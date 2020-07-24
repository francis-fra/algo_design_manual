#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdbool.h>
#ifndef GRAPH_H
#define GRAPH_H
#include "graph.h"
#endif
#ifndef QUEUE_H
#define QUEUE_H
#include "queue.h"
#endif
#ifndef STACK_H
#define STACK_H
#include "stack.h"
#endif

// read and dump till end of line
void dump_line(FILE *fp) {
    char c;
    while ((c != '\n') && (c != EOF)) {
        c = fgetc(fp);
    }
    // put back char beyond the newline or EOF
    ungetc(c, fp);
}


void read_graph(Graph *g, char *filename, bool directed) {

    FILE *fp = fopen(filename, "r");
    /* printf("Opening %s\n", filename); */
    int V;
    int u, v;
    int flag = -1;
    char c;

    if (fp != NULL) {

       // FIXME: read num vertices (necessary??)
       // loop until num vertices is read
       while (flag <= 0) {
           c = fgetc(fp);
           // get rid of comments
           if (c == '#') {
             dump_line(fp);
           }
           // read data
           /* flag = fscanf(fp, "%d %d", &E, &V); */
           flag = fscanf(fp, "%d", &V);
           if (flag > 0) {
               // DEBUG
               //printf("V = %d\n", V);
               g->numVertex = V;
           } else {
               continue;
           }
       }

       // loop to read all edge links
       while (c != EOF) {
          c = fgetc(fp);

          // get rid of comments
          if (c == '#') {
            dump_line(fp);
            continue;
          }
          // read data
          int flag = fscanf(fp, "%d %d", &u, &v);
          if (flag > 0) {
              insert_edge(g, u, v, 1, directed);  // unit weight
              // DEBUG
              /* printf("flag = %d, Edge = %d, %d\n", flag, u, v); */
          }

       }
    }

    fclose(fp);

}

void insert_edge(Graph *g, int from, int to, int weight, bool directed) {

    // create connected vertex
    Edge *v = malloc(sizeof(Edge));
    /*
    Vertex *root = malloc(sizeof(Vertex));
    root->neighbors = malloc(sizeof(Vertex));
    Vertex *v = root->neighbors;
    */

    // edge data
    v->id = from;
    v->adj = to;
    v->weight = weight;

    // append linkd list
    // save the original edge to the new node
    v->neighbors = g->edges[from];
    // then add the new edge to the front of the linked list in the graph
    g->edges[from] = v;
    g->degrees[from]++;

    if (directed == false) {
        insert_edge(g, to, from, weight, true);  // add as directed
    } else {
        // to make sure num edge is counted once
        g->numEdge++;  // add count for directed link only
    }

}

void show_graph(Graph *g) {

    Edge *p, *q;
    printf("Num Vertices = %d\n", g->numVertex);
    printf("Num Edges = %d\n", g->numEdge);
    if (g->directed == 1)
      printf("Directed: True\n");
    else
      printf("Directed: False\n");

    for (int k=0; k < g->numVertex; k++) {
        // get a vertex
        p = g->edges[k];
        // show degree
        printf(" (%d) ", g->degrees[k]);
        if (p == NULL) {
            continue;
        } else {
            printf("%d : ", p->id);
            printf("%d ", p->adj);
            // loop to print all its neighbours
            q = p->neighbors;
            while (q != NULL) {
                printf("%d ", q->adj);
                q = q->neighbors;
            }
        }
        printf("\n");
    }

}


void initialize_graph(Graph *graph, bool directed) {
    graph->directed = directed;
    graph->numVertex = 0;
    graph->numEdge = 0;

    for (int k=0; k<MAX_VERTEX; k++) {
        graph->edges[k] = NULL;
    }
    for (int k=0; k<MAX_VERTEX; k++) {
        graph->degrees[k] = 0;
    }
    for (int k=0; k<MAX_VERTEX; k++) {
        graph->value[k] = 0;
    }
};

// reset all data
void init_search(Graph *g) {
    for (int k=0; k<g->numVertex; k++) {
        g->discovered[k] = false;
        g->processed[k] = false;
        g->parent[k] = -1;
        g->value[k] = 0;
    }
}


void bfs(Graph *g, int start, void (*f) (Graph*, Edge*)) {

    /*
    va_list ap;
    va_start(ap, g);
    int try = va_arg(ap, int);
    */
    Edge *V;
    Edge *nb;
    int nb_id, vtx_id;

    VertexQueue *q = createVQueue();
    enqueue(q, g->edges[start]);
    g->discovered[start] = true;

    // visit vertex in the queue
    while (isEmptyQueue(q) == false) {
        // take a vertex
        V = dequeue(q);
        // id of this vertex
        vtx_id = V->id;
        // discovered
        process_vertex_early(V);
        g->processed[vtx_id] = true;
        // Start processing at this edge
        nb = V;
        // BFS: loop to process all its neighbours
        while (nb != NULL) {
            // edge destination vertex id
            nb_id = nb->adj;
            // process the edge (unless the terminated vertex has been processed)
            if ((g->processed[nb_id] == false) || g->directed) {
                f(g,V);
                // f(vtx_id, nb_id);   // edge processor
            }
            // now the neighbor has been discovered
            if (g->discovered[nb_id] == false) {
                g->discovered[nb_id] = true;
                g->parent[nb_id] = vtx_id;
                // enqueue vertex of nb_id
                enqueue(q, g->edges[nb_id]);
            }
            // bfs: next edge
            nb = nb->neighbors;
        }
        process_vertex_late(V);
    }

}

void process_edgeNode(Graph* g, Edge* E) {
    int u = E->id;
    int v = E->adj;
    printf("Edge : %d -> %d\n", u, v);
}

void process_edge(int u, int v) {
    printf("Edge : %d -> %d\n", u, v);
}

void process_vertex_early(Edge *V) {
    printf("Processing Vertex %d\n", V->id);
}

void process_vertex_late(Edge *V) {
    printf("Vertex %d processed\n", V->id);
}


// print traversed path
void find_path(Graph *g, int start, int end) {

    stack *path = create_stack(g->numVertex);
    // find  path from the destination
    int current = end;
    // start must be the root
    while (start != current) {
        push(path, current);
        current = g->parent[current];
    }
    push(path, start);

    // TODO: print stack
    traverse_stack(path, &print_item);

}

// return if a graph is bipartite
bool two_color(Graph *g) {

    // start vertex
    Edge *V = g->edges[0];
    int start = V->id;

    init_search(g);
    bfs(g, start, &check_color);
    show_vertex_value(g);

    return true;

}

// FIXME: need to check all its neighors as well
void check_color(Graph* g, Edge* E) {
    int u = E->id;
    int v = E->adj;
    // both uninitialized
    if (g->value[u] == 0 && g->value[v] == 0) {
      g->value[u] = 1;
      g->value[v] = -1;
      printf("Coloring %d as %d and %d as %d\n", u, 1, v, -1);
    }
    else if (g->value[u] == 0) {
      g->value[u] = -g->value[v];
      printf("Coloring %d as %d\n", u, g->value[u]);
    }
    else if (g->value[v] == 0) {
      g->value[v] = -g->value[u];
      printf("Coloring %d as %d\n", v, g->value[v]);
    }
    else {
      // both were colored
      if (g->value[u] == g->value[v]) {
        printf("CONFLICT: Color of %d = %d, Color of %d = %d\n", u, g->value[u], v, g->value[v]);
      }
    }

}

void show_vertex_value(Graph* g) {

    for(int k=0; k<g->numVertex; k++) {
        printf("Vertex: %d = %d\n", k, g->value[k]);
    }

}

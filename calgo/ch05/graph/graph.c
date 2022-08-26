#include <stdlib.h>
#include <graph.h>
#include <queue.h>
#include <string.h>
#include <misc.h>

Graph* 
initialize_graph(int nvertices, int nedges, bool directed) {
    Graph *g = malloc(sizeof(Graph));

    g->directed = directed;
    g->numVertex = nvertices;
    if (directed == false) {
        g->numEdge = 2*nedges;
    } else {
        g->numEdge = nedges;
    }

    return g;
}

Edge* 
make_undirected_edge(int id, int weight) {
    Edge *ptr = malloc(sizeof(Edge));
    ptr->id = id;
    ptr->weight = weight;
    return ptr;
}

void
insert_undirected_edge(Graph *g, int from, int to, int weight) {

    // out degress
    g->degrees[from]++;
    Edge *new_edge = make_undirected_edge(to, weight);
    // add to graph
    Edge *ptr= g->edges[from];
    if (ptr == NULL) {
        g->edges[from] = new_edge;
    } else {
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = new_edge;
    }
}

void
print_edge_link(Edge* ptr) {
    while (ptr != NULL) {
        printf("%d[%d] ", ptr->id, ptr->weight);
        ptr = ptr->next;
    }
    printf("\n");
}

void 
show_adjacent_edges(Graph *g, int id) {

    Edge *ptr= g->edges[id];
    print_edge_link(ptr);
}

void
print_graph(Graph *g) {
    printf("num vectices: %d, num edges: %d\n", g->numVertex, g->numEdge);
    printf("\n");
    printf("Adjacency:\n");
    for (int k=0; k<g->numVertex; k++) {
        printf("vertex %d: ", k);
        show_adjacent_edges(g, k);
    }
    printf("\n");
    printf("Out degrees:\n");
    for (int k=0; k<g->numVertex; k++) {
        printf("vertex %d: %d\n", k, g->degrees[k]);
    }
}

GData*
intitialize_search(Graph *g) {
    GData *searchData = malloc(sizeof(GData));
    for (int k=0; k<g->numVertex; k++) {
        searchData->discovered[k] = false;
        searchData->processed[k] = false;
        searchData->parent[k] = -1;
        searchData->entry_time[k] = -1;
        searchData->exit_time[k] = -1;
        searchData->data[k] = -1;
    }
    return searchData;
}

GData*
bfs(Graph *g, int v, 
    void(*process_edge)(int, int, GData*),
    void(*pre_process_vertex)(int, GData*),
    void(*post_process_vertex)(int, GData*)) 
{
    // initialize data for search
    GData *ctrl = intitialize_search(g);
    queue q = create_queue();
    pre_process_vertex(v, ctrl);
    ctrl->discovered[v] = true;
    // put it in queue
    insert_queue_item(q, v);
    // loop the queue
    node *n;
    Edge *ptr;
    int id, neighbor;
    // proces the first in queue
    while (n = take_queue_node(q)) {
        id = n->item;
        // find all connected vertices
        ptr = g->edges[id];
        while (ptr != NULL) {
            neighbor = ptr->id;
            // make them all discovered if not 
            if (ctrl->discovered[neighbor] == false) {
                pre_process_vertex(neighbor, ctrl);
                insert_queue_item(q, neighbor);
                ctrl->parent[neighbor] = id;
                ctrl->discovered[neighbor] = true;
            }
            ptr = ptr->next;
        }
        post_process_vertex(id, ctrl);
        process_edge(ctrl->parent[id], id, ctrl);
        ctrl->processed[id] = true;
    }
    // TODO: free queue
    // print_array(ctrl->parent, g->numVertex);
    return ctrl;
}

// ------------------------------------------------------------
// customize these for different functions
void dummy_vertex(int v, GData* gdata) { }

void 
print_vertex(int v, GData* gdata) {
    printf("Visiting %d\n", v);
}

void 
print_edge(int u, int v, GData* gdata) {
    printf("Visiting %d->%d\n", u, v);
}

void 
dummy_edge(int u, int v, GData* gdata) { }


// ------------------------------------------------------------
GData*
dfs(Graph *g, int v, 
    void(*process_edge)(int, int, GData*),
    void(*pre_process_vertex)(int, GData*),
    void(*post_process_vertex)(int, GData*)) 
{
    // initialize data for search
    GData *ctrl = intitialize_search(g);
    stack s = create_stack();
    int time = 1;

    pre_process_vertex(v, ctrl);
    ctrl->discovered[v] = true;
    ctrl->entry_time[v] = time;
    // put it in queue
    insert_stack_item(s, v);
    node *n;
    Edge *ptr;
    int id, neighbor;
    // loop the queue
    while (n = take_stack_node(s)) {
        id = n->item;
        // find all connected vertices
        ptr = g->edges[id];
        while (ptr != NULL) {
            neighbor = ptr->id;
            // make them all discovered if not 
            if (ctrl->discovered[neighbor] == false) {
                insert_stack_item(s, neighbor);
                pre_process_vertex(neighbor, ctrl);
                // insert parent vertex to find the edge
                ctrl->parent[neighbor] = id;
                ctrl->discovered[neighbor] = true;
                time = time + 1;
                ctrl->entry_time[neighbor] = time;
            }
            ptr = ptr->next;
        }
        post_process_vertex(id, ctrl);
        process_edge(ctrl->parent[id], id, ctrl);
        ctrl->processed[id] = true;
        time = time + 1;
        ctrl->exit_time[v] = time;
    }
    // print_array(ctrl->parent, g->numVertex);
    return ctrl;
}

// read from stdin
Graph*
read_graph(bool directed, bool weighted) {

    int nvertices;
    int nedges;
    int from, to;
    int weight;

    // read num vertices and edges 
    scanf("%d %d", &nvertices, &nedges);
    // initialize graph
    Graph *g = initialize_graph(nvertices, nedges, directed);

    if (weighted) {
        // read edge pairs
        for (int k=0; k<nedges; k++) {
            scanf("%d %d %d", &from, &to, &weight);
            printf("%d %d %d\n", from, to, weight);
            insert_undirected_edge(g, from, to, weight);
            if (!directed) {
                insert_undirected_edge(g, to, from, weight);
            }
        }

    } else {
        // read edge pairs
        for (int k=0; k<nedges; k++) {
            scanf("%d %d", &from, &to);
            printf("%d %d\n", from, to);
            insert_undirected_edge(g, from, to, 1);
            if (!directed) {
                insert_undirected_edge(g, to, from, 1);
            }
        }
    }
    return g;
}

Graph*
fread_graph(char* filename, bool directed, bool weighted) {

    FILE* fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Cannot open file %s", filename);
        exit(EXIT_FAILURE);
    }
    int nvertices;
    int nedges;
    int from, to;
    int weight;

    // read num vertices and edges 
    fscanf(fp, "%d %d", &nvertices, &nedges);
    // initialize graph
    Graph *g = initialize_graph(nvertices, nedges, directed);

    if (weighted) {
        // read edge pairs
        for (int k=0; k<nedges; k++) {
            fscanf(fp, "%d %d %d", &from, &to, &weight);
            // printf("%d %d %d\n", from, to, weight);
            insert_undirected_edge(g, from, to, weight);
            if (!directed) {
                insert_undirected_edge(g, to, from, weight);
            }
        }

    } else {
        // read edge pairs
        for (int k=0; k<nedges; k++) {
            fscanf(fp, "%d %d", &from, &to);
            // printf("%d %d\n", from, to);
            insert_undirected_edge(g, from, to, 1);
            if (!directed) {
                insert_undirected_edge(g, to, from, 1);
            }
        }
    }
    fclose(fp);
    return g;
}
// ------------------------------------------------------------
// graph functions
// ------------------------------------------------------------
bool
find_path(Graph *g, int from, int to, char *method) {
    GData *gdata;
    if (strcmp(method,"bfs") == 0) {
        gdata = bfs(g, from, &print_edge, &dummy_vertex, &dummy_vertex);
    } else {
        gdata = dfs(g, from, &print_edge, &dummy_vertex, &dummy_vertex);
        // gdata = dfs(g, from);
    }
    int parent = gdata->parent[to];
    printf("%d -> ", to);
    while (parent != -1 && parent != from) {
        printf("%d -> ", parent);
        parent = gdata->parent[parent];
    }
    printf("%d -> ", parent);
    if (parent == from)
        return true;
    else
        return false;
}

// TODO
void
topsort(Graph *g) {

}

// ------------------------------------------------------------
// customize these for different functions

void 
color_edge(int u, int v, GData* gdata) {
    // swtich color
    gdata->data[v] = (gdata->data[u] + 1) % 2;
    printf("visiting %d->%d\n", u, v);
}

// 
void color_vertex(int v, GData* gdata) {
    if (gdata->discovered[v] == false) {
        gdata->data[v] = 0;
    }
}

void count_vertex(int v, GData* gdata) {
    gdata->data[v] = 1;
}




// ------------------------------------------------------------

void
twocolor(Graph *g) {
    // record color in data array
    GData *gdata;
    gdata = bfs(g, 1, &color_edge, &color_vertex, &dummy_vertex);
    print_array(gdata->data, g->numVertex);

}

void 
articulate(Graph *g) {
    Graph origin;
    // from g to origin
    memcpy(&origin, g, sizeof(Graph));

    GData *gdata;
    Graph *gv;
    bool found;
    int start;
    int count;
    for (int k=0; k<g->numVertex; k++) {
        gv = delete_edge(g, k);
        start = (k+1) % g->numVertex;
        gdata = dfs(gv, start, &dummy_edge, &dummy_vertex, &count_vertex);
        // check
        count = 0;
        for (int v=0; v<g->numVertex; v++) {
            if (gdata->data[v] == 1) count++;
        }
        printf("%d: count: ", k);
        // FIXME: still a shallow copy...
        memcpy(g, &origin, sizeof(Graph));
        // print_graph(g);
        // print_graph(&origin);

    }
}

Edge *
remove_edge_link(Edge *lst, int item) {
    Edge *head = lst;

    // remove leading matched nodes
    Edge *ptr = head;
    while (ptr != NULL && ptr->id == item) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        return NULL;
    }
    // now head points to a node whose item is not matched
    head = ptr;
    Edge *parent = head;
    Edge *child = parent->next;
    while (child != NULL) {
        if (child->id == item) {
            // unlink parent no change
            parent->next = child->next;
        } else {
            // move parent
            parent = child;
        }
        child = parent->next;
    }
    return head;
}

bool 
isEdge(Graph *g, int v, int u) {
    Edge *p = g->edges[v];
    while (p != NULL) {
        if (p->id == u) return true;
        p = p->next;
    }
    return false;
}

Graph *
delete_edge(Graph *g, int v) {
    for(int k=0; k<g->numVertex; k++) {
        if (k == v) {
            // delete all
            g->edges[k] = NULL;
            g->degrees[k] = 0;
        } else {
            // assume single path
            if (isEdge(g, k, v))
                g->degrees[k] = g->degrees[k] - 1;
            g->edges[k] = remove_edge_link(g->edges[k], v);
        }
    }
    return g;
}
#include <weighted_graph.h>
#include <stdlib.h>
#include <limits.h>
#include <assert.h>
#include <misc.h>

void prim(Graph *g, int start) {

    // keep an array of distance from outside
    int distance[MAX_VERTEX];
    // keep an array of intree nodes 
    bool intree[MAX_VERTEX];
    // keep an array of parents
    int parent[MAX_VERTEX];

    // initialize
    for (int k=0; k<g->numVertex; k++) {
        distance[k] = INT_MAX;
        intree[k] = false;
        parent[k] = -1;
    }

    distance[start] = 0;
    int v = start;
    Edge *p;

    while (intree[v] == false) {
        printf("%d -> %d\n", parent[v], v);
        intree[v] = true;
        // update distances of all connected edge
        p = g->edges[v];
        while (p != NULL) {
            int id = p->id;
            if (intree[id] == false) {
                // update distance
                if (distance[id] > p->weight) {
                    distance[id] = p->weight;
                    parent[id] = v;
                }
            }
            p = p->next;
        }
        // choose the best vertex
        int min_dist = INT_MAX;
        // int min_vertex = -1;
        v = start;
        for (int k=0; k<g->numVertex; k++) {
            if (intree[k] == false && distance[k] < min_dist) {
                min_dist = distance[k];
                v = k;
            } 
        }
    }
    printf("\n");
    // print_array(parent, g->numVertex);
    // print_array(distance, g->numVertex);

}

void kruskal(Graph *g, int start) {

    Set_union s; 
    Edge_pair e[MAX_EDGES];

    // initialize set union structure
    init_union(g, &s);
    // initialize edge data into an array
    to_edge_array(g, e);

    // sort by weight
    qsort(&e, g->numEdge, sizeof(Edge_pair), &edge_pair_cmp);

    for (int k=0; k<g->numEdge; k++) {
        Edge_pair edge = e[k];
        if (same_component(&s, edge.x, edge.y)) continue;
        printf("%d -> %d\n", edge.x, edge.y);
        union_sets(&s, edge.x, edge.y);
        // break if all included
    }

}

// ascending order
int
edge_pair_cmp(const Edge_pair *x, const Edge_pair *y) {
	if (x->weight < y->weight) return(-1);
	if (x->weight > y->weight) return(1);
	return(0);
}

// typedef struct {
//     int parent[MAX_VERTEX];
//     int size[MAX_VERTEX];
//     int num_vertex;
// } Set_union;

void
init_union(Graph *g, Set_union* s) {
    s->num_vertex = g->numVertex;
    for (int k=0; k<s->num_vertex; k++) {
        s->parent[k] = k;
        s->size[k] = 1;
    }
}
int
find(Set_union*s, int v) {
    // find parent of v
    int *p = s->parent; 
    int v_parent = p[v];
    while (v_parent != p[v_parent]) {
        v_parent = p[v_parent];
    }
    return v_parent;
}

void
union_sets(Set_union* s, int u, int v) {
    int u_parent = find(s, u);
    int v_parent = find(s, v);

    if (u_parent == v_parent) return;

    // update their parents
    int *p = s->parent;
    // find which join to which
    if (s->size[u_parent] > s->size[v_parent]) {
        // v join to u
        s->size[u_parent] = s->size[u_parent] + s->size[v_parent];
        p[v_parent] = u_parent;
    } else {
        s->size[v_parent] = s->size[u_parent] + s->size[v_parent];
        p[u_parent] = v_parent;
    }
}

bool
same_component(Set_union* s, int u, int v) {
    return find(s, u) == find(s, v);
}

void
to_edge_array(Graph *g, Edge_pair e[])
{
	int m = 0;
	Edge *p;

	for (int i=0; i<g->numVertex; i++) {
        // linked list of edges
		p = g->edges[i];
        // loop for this vertex
		while (p != NULL) {
            e[m].x = i;
            e[m].y = p->id;
            e[m].weight = p->weight;
            m = m+1;
            // next edge node
			p = p->next;
		}
	}
}

// shortest path
void
shortest_path(Graph* g, int s, int v) {
    int dist[MAX_VERTEX];
    int processed[MAX_VERTEX];
    int parent[MAX_VERTEX];
    for (int k=0; k<g->numVertex; k++) {
        dist[k] = INT_MAX;
        processed[k] = false;
        parent[k] = -1;
    }
    dist[s] = 0;
    processed[s] = true;
    int best_parent = s;
    int best = s;
    int distance;
    int min_dist;
    int from, to;
    Edge *ptr;
    printf("%d -> %d (%d)\n", best_parent, best, 0);
    while(best != v) {
        // select next vertex closest to last
        min_dist = INT_MAX;
        for(int k=0; k<g->numVertex; k++) {
            // find an edge extending from existing path 
            if (processed[k] == true) {
                // loop all edges to k
                ptr = g->edges[k];
                from = k;
                while(ptr != NULL) {
                    // node being tested
                    to = ptr->id;
                    // find the distnace from k to s
                    if (processed[to] == false) {
                        distance = dist[from] + ptr->weight;
                        if (distance < min_dist) {
                            min_dist = distance;
                            best = to;
                            best_parent = from;
                        }
                    }
                    ptr = ptr->next;
                }
            }
        }
        processed[best] = true;
        dist[best] = min_dist;
        parent[best] = best_parent;
        printf("%d -> %d (%d)\n", best_parent, best, min_dist);
    }
    printf("\n");
    print_path_from_parent_array(parent, s, v);
}

void 
print_path_from_parent_array(int parent[], int u, int v) {
    for (int k=v; k!=u; k=parent[k]) {
        printf("%d <- ", k);
        if (k < 0) {
            // -1 means no parent
            printf("No such path\n");
            return ;
        }
    }
    printf("%d \n", u);
}
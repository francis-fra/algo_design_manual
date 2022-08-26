#include <graph.h>

typedef struct {
    int parent[MAX_VERTEX];
    int size[MAX_VERTEX];
    int num_vertex;
} Set_union;

typedef struct {
        int x, y;                       /* adjacency info */
        int weight;                     /* edge weight, if any */
} Edge_pair;

void prim(Graph *g, int start);
void kruskal(Graph *g, int start);

void init_union(Graph* g, Set_union* s);
int find(Set_union* s, int v);
void union_sets(Set_union* s, int u, int v);
void to_edge_array(Graph *g, Edge_pair e[]);
int edge_pair_cmp(const Edge_pair *x, const Edge_pair *y);
bool same_component(Set_union* s, int u, int v);
void shortest_path(Graph* g, int s, int v);

void print_path_from_parent_array(int parent[], int u, int v);
#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTEX 100
/* typedef int itemType; */

typedef struct S {
    int to;
    int from;
} nodeType;

// represent an edge is an adjacent list
typedef struct node {
    int weight;     // weight of the edge
    nodeType data;  // optional data
    int id;         // initiate (this) vertex
    int adj;        // terminating vertex
    struct node *neighbors;   // pointer to neighboring edge with the same vertex id
} Edge;

typedef struct G {
    Edge *edges[MAX_VERTEX];      // linked list of Vertices
    int degrees[MAX_VERTEX];        // number of out degree of each vertex
    bool discovered[MAX_VERTEX];
    bool processed[MAX_VERTEX];
    int parent[MAX_VERTEX];
    // graph properties
    bool directed;
    int numVertex;
    int numEdge;
    // Vertex data
    int value[MAX_VERTEX];
} Graph;

void initialize_graph(Graph *graph, bool directed);
void dump_line(FILE *fp);
// read graph vertex id represented by integer
void read_graph(Graph *graph, char *filename, bool directed);
void insert_edge(Graph *graph, int from, int to, int weight, bool directed);
void show_graph(Graph *graph);

// void bfs(Graph *graph, int start, void (*f) (int, int));
void bfs(Graph *graph, int start, void (*f) (Graph*, Edge*));
void init_search(Graph *graph);
// processing for the first visit
void process_vertex_early(Edge *V);
// process edge before switching to the next
void process_vertex_late(Edge *V);
void process_edgeNode(Graph*, Edge *E);
void process_edge(int u, int v);

void find_path(Graph *graph, int start, int end);
bool two_color(Graph *graph);
void check_color(Graph*, Edge *E);
void show_vertex_value(Graph*);

#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTEX 100
#define MAX_EDGES 100

// linked list
typedef struct Edge {
    int id;         // vertex id
    int weight;     // weight of this edge to the head (vertex) of this list
    struct Edge *next;   // pointer to neighboring edge with the same vertex id
} Edge;


typedef struct {
    Edge *edges[MAX_VERTEX];        // adjacency linked list for each vertex
    int degrees[MAX_VERTEX];        // number of out degree of each vertex

    // graph properties
    bool directed;
    int numVertex;
    int numEdge;

} Graph;

// graph vertex is integer (index)
typedef struct {
    bool discovered[MAX_VERTEX];
    bool processed[MAX_VERTEX];
    int parent[MAX_VERTEX];
    int entry_time[MAX_VERTEX];
    int exit_time[MAX_VERTEX];
    int data[MAX_VERTEX];
} GData;


Graph* initialize_graph(int nvertices, int nedges, bool directed);
void insert_undirected_edge(Graph *g, int from, int to, int weight);
Edge* make_undirected_edge(int id, int weight);

void show_adjacent_edges(Graph *g, int id);
void print_graph(Graph *g);

GData* intitialize_search(Graph *g);

void dummy_vertex(int v, GData *gdata);
void dummy_edge(int u, int v, GData *gdata);
void print_vertex(int v, GData *gdata);
void count_vertex(int v, GData *gdata);
void print_edge(int u, int v, GData *gdata);

GData* bfs(Graph *g, int v, 
    void(*process_edge)(int, int, GData*),
    void(*pre_process_vertex)(int, GData*),
    void(*post_process_vertex)(int, GData*));
GData* dfs(Graph *g, int v, 
    void(*process_edge)(int, int, GData*),
    void(*pre_process_vertex)(int, GData*),
    void(*post_process_vertex)(int, GData*));
// GData* bfs(Graph *g, int v);
// GData* dfs(Graph *g, int v);

bool find_path(Graph *g, int from, int to, char *method);
void topsort(Graph *g);
void twocolor(Graph *g);
void articulate(Graph *g);

Graph *read_graph(bool directed, bool weighted);
Graph *fread_graph(char *filename, bool directed, bool weighted);

bool isEdge(Graph *g, int v, int u);
Graph *delete_edge(Graph *g, int v);
Edge* remove_edge_link(Edge *lst, int item);
void print_edge_link(Edge *ptr);

#endif
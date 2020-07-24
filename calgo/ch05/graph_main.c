#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

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


int main(int argc, char **argv) {

    // read graph info from file

    char *filename = argv[1];
    Graph graph;
    // read graph from file
    bool directed = false;
    initialize_graph(&graph, directed);
    read_graph(&graph, filename, directed);

    // testing bfs
    show_graph(&graph);
    init_search(&graph);
    int start = 3;
    // bfs(&graph, start, &process_edgeNode);

    // make an emtpy graph
    /* initialize_graph(&graph, directed); */

    // find path
    // printf("Path>>>\n");
    // find_path(&graph, start, 6);

    printf("Two color problem:\n");
    two_color(&graph);


    return 0;
}


    // testing queue
    /*
    VertexQueue *q = createVQueue();
    enqueue(q, graph.edges[0]);
    enqueue(q, graph.edges[1]);
    enqueue(q, graph.edges[2]);

    // dequeue
    Vertex *V = dequeue(q);
    V = dequeue(q);
    printf("Getting Vertex: %d\n", V->id);
    printf("isEmpty? %d\n", isEmptyQueue(q));
    V = dequeue(q);
    printf("isEmpty? %d\n", isEmptyQueue(q));

    free(q);
    */

    /*
    stack *s = create_stack(4);
    push(s, 5);
    push(s, 7);
    push(s, 9);
    printf("item = %d\n", peek(s));
    pop(s);
    printf("item = %d\n", peek(s));
    */

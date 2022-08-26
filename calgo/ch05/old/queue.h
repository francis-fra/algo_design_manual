#include <stdbool.h>
#ifndef GRAPH_H
#define GRAPH_H
#include "graph.h"
#endif

// Note: root has no data
typedef struct Q {
    Edge *data;
    struct Q* next;
} VertexQueue;

void enqueue(VertexQueue *q, Edge *V);
Edge* dequeue(VertexQueue *q);
VertexQueue *createVQueue();
bool isEmptyQueue(VertexQueue *q);

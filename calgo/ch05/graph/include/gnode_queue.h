#ifndef __GNODE_QUEUE_H__
#define __GNODE_QUEUE_H__

#include <stdbool.h>
#include <graph.h>

typedef struct Q {
    Edge *data;
    struct Q* next;
} VertexQueue;

void enqueue(VertexQueue *q, Edge *V);
Edge* dequeue(VertexQueue *q);
VertexQueue *createVQueue();
bool isEmptyQueue(VertexQueue *q);

#endif
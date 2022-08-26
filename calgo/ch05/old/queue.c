#include <stdlib.h>
#ifndef QUEUE_H
#define QUEUE_H
#include "queue.h"
#endif

#ifndef GRAPH_H
#define GRAPH_H
#include "graph.h"
#endif

// FIFO - insert to the end
void enqueue(VertexQueue *q, Edge *V) {

    while (q->next != NULL) {
        // insert at the end
        q = q->next;
    }
    // create new node

    VertexQueue *newVertex = createVQueue();
    newVertex->data = V;

    // save current to new
    // insert at the end
    q->next = newVertex;

};

// dequeue from the front
Edge* dequeue(VertexQueue *q) {

    VertexQueue *current;
    VertexQueue *root = q;
    // check if the queue is empty of not
    // note that the root has no data
    if (root->next == NULL) {
        return NULL;
    } else {
        // move to the first data node
        current = root->next;
        // remove the link
        root->next = current->next;
        return current->data;
    }
};
/*
void initVQueue(VertexQueue *q) {
    q = malloc(sizeof(VertexQueue));
    q->data = NULL;
    q->next = NULL;
}
*/

VertexQueue *createVQueue() {
    VertexQueue *q = malloc(sizeof(VertexQueue));
    q->data = NULL;
    q->next = NULL;
    return q;
}

bool isEmptyQueue(VertexQueue *q) {
    return (q->next == NULL);
}

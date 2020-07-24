#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "heap.h"

// first index starts with 0
int pq_parent(int n) {
    return ((n-1)/2);
};

int pq_young_child(int n) {
    return (2*n+1);

};

void pq_init(priority_queue *q, enum heapType type) {
    q->size = 0;
    q->type = type;
}

void pq_insert(priority_queue *q, itemType item) {
    int size = q->size;
    if (size < PQ_SIZE) {
       (q->buffer)[size] = item;
       if (q->type == max_heap)
           bubble_up(q, size);
           /* bubble(q, size, &less_than); */
       else
           bubble_down(q, size);
           /* bubble(q, size, &greater_than); */

       (q->size)++;
    }
}

/*
    comparison functions 
*/
int greater_than(itemType a, itemType b) {
    return (a > b);
};

int less_than(itemType a, itemType b) {
    return (a < b);
}

void swap(itemType arr[], int a, int b) {
    itemType tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

/*
    bubble_root: perform bubbling from the root (called bubble down in book)
    bubble: perform bubbling with different directions
    bubble_up: bubbling for max heap
    bubble_down: bubbling for min heap
*/
void bubble_root(priority_queue *q, int p, int (*f) (itemType, itemType)) {

    int young_child = pq_young_child(p);
    int other_child = young_child + 1;

    // Repeatative??

    // check young child 
    if (young_child < q->size) {
        if (f(q->buffer[p], q->buffer[young_child])) {
            swap(q->buffer, p, young_child);
            bubble_root(q, young_child, f);
        }
    }

    // check other child 
    if (other_child < q->size) {
        if (f(q->buffer[p], q->buffer[other_child])) {
            swap(q->buffer, p, other_child);
            bubble_root(q, other_child, f);
        }
    }

}

void bubble(priority_queue *q, int p, int (*f) (itemType, itemType)) {

   int parent = pq_parent(p);
   if ( f(q->buffer[parent], q->buffer[p]) ) {
        swap(q->buffer, parent, p);        
        bubble(q, parent, f);
   }
}

void bubble_up(priority_queue *q, int p) {

    bubble(q, p, &less_than);
}

void bubble_down(priority_queue *q, int p) {

    bubble(q, p, &greater_than);
}

// traverse and print from the root
void pq_show(priority_queue *q) {
    for (int idx=0; idx < q->size; idx++) {
        printf("%d\n", (q->buffer)[idx]);
    }
}

// fill existing priority queue from array
void make_heap(priority_queue *q, itemType a[], int n) {
    for (int k=0; k<n; k++)
        pq_insert(q, a[k]);
}

/*
    Search functions
*/
itemType find_max(priority_queue *q) {
    int depth = (int) (0.5 + log2(q->size));
    int max;
    // parent is the largest
    if (q->type == min_heap) {
        int start_idx = exp2(depth-1) - 1;
        max = q->buffer[start_idx];
        for (int k=start_idx+1; k < q->size; k++) {
            if (q->buffer[k] > max) {
                max = q->buffer[k];
            }
        }
        return max;

    } else {
        return q->buffer[0];    
    }
}

itemType find_min(priority_queue *q) {
    int depth = (int) (0.5 + log2(q->size));
    int min;
    /* int depth = (int) (0.5 + log(q->size) / log(2)); */
    // parent is the largest
    if (q->type == max_heap) {
        int start_idx = exp2(depth-1) - 1;
        min = q->buffer[start_idx];
        for (int k=start_idx+1; k < q->size; k++) {
            if (q->buffer[k] < min) {
                min = q->buffer[k];
            }
        }
        return min;

    } else {
        return q->buffer[0];    
    }
}


itemType extract_root(priority_queue *q) {

    if (q->size == 0) {
       printf("Error - empty queue!\n"); 
       return -1;
    }

    int root = q->buffer[0];
    // extract it and restore the heap 
    if (q->size > 1) {
        q->buffer[0] = q->buffer[q->size-1];
    }
    (q->size)--;

    // restore the heap
    if (q->type == max_heap) {
        bubble_root(q, 0, &less_than);
    } else {
        bubble_root(q, 0, &greater_than);
    }

    return (root);

}

// sort array using priority queue
void heap_sort(itemType s[], int n, int direction) {

    priority_queue q;
    
    if (direction > 0) 
        pq_init(&q, min_heap); // ascending
    else
        pq_init(&q, max_heap); // descending

    make_heap(&q, s, n);

    for (int k=0; k<n; k++)
        s[k] = extract_root(&q);

}


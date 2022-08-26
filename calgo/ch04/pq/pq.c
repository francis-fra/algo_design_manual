#include <stdio.h>
#include <stdlib.h>
#include <pq.h>

PQ*
pq_init() {
    PQ *pq = malloc(sizeof(PQ));
    pq->size = 0;
}

int 
pq_parent(int n) {
    return (n-1)/2;
}

int 
pq_left_child(int n) {
    return 2*n+1;
}

int 
pq_right_child(int n) {
    return (n+1)*2;
}

void 
swap(int arr[], int a, int b) {
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

void
pq_insert(PQ *pq, int item) {
    if (pq->size >= MAX_PQ_SIZE) {
        fprintf(stderr, "PQ capacity full\n");
        return;
    }
    pq->queue[pq->size] = item;
    bubble_up(pq, pq->size);
    pq->size++;
}

void 
print_pq(PQ* pq) {
    for (int k=0; k<pq->size; k++) {
        printf("%d ", pq->queue[k]);
    }
    printf("\n");
}

void 
bubble_up(PQ *pq, int idx) {
    // continue until root is reached
    if (idx > 0) {
        // find parent
        int pidx = pq_parent(idx);
        // compare 
        if (pq->queue[pidx] > pq->queue[idx]) {
            swap(pq->queue, pidx, idx);
        }
        // recursive
        bubble_up(pq, pidx);
    }
}
void 
bubble_down(PQ *pq, int idx) {

    if (idx >= pq->size) {
        return;
    }
    // find children indices
    int lidx = pq_left_child(idx);
    int ridx = pq_right_child(idx);

    // check if parent is smaller than its children
    int smallest = pq->queue[idx];
    int smallest_idx = idx;

    // int left_child = pq->queue[lidx];
    // int right_child = pq->queue[ridx];
    if ((lidx < pq->size) && (pq->queue[lidx] < smallest)){
        smallest_idx = lidx;
        smallest = pq->queue[lidx];
    }
    if ((ridx < pq->size) && (pq->queue[ridx] < smallest)){
        smallest_idx = ridx;
        // smallest = pq->queue[ridx];
    }

    if (smallest_idx != idx) {
        swap(pq->queue, idx, smallest_idx);
        // recursive
        bubble_down(pq, smallest_idx);
    }
}

int
pq_extract(PQ* pq) {
    if (pq->size == 0) {
        fprintf(stderr, "PQ is empty\n");
    }
    int item = pq->queue[0];
    // move last to root
    pq->queue[0] = pq->queue[pq->size-1];
    pq->size--;
    bubble_down(pq, 0);

    return item;
}

PQ*
make_heap(int arr[], int size) {

    PQ *pq = pq_init();
    for (int k=0; k<size; k++) {
        pq_insert(pq, arr[k]);
    }
    return pq;
}

PQ*
fast_make_heap(int arr[], int size) {

    PQ *pq = pq_init();
    for (int k=0; (k<size) & (k<MAX_PQ_SIZE); k++) {
        pq->queue[k] = arr[k];
        pq->size++;
    }
    // print_array(pq->queue, size);
    for (int k=pq->size; k>=0; k--) {
        bubble_down(pq, k);
    }
    return pq;
}

void
heap_sort(int arr[], int n) {

    PQ* pq = make_heap(arr, n);
    for (int k=0; pq->size>0; k++) {
        arr[k] = pq_extract(pq);
    }
    free(pq);
}
void
fast_heap_sort(int arr[], int n) {

    PQ* pq = fast_make_heap(arr, n);
    for (int k=0; pq->size>0; k++) {
        arr[k] = pq_extract(pq);
    }
    free(pq);
}

// void
// heap_sort(int arr[], int n) {
//     PQ *pq = pq_init();
//     for (int k=0; k<n; k++) {
//         pq_insert(pq, arr[k]);
//     }
//     // copy back to arr
//     int item;
//     for (int k=0; pq->size>0; k++) {
//         item = pq_extract(pq);
//         arr[k++] = item;
//     }
// }

void
print_array(int arr[], int size) {
    for (int k=0; k<size; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}
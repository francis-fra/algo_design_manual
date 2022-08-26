#include <stdio.h>
#include <stdlib.h>
#include "pq.h"

#define BUF_SIZE 20

// void
// print_array(int arr[], int size) {
//     for (int k=0; k<size; k++) {
//         printf("%d ", arr[k]);
//     }
//     printf("\n");
// }

void
do_test(int *arr, int size) {
    int item;
    // ascending
    PQ *pq = pq_init();
    for (int k=0; k<size; k++) {
        pq_insert(pq, arr[k]);
    }
    print_pq(pq);
    while (pq->size >0) {
        item = pq_extract(pq);
        printf("extracted %d\n", item);
    }
}

int
read_integers(int *arr) {
    int count = 0;
    while(scanf("%d ", &arr[count]) != EOF) {
        count++;
    }
    return count;
}

int main() {

    int arr[BUF_SIZE];
    int count  = read_integers(arr);
    print_array(arr, count);
    // do_test(arr, count);
    heap_sort(arr, count);
    // fast_heap_sort(arr, count);
    print_array(arr, count);

    return 0;
}
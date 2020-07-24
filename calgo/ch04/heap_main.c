#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

int main() {

    priority_queue q;
    pq_init(&q, max_heap);

    itemType val = 5;
    printf("Inserting...%d\n", val);
    pq_insert(&q, val);
    val = 15;
    printf("Inserting...%d\n", val);
    pq_insert(&q, val);

    val = 9;
    printf("Inserting...%d\n", val);
    pq_insert(&q, val);
    pq_show(&q);

    // insert from array
    int arr[5] = {6, 19, 12, 3, 27};
    printf("making heap...\n");
    make_heap(&q, arr, 5);
    pq_show(&q);

    // get statistics
    printf("Min = %d\n", find_min(&q));
    printf("Max = %d\n", find_max(&q));
    printf("root = %d\n", extract_root(&q));
    pq_show(&q);

    // heap sort
    printf("Sorted array\n");
    heap_sort(arr, 5, -1);      // max heap (descending)

    // print array
    for (int k=0; k<5; k++)
        printf("%d\n", arr[k]);

    return 1;
}



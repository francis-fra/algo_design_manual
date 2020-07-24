#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int main(void) {

    /* 
    int arr[] = {3, 7, 5 ,1 , 9, 2};
    int size = 6;
    traverse(arr, size, &print);
    printf("\n");

    printf("After sorting..\n");
    selection_sort(arr, size, &ascending);
    traverse(arr, size, &print);
    printf("\n");
    */

    /*
    int arr2[] = {13, 4, 5 ,10, 8, 19, 1};
    int size = 7;
    traverse(arr2, size, &print);
    printf("\n");
    // merge sort
    printf("After sorting..\n");
    merge_sort(arr2, size, &ascending);
    traverse(arr2, size, &print);
    printf("\n");
    */

    // quick sort
    /*
    int arr3[] = {13, 4, 5 ,10, 8, 19, 7};
    int size = 7;
    traverse(arr3, size, &print);
    printf("\n");
    printf("after sorting...\n");
    quick_sort(arr3, size, &ascending);
    traverse(arr3, size, &print);
    printf("\n");
    */

    // binary search
    int arr4[] = {3, 4, 5, 7, 9, 13, 45};
    int size = 7;
    int target = 5;
    /* traverse(arr4, size, &print); */
    int result = binary_search(arr4, size, target); 
    printf("Found %d\n", result);
   
    int arr5[] = {3, 4, 4, 4, 5, 5, 9, 13, 45};
    size = 9;
    target = 5;

    result = count_occurrences(arr5, size, target); 
    printf("Found %d\n", result);


    return 0;
}

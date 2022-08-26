#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

#define BUF_SIZE 20

void
print_array(int arr[], int size) {
    for (int k=0; k<size; k++) {
        printf("%d ", arr[k]);
    }
    printf("\n");
}

void
do_test(int *arr, int size) {
    int item;
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

    return 0;
}
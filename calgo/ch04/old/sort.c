#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/*
Utility functions
*/
void traverse(int arr[], int size, void (*f)(int)) {
    for (int k=0; k<size; k++) {
        f(arr[k]);
    }
}

void print(int x) {
    printf("%d ", x);
}


void swap(int arr[], int idx1, int idx2) {

    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}


/*
    Selection Sort
*/
void selection_sort(int arr[], int size, int (*compare) (int, int)) {

    for (int n=0; n<size; n++) {
        for (int kk=n+1; kk<size; kk++) {
           if (compare(arr[n], arr[kk]) == -1) {
                swap(arr, n, kk); 
           }
        }
    }
}


void merge(int arr[], int ls, int le, int rs, int re, int (*compare) (int, int)) {
    int left_idx = ls;
    int right_idx = rs;
    int leftVal, rightVal;

    // allocate a temp array
    int total_size = (le-ls+1) + (re-rs+1);
    int *sorted_array = malloc(total_size * sizeof(int));

    for (int k=0; k<total_size; k++) { 
       leftVal = arr[left_idx];
       rightVal = arr[right_idx];
       if (left_idx > le) {
            right_idx++;
            sorted_array[k] = rightVal;
       } else if (right_idx > re) {
            left_idx++;
            sorted_array[k] = leftVal; 
       } else if (compare(leftVal, rightVal) == -1) {
            /* printf("left = %d\n", leftVal); */
            /* printf("right = %d\n", rightVal); */
            right_idx++;
            sorted_array[k] = rightVal;
       } else {
            /* printf("left = %d\n", leftVal); */
            /* printf("right = %d\n", rightVal); */
            left_idx++;
            sorted_array[k] = leftVal;
       }

    }
               
    for (int k=0; k<total_size; k++)
        arr[ls+k] = sorted_array[k];
   
    free(sorted_array);
}

// merge sort
void merge_sort(int arr[], int size, int (*compare) (int, int)) {
    // divide into two sub arrays
    int half = size / 2;
    int rs = half;
    int re = size-1;
    int ls = 0;
    int le = half-1;

    msort(arr, ls, le, compare);
    msort(arr, rs, re, compare);
    merge(arr, ls, le, rs, re, compare);

}

void msort(int arr[], int left_idx, int right_idx, int (*compare) (int, int)) {

    if (left_idx < right_idx) {

        int size = (right_idx - left_idx + 1);
        int half = size / 2;
        int rs = half + left_idx;
        int re = right_idx;
        int ls = left_idx;
        int le = left_idx+half-1;

        msort(arr, ls, le, compare);
        msort(arr, rs, re, compare);
        merge(arr, ls, le, rs, re, compare);
    }
}

int ascending(int a, int b) {
    if (a < b)
        return 1;
    else if (a > b)
        return -1;
    else
        return 0;
}

/*
    Quick Sort
*/
int partition(int arr[], int low, int hi, int (*compare) (int, int)) {
    int p = hi;  // pivot index
    int fp = low; // pivot so far
    int pivot = arr[p];

    for (int k=low; k<hi; k++) {
        if (compare(arr[k], pivot) == 1) {
           swap(arr, k, fp);
           fp++;   // one element less than pivot found, move the index
        }
    }
    // swap the true pivot with the temp pivot
    swap(arr, fp, p);

    return fp;

}


void quick_sort(int arr[], int size, int (*compare) (int, int)) {

    qksort(arr, 0, size-1, compare);

}



void qksort(int arr[], int low, int hi, int (*compare) (int, int)) {

    if (hi > low) {
        int p = partition(arr, low, hi, compare);
        qksort(arr, low, p-1, compare);
        qksort(arr, p, hi, compare);
    }

}

/* 
    Binary Search
*/
// Pre: array is sorted
// Post: return the index
int binary_search(int arr[], int size, int target) {
    return bnsearch(arr, 0, size-1, target);
}


int count_occurrences(int arr[], int size, int target) {

    // FIXME: find the lower bound of the target
    /*
    int lower_bound = boundary_search(arr, 0, size-1, target, &is_less);
    int upper_bound = boundary_search(arr, 0, size-1, target, &is_greater);
    */
    int lower_bound = search_lower_bound(arr, 0, size-1, target);
    int upper_bound = search_upper_bound(arr, 0, size-1, target);
    printf("lower = %d, upper = %d\n", lower_bound, upper_bound);
    return upper_bound - lower_bound;
}

int bnsearch(int arr[], int low, int high, int target) {
    
    if (low >= high) {
        if (arr[low] == target) {
            return low;
        } else {
            return -1;
        }
    } else {
        int middle = (int) ((high - low)/2) + low;

        if (arr[middle] == target) {
            return middle;
        } else if (arr[middle] > target) {
            return bnsearch(arr, low, middle, target);
        } else {
            return bnsearch(arr, middle+1, high, target);
        }

    }

}

int search_upper_bound(int arr[], int low, int high, int target) {
    
    if (low >= high) {
            return low;
    } else {
        int middle = (int) ((high - low)/2) + low;

        if (arr[middle] > target) {
            return search_upper_bound(arr, low, middle, target);
        } else {
            return search_upper_bound(arr, middle+1, high, target);
        }

    }

}


int search_lower_bound(int arr[], int low, int high, int target) {
    
    if (low >= high) {
            return low;
    } else {
        int middle = (int) ((high - low)/2) + low;

        if (arr[middle] < target) {
            return search_lower_bound(arr, middle+1, high, target);
        } else {
            return search_lower_bound(arr, low, middle, target);
        }

    }

}
/*
int boundary_search(int arr[], int low, int high, int target, int (*f)(int, int)) {
    
    if (low >= high) {
            return low;
    } else {
        int middle = (int) ((high - low)/2) + low;

        if (f(arr[middle], target)) {
            return boundary_search(arr, low, middle, target, f);
        } else {
            return boundary_search(arr, middle+1, high, target, f);
        }

    }

}
*/

int is_greater(int a, int b) {
    return (a > b);
}

int is_less(int a, int b) {
    return (a < b);
}
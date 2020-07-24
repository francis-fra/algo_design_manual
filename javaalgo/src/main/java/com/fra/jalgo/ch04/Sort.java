package com.fra.jalgo.ch04;

import java.util.Comparator;
import java.util.List;
import java.util.Arrays;

// TODO: heap sort


public class Sort<T extends Comparable<T>> {

    private void swap(List<T> lst, int a, int b) {
        // System.out.printf("Swapping %d with %d\n", a, b);   // DEBUG
        T tmp = lst.get(a);
        lst.set(a, lst.get(b));
        lst.set(b, tmp);
    }

    private int find_minmax_index(List<T> lst, int start, int ending, Comparator<T> comp) {

        int index = start;
        for (int n=start+1; n<ending; n++) {
            // DEBUG
            // System.out.printf("first: %d, second: %d\n", lst.get(n), lst.get(index));
            // System.out.println(comp.compare(lst.get(n), lst.get(index)));
            if (comp.compare(lst.get(n), lst.get(index)) < 0) {
                index = n;
            }
        }
        // System.out.printf("Min at %d\n", index);        // DEBUG
        return index;
    }

    public void selection_sort(List<T> lst, Comparator<T> comp) {

        int min_index;
        for (int n=0; n<lst.size(); n++) {
            min_index = find_minmax_index(lst, n, lst.size(), comp);
            swap(lst, n, min_index);
        }
        // arr.sort(comp);

    };

    private int find_middle(int a, int b) {
        return (a+b)/2;
    };

    // for merge sort
    private void combine(List<T> lst, int start, int middle, int ending, Comparator<T> comp) {

        // create a temp array to store the two merged sorted subarrays
        Object[] arr = new Object[ending-start+1]; 
        int left_arr_idx = start;
        int right_arr_idx = middle+1;
        int idx = start;

        while (idx <= ending) {
            if (left_arr_idx > middle) {
                arr[idx++] = lst.get(right_arr_idx++);
            } else if (right_arr_idx > ending) {
                arr[idx++] = lst.get(left_arr_idx++);
            } else {
                if (comp.compare(lst.get(left_arr_idx), lst.get(right_arr_idx)) < 0) {
                    arr[idx++] = lst.get(left_arr_idx++);
                } else {
                    arr[idx++] = lst.get(right_arr_idx++);
                }
            }
        }


        // copy the array back to List
        for (int k=start; k<=ending; k++) {
            lst.set(k, (T) arr[k-start]);
        }
        
    };

    // inclusive indices from start to ending
    private void merge(List<T> lst, int start, int ending, Comparator<T> comp) {
        if (start >= ending) {
            return;
        } else if (ending - start == 1) {
            if (comp.compare(lst.get(start), lst.get(ending)) > 0) {
                swap(lst, start, ending);
            }
        } else {
            int middle = find_middle(start, ending);
            merge(lst, start, middle, comp);
            merge(lst, middle+1, ending, comp);
            combine(lst, start, middle, ending, comp);
        }

    };

    public void merge_sort(List<T> lst, Comparator<T> comp) {

        // divide array into two equal size and merge
        merge(lst, 0, lst.size()-1, comp);

    };

    private void qsort(List<T> lst, int start, int ending, Comparator<T> comp) {

        if (start >= ending) {
            return;
        }
        int pivot_idx = partition(lst, start, ending, comp);
        qsort(lst, start, pivot_idx-1, comp);
        qsort(lst, pivot_idx+1, ending, comp);
    };

    // choose a pivot and move smaller (larger) values to the left (right)
    // @param: start / ending are inclusive array indices
    // return the pivot index
    public int partition(List<T> lst, int start, int ending, Comparator<T> comp) {
        int pivot_idx = ending;
        // anchor is the temporary pivot point so far
        int anchor = start;

        for (int k=start; k<=ending; k++) {
            if (comp.compare(lst.get(k), lst.get(pivot_idx)) < 0) {
                swap(lst, k, anchor);
                // System.out.printf("anchor = %d\n", anchor);
                anchor++;
            } 
        }
        swap(lst, anchor, ending);

        return anchor;

    }

    public void quick_sort(List<T> lst, Comparator<T> comp) {

        qsort(lst, 0, lst.size()-1, comp);

    }
}
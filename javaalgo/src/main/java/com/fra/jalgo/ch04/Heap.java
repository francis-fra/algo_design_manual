package com.fra.jalgo.ch04;

import java.util.Comparator;
import java.util.ArrayList;
import java.util.List;
import java.util.Arrays;
// import java.lang.*;

enum HeapType {
    MAX_HEAP,       // root is the largest
    MIN_HEAP        // root is the smallest
};

public class Heap<T extends Comparable<T>> {

    // private int size;
    private HeapType type;
    private List<Object> arr;
    
    Heap(List<T> lst, HeapType type) {
        this.type = type;
        // this.size = lst.size();
        arr = new ArrayList<Object>();
        make_heap(lst, type);
        // TODO: how to initialize (or clone) a generic container??
        // this.lst = new ArrayList<T>();
    }

    private void swap(List<Object> lst, int a, int b) {
        Object tmp = lst.get(a);
        lst.set(a, lst.get(b));
        lst.set(b, tmp);
    }

    /*
    private int find_minmax_index(List<T> lst, int start, int ending, Comparator<T> comp) {

        int index = start;
        for (int n=start+1; n<ending; n++) {
            if (comp.compare(lst.get(n), lst.get(index)) < 0) {
                index = n;
            }
        }
        return index;
    }
    */

    private void make_heap(List<T> lst, HeapType type) {

        for (int k=0; k<lst.size(); k++) {
            pq_insert(lst.get(k));
        }
    }

    // insert item to the end of the heap
    private void pq_insert(T item) {
        arr.add(item);
        // heapify if necessary
        if (this.type == HeapType.MAX_HEAP)
            bubble(arr.size()-1, Comparator.naturalOrder());
        else
            bubble(arr.size()-1, Comparator.reverseOrder());

    }

    // FIXME: unsafe casting
    private void bubble(int index, Comparator<T> comp) {
        int parent_idx = get_parent_idx(index); 
        T parent = (T) this.arr.get(parent_idx);
        T me = (T) this.arr.get(index);

        if (comp.compare(parent, me) < 0) {
            swap(this.arr, parent_idx, index);
            bubble(parent_idx, comp);
        }
    }

    private int get_parent_idx(int index) {
        return (int) Math.floor((index-1)/2);
    }

    public T extract_root() {
        if (arr.size() <= 0) {
            return null;
        }
        // extract the root
        T root = (T) this.arr.get(0);
        // need to replace the root only if there are more items left
        if (this.arr.size() > 1) {

            // move the rightmost to the root
            T last_item = (T) this.arr.get(this.arr.size()-1);
            this.arr.set(0, last_item);
            this.arr.remove(this.arr.size()-1);

            if (this.type == HeapType.MAX_HEAP)
                bubble_root(0, Comparator.naturalOrder());
            else
                bubble_root(0, Comparator.reverseOrder());
        }

        return root;

    }

    private void bubble_root(int index, Comparator<T> comp) {

        int younger_child_index = get_younger_child_index(index);

        int swap_index = index;
        T this_item;
        int this_index;
        T swap_item = (T) this.arr.get(index);

        // find the rightmost
        int last_index = this.arr.size() - 1;
        for (int k=0; k<=1; k++) {
            // check bound
            if (younger_child_index + k < last_index) {
                this_index = younger_child_index + k;
                this_item = (T) this.arr.get(this_index);
                if (comp.compare(this_item, swap_item) > 0 ) {
                    swap_index = younger_child_index + k;
                    swap_item = (T) this.arr.get(younger_child_index + k);
                }
            }
        }

        if (swap_index != index) {
            swap(this.arr, index, swap_index);
            bubble_root(swap_index, comp);
        }

    }

    private int get_younger_child_index(int index) {
        return (2*index+1);
    }

    public void show() {
        for (Object item: this.arr) {
            System.out.print(item + " ");
        }
        System.out.print('\n');
    }

    public static void main(String[] argv) {
        
        // TODO: unit test
        List<Integer> numbers = new ArrayList<Integer>(Arrays.asList(5,3,8,1,6,2,9,7,4));
        Integer arr[] = {5,3,8,1,6,2,9,7,4};

        Heap<Integer> minheap = new Heap<Integer>(Arrays.asList(arr), HeapType.MIN_HEAP);
        // Heap<Integer> maxheap = new Heap<Integer>(Arrays.asList(arr), HeapType.MAX_HEAP);
        Heap<Integer> maxheap = new Heap<Integer>(numbers, HeapType.MAX_HEAP);

        minheap.show();
        maxheap.show();

        String str_arr[] = {"bannana", "water", "apple", "pear", "cat", "nuts"};
        Heap<String> maxheap_string = new Heap<String>(Arrays.asList(str_arr), HeapType.MAX_HEAP);
        maxheap_string.show();

        int root = minheap.extract_root();
        System.out.printf("root: %d\n", root);
        minheap.show();

        root = minheap.extract_root();
        System.out.printf("root: %d\n", root);
        minheap.show();
        
        for (int k=0; k<6; k++) {
            System.out.printf("root: %s\n", maxheap_string.extract_root());
            maxheap_string.show();
        }

    }

}
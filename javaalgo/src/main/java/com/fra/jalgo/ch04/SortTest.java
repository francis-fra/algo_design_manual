package com.fra.jalgo.ch04;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.*;

public class SortTest {
    
    static public void QuickSortTest01() {

        List<String> words = new ArrayList<>();
        words.add("dog");
        words.add("cat");
        words.add("water");
        words.add("pen");

        // selection sort
        Sort<String> stringsort = new Sort<String>();
        // stringsort.selection_sort(words, Comparator.naturalOrder());
        // stringsort.merge_sort(words, Comparator.naturalOrder());

        stringsort.quick_sort(words, Comparator.naturalOrder());
        words.forEach(System.out::println);
    }

    static public void MergeSortTest01() {

        Sort<Integer> numsort = new Sort<Integer>();
        List<Integer> numbers = new ArrayList<>(Arrays.asList(5,7, 1, 3, 4));
        
        // numbers = new ArrayList<>(Arrays.asList(5,7, 8, 3, 4));
        // numsort.combine(numbers, 0, 2, 4, Comparator.naturalOrder());

        numbers = new ArrayList<>(Arrays.asList(5,7, 1, 3, 4));
        numsort.merge_sort(numbers, Comparator.naturalOrder());
        numbers.forEach(System.out::println);

    }

    static public void QuickSortTest02() {
        
        Sort<Integer> numsort = new Sort<Integer>();
        List<Integer> numbers = new ArrayList<>(Arrays.asList(5,7, 1, 3, 4));

        numbers = new ArrayList<>(Arrays.asList(6, 4, 8, 7, 1, 5));
        numsort.quick_sort(numbers, Comparator.naturalOrder());
        // int pivot_idx = numsort.partition(numbers, 0, 5, Comparator.naturalOrder());
        // System.out.printf("Pivot at %d\n", pivot_idx);
        numbers.forEach(System.out::println);

    }

    static public void SelectionSortTest01() {
        Sort<Integer> numsort = new Sort<Integer>();
        List<Integer> numbers = new ArrayList<>(Arrays.asList(5,7, 1, 3, 4));

        numbers = new ArrayList<>(Arrays.asList(6, 4, 8, 7, 1, 5));
        numsort.selection_sort(numbers, Comparator.naturalOrder());
        // int pivot_idx = numsort.partition(numbers, 0, 5, Comparator.naturalOrder());
        // System.out.printf("Pivot at %d\n", pivot_idx);
        numbers.forEach(System.out::println);

    }

    static public void HeapSortTest01() {
        // List<Integer> numbers = new ArrayList<Integer>(Arrays.asList(5,3,8,1,6,2,9,7,4));
        // Heap<Integer> maxheap = new Heap<Integer>(numbers, HeapType.MAX_HEAP);

        Integer arr[] = {5,3,8,1,6,2,9,7,4};

        // TODO: heap sort
        Heap<Integer> maxheap = new Heap<Integer>(Arrays.asList(arr), HeapType.MAX_HEAP);
        maxheap.show();
        // Heap<Integer> minheap = new Heap<Integer>(Arrays.asList(arr), HeapType.MIN_HEAP);
        // minheap.show();

        // sorting
        for (int k=0; k<arr.length; k++) {
            System.out.printf("%s, ", maxheap.extract_root());
        }
        System.out.println();


    }

    static public void HeapSortTest02() {

        String arr[] = {"bannana", "water", "apple", "pear", "cat", "nuts"};
        Heap<String> heap= new Heap<String>(Arrays.asList(arr), HeapType.MIN_HEAP);
        heap.show();

        for (int k=0; k<arr.length; k++) {
            System.out.printf("%s, ", heap.extract_root());
        }
        System.out.println();

    }
}

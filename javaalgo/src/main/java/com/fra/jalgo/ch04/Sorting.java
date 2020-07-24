package com.fra.jalgo.ch04;

import java.util.ArrayList;
import java.util.Comparator;
// import java.util.List;
import java.util.*;

public class Sorting {

    public static void main(String[] argv) {
        // SelectionSort<Integer> sort = new SelectionSort<Integer>();
        // int value = sort.compare(5, 6);
        // System.out.println(value);

        //-----------------
        // String
        //-----------------
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


        Sort<Integer> numsort = new Sort<Integer>();
        List<Integer> numbers = new ArrayList<>(Arrays.asList(5,7, 1, 3, 4));

        //-----------------
        // Number
        //-----------------

        //-----------------
        // Selection sort
        //-----------------
        // System.out.println("Before....");
        // numbers.forEach(System.out::println);
        // numsort.selection_sort(numbers, Comparator.naturalOrder());
        // System.out.println("After....");
        // numbers.forEach(System.out::println);

        // numsort.selection_sort(numbers, Comparator.reverseOrder());
        // System.out.println("After....");
        // numbers.forEach(System.out::println);

        // words.sort(Comparator.reverseOrder());
        // words.forEach(System.out::println);
        // words.sort(Comparator.naturalOrder());
        // words.forEach(System.out::println);

        //-----------------
        // merge sort
        //-----------------
        // numbers = new ArrayList<>(Arrays.asList(5,7, 8, 3, 4));
        // numsort.combine(numbers, 0, 2, 4, Comparator.naturalOrder());

        // numbers = new ArrayList<>(Arrays.asList(5,7, 1, 3, 4));
        // numsort.merge_sort(numbers, Comparator.naturalOrder());
        // numbers.forEach(System.out::println);

        //-----------------
        // quick sort
        //-----------------
        numbers = new ArrayList<>(Arrays.asList(6, 4, 8, 7, 1, 5));
        numsort.quick_sort(numbers, Comparator.naturalOrder());
        // int pivot_idx = numsort.partition(numbers, 0, 5, Comparator.naturalOrder());
        // System.out.printf("Pivot at %d\n", pivot_idx);
        numbers.forEach(System.out::println);

    }

}
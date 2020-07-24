package com.fra.jalgo.ch04;

import java.util.Comparator;
import java.util.List;

public class SelectionSort<T extends Comparable<T>> {

    // @DEPRECATED
    public int compare(T a, T b) {
        return a.compareTo(b);
    };

    public void sort(List<T> arr, Comparator<T> comp) {
        // TODO: implement sorting algorithm
        arr.sort(comp);

    };
}
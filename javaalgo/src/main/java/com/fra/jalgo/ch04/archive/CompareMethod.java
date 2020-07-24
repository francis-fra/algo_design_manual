package com.fra.jalgo.ch04;

// @DEPRECATED
public interface CompareMethod<T> {
    int compare(T a, T b);
}

// class greater<T> implements CompareMethod<T> {
//     @Override
//     public int compare(T a, T b) {
//         return a > b;
//     }
// }
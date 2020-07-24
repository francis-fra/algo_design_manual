#ifndef _SORT_H
#define _SORT_H
#include <iostream>
#include <array>

using namespace std;

template <class T>
void swap(T* a, T* b) {
    T tmp = *a;
    *a = *b;
    *b = tmp;
}

template <class T>
void print_container(T& con) {
    for (auto p = con.begin(); p != con.end(); ++p) {
        if (p != con.begin())
            cout << ", ";
        cout << *p ;
    } 
    cout << endl;
}

// TODO: comparable??
template <class T>
unsigned find_min(vector<T>& vec, int start, int end) {
    unsigned index = start;
    T min_val = vec.at(index);

    for (unsigned k=start+1; k<end; ++k) {
        if (vec.at(k) < min_val) {
            index = k;
            min_val = vec.at(index);
        }
    }
    return index;
}

// TODO: sorting
template <class T>
void selection_sort(vector<T>& vec) {

    unsigned index;
    for (unsigned k=0; k<vec.size(); ++k) {
        index = find_min(vec, k, vec.size());
        if (index != k)
            swap(&vec.at(index), &vec.at(k));
    } 

}

#endif
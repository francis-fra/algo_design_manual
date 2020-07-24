#ifndef _HEAP_H
#define _HEAP_H

#include "../algo/Comparator.hpp"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

namespace Algo {

    template<class T>
    class Heap {
        public:
            // default constructor
            constexpr Heap<T>(int capacity=10, bool descending=true): _capacity{capacity}, Cmp{Comparator<T>{descending}} { };

            // construct by initizilizer list
            Heap<T>(std::initializer_list<T> arg, int capacity=10, bool descending=true): _capacity{capacity}, Cmp{Comparator<T>{descending}} {
                for (auto item: arg) {
                    this->insert(item);
                }
            };

            // copy constructor
            constexpr Heap(const Heap &H): pq{H.pq}, _capacity{H._capacity}, Cmp{H.Cmp} {};

            // 
            void insert(T item) {

                if (isFull())
                    return;

                pq.push_back(item);
                // check if heap is maintained
                int last_idx = this->last_heap_index();
                int parent_idx = this->pq_parent(last_idx);

                this->bubble_up(parent_idx, last_idx);

            };

            T extract_root() {
                // T result;
                if (isEmpty()) {
                    throw range_error("Heap is empty");
                } else {
                    // return the root item
                    T result = pq[0];
                    // copy the last item to the root
                    // pq[0] = this->pq.pop_back();
                    if (pq.size() > 1) {
                        pq[0] = pq[pq.size()-1];
                        this->pq.pop_back();
                        this->bubble_down(1);
                    }
                    return result;
                }
            }

            bool isFull() {
                return pq.size() >= _capacity;
            }

            bool isEmpty() {
                return pq.size() == 0;
            }

            void show() {
                for (auto item: pq) {
                    cout << item << " |> ";
                }
                cout << endl;
            }

            // accessor
            int size() const {
                return pq.size();
            };

            int capacity() const {
                return _capacity;
            };

            // for testing only
            int test_parent(int idx) {
                return finding_parent_idx(idx);
            }

            // for testing only
            // use vector index
            void test_swap(int idx1, int idx2) {
                swap(pq[idx1],pq[idx2]);
            }


        private:
            Comparator<T> Cmp;
            int _capacity;
            vector<T> pq;

            // get parent index
            // pq index starts from 1
            int pq_parent(int n) const {
                return n <= 1 ? -1 : ((int) n/2);
            };

            // get youngest child index
            // pq index starts from 1
            int pq_young_child(int n) const {
                return (2*n);
            };

            // index from 0 to capacity-1
            // -1 if none
            int last_item_index() {
                return pq.size() - 1;
            }

            // 0 if none
            int last_heap_index() {
                return pq.size();
            }

            int vec_to_heap_index(int n) {
                return n+1;
            }

            int heap_to_vec_index(int n) {
                return n-1;
            }

            // index of children or parent to become a parent
            int finding_parent_idx(int idx) {
                int youngest_idx = pq_young_child(idx);
                int oldest_idx = youngest_idx + 1;
                int last_idx = last_heap_index();
                int next_parent;

                if (youngest_idx > last_idx) {
                    // num_children = 0;
                    next_parent = idx;
                } else if (oldest_idx <= last_idx) {
                    // num_children = 2;
                    next_parent = oldest_idx;
                    // compare two children
                    if (Cmp(pq[heap_to_vec_index(next_parent)], pq[heap_to_vec_index(youngest_idx)])) {
                        next_parent = youngest_idx;
                    }
                    // compare parent with the children
                    if (Cmp(pq[heap_to_vec_index(next_parent)], pq[heap_to_vec_index(idx)])) {
                        next_parent = idx;
                    }

                } else {
                    // num_children = 1;
                    if (Cmp(pq[heap_to_vec_index(idx)], pq[heap_to_vec_index(youngest_idx)])) {
                        next_parent = youngest_idx;
                    } else {
                        next_parent = idx;
                    }
                }
                return next_parent;

            }

            // idx is the heap index
            /*
            int num_children(int idx) {

                int youngest_idx = pq_young_child(idx);
                int oldest_idx = youngest_idx + 1;
                int last_idx = last_heap_index();
                int num_children;

                if (youngest_idx > last_idx) {
                    num_children = 0;
                } else if (oldest_idx <= last_idx) {
                    num_children = 2;
                } else {
                    num_children = 1;
                }
                return num_children;
            }
            */

            // swap items (heap index)
            void swap_item_at(int idx1, int idx2) {
                idx1 = heap_to_vec_index(idx1);
                idx2 = heap_to_vec_index(idx2);
                std::swap(pq[idx1],pq[idx2]);
            };

            // recursively swap 
            void bubble_up(int parent_idx, int child_idx) {
                if (parent_idx <= 0)
                    return;
                
                T parent = this->pq.at(heap_to_vec_index(parent_idx));
                T child = this->pq.at(heap_to_vec_index(child_idx));
                if (Cmp(parent, child)) {
                    swap_item_at(parent_idx, child_idx);
                    // recursive call
                    child_idx = parent_idx;
                    parent_idx = pq_parent(child_idx);
                    bubble_up(parent_idx, child_idx);
                } else {
                    return;
                }
            };

            // idx: heap index
            void bubble_down(int idx) {
                int next_parent_idx = finding_parent_idx(idx);
                if (next_parent_idx != idx) {
                    swap_item_at(idx, next_parent_idx);
                    bubble_down(next_parent_idx);
                }

            };
    };

    /*
    template<class T>
    void heapsort(std::initializer_list<T> arg, bool descending=true) {

        Heap<T> *H = new Heap<T>(arg.size(), descending);
        for (auto item: arg) {
            H->insert(item);
        }
        // reinsert item back to vec
        for (int k=0; k<vec.size(); k++) {
            vec.at(k) = H->extract_root();
        }
        delete H;
    }
    */

    template<class T>
    void heapsort(std::vector<T>& vec, bool descending=true) {
        Heap<T> *H = new Heap<T>(vec.size(), descending);
        for (auto item: vec) {
            H->insert(item);
        }
        // reinsert item back to vec
        for (int k=0; k<vec.size(); k++) {
            vec.at(k) = H->extract_root();
        }

        delete H;
    }


} // algo


#endif
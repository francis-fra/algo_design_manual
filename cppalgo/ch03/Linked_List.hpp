#ifndef _LINKED_LIST_H
#define _LINKED_LIST_H

#include <iostream>
#include <vector>
using namespace std;

namespace Algo {

    template<class T>
    struct LinkedNode {
        // default constructor
        // LinkedNode<T>(): next{nullptr} {};
        LinkedNode<T>(const T& a): item{a}, next{nullptr} {};
        T item;
        LinkedNode<T>* next;
    };

    // Numerical class
    template<class T>
    class LinkedList {

        public:
            LinkedList<T>(): head{nullptr} {}; 

            LinkedList<T>(initializer_list<T> arg) {
                head = nullptr;
                for (auto item: arg) {
                    insert(item);
                }
            };

            // copy constructor
            LinkedList<T>(const LinkedList<T>& L) {
                copy_all(L);
            };

            // move constructor
            LinkedList<T>(LinkedList<T>&& L) {
                this->head = L.first();
                L.head = nullptr;
            };


            // copy operator
            LinkedList<T>& operator=(const LinkedList<T>& L) {
                free_all();
                copy_all(L);
                return *this;
            };

            // move operator
            LinkedList<T>& operator=(LinkedList<T>&& L) {
                free_all();
                this->head = L.first();
                L.head = nullptr;
            };

            ~LinkedList<T>() {
                free_all();
            };

            LinkedNode<T>* last() const {
                LinkedNode<T>* current = this->head;
                LinkedNode<T>* parent;
                // find the last node
                while (current != nullptr) {
                    parent = current;
                    current = current->next;
                }
                return parent;
            };


            LinkedNode<T>* first() const {
                return head;
            };

            bool isEmpty() const {
                return head == nullptr;
            };

            // insert at the end
            void insert(const T& item) {
                // new node
                LinkedNode<T>* node = new LinkedNode<T>(item);
                // if the list is currently empty, set the head to the new node
                if (isEmpty()) {
                    this->head = node;
                } else {
                    LinkedNode<T>* current = this->head;
                    LinkedNode<T>* parent;
                    // find the last node
                    while (current != nullptr) {
                        parent = current;
                        current = current->next;
                    }
                    parent->next = node;
                }
            };

            // insert at the front
            void prepend(const T& item) {
                // new node
                LinkedNode<T>* node = new LinkedNode<T>(item);
                // if the list is currently empty, set the head to the new node
                if (isEmpty()) {
                    this->head = node;
                } else {
                    LinkedNode<T>* current = this->head;
                    node->next = current;
                    this->head = node;
                }

            };

            // FIXME: cannot remove last
            void remove() {
                LinkedNode<T>* node = last_parent();
                if (node != nullptr) {
                    delete node->next;
                    // remember to set both ends of the link
                    node->next = nullptr;
                } else {
                    // last parent is null, it means:
                    // either it had one or zero node before
                    this->head = nullptr;
                }
            };

            // mutable
            void forEach(T (*f) (const T&) ) {
                LinkedNode<T>* current = this->head;
                while (current != nullptr) {
                    T item = f(current->item);
                    current->item = item;
                    current = current->next;
                }
            };

            // TODO: map() to return a new linkedlist

            // mutable
            void reverse() {
                if (isEmpty())
                    return;

                // single item
                if (this->head->next == nullptr)
                    return;

                LinkedNode<T>* parent = this->head;
                LinkedNode<T>* child = this->head->next;

                // save the tail
                LinkedNode<T>* tail = child->next;

                // the last node is the end node
                parent->next = nullptr;

                // reverse the link direction
                this->head = child;
                child->next = parent;

                while (tail != nullptr) {
                    // advance
                    parent = child;
                    child = tail;
                    tail = tail->next;
                    // reverse direction
                    this->head = child;
                    child->next = parent;
                }
                return;
            }



        private:
            // head should always point to the first node or nullptr
            LinkedNode<T>* head;

            LinkedNode<T>* last_parent() const {
                LinkedNode<T>* current = this->head;
                LinkedNode<T>* parent = nullptr;
                LinkedNode<T>* grand_parent = nullptr;
                // find the last node
                while (current != nullptr) {
                    grand_parent = parent;
                    parent = current;
                    current = current->next;
                }
                return grand_parent;
                // return parent;
            };

            void free_all() {
                // remember all node address
                vector<LinkedNode<T>*> vec;

                LinkedNode<T>* current = this->head;
                LinkedNode<T>* parent = nullptr;
                // find the last node
                while (current != nullptr) {
                    vec.push_back(current);
                    parent = current;
                    current = current->next;
                }
                // free all nodes
                for (auto node: vec) {
                    delete node;
                }
            };

            void copy_all(const LinkedList<T>& L) {
                if (L.isEmpty()) {
                    this->head = nullptr;
                } else {
                    // current is the last item in the source list
                    LinkedNode<T>* current = L.first();
                    // node is the last item in the destination list
                    LinkedNode<T>* node = new LinkedNode<T>(current->item);
                    // set the head to the fisrt node
                    this->head = node;
                    // then copy the rest
                    while(current->next != nullptr) {
                        current = current->next;
                        LinkedNode<T>* nextnode = new LinkedNode<T>(current->item);
                        node->next = nextnode;
                        node = node->next;
                    }
                }
            };

    }; // end LinkedList


    template <class T>
    ostream& operator<<(ostream& out, const LinkedList<T>& L) {
        LinkedNode<T>* current = L.first();
        while (current != nullptr) {
            out << current->item << " |> ";
            current = current->next;
        }
        return out;
    };

};

#endif
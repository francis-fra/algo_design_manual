/*
*   Operators for Linked List
*   @author: Fra
*/

#ifndef _LINKED_LISH_H
#define _LINKED_LISH_H
#include <iostream>
// #include "linked_list_node.h"

using namespace std;


template <class T> 
class LinkedNode {
    private:
        T item;
        LinkedNode *next;
    public:
        LinkedNode(T value) {
            item = value;
            next = nullptr;
        }
        // item accessor
        T get_item() {
            return item;
        }
        // assign next node pointer
        void link(LinkedNode* node) {
            this->next = node;
        }
        // link accessor
        LinkedNode *next_node() {
            return this->next;
        }
        // copy constructor
        // FIXME: deep copy needed
        LinkedNode(const LinkedNode& node) {
            this->item = node.item;
            this->next = node.next;
        }
        // FIXME: can't free it here - next node might be lost when destructor is called
        // ~LinkedNode() {
            // LinkedNode<T> *p = head->next_node();
            // LinkedNode<T> *next;        // node after the to-be deleted node
            // while (p != nullptr) {
            //     next = p->next_node();
            //     cout << "deleting... " << p->get_item() << endl;
            //     delete p;
            //     p = next;
            // }
        // }
        
};

template <class T>
LinkedNode<T>* create_Node(T item) {
    return new LinkedNode<T>(item);
};

template <class T>
void delete_Node(LinkedNode<T> *node) {
    delete node;
};

// insert at front of the list
template <class T>
void insert_list(LinkedNode<T> *head, T item) {

    // create new node with new item
    LinkedNode<T> *node = create_Node(item);
    // update link fro new node
    node->link(head->next_node());
    // update link from the head
    head->link(node);

};

// FILO
// remove at the back
template <class T>
void remove_node(LinkedNode<T> *head) {

    // save the orignal head and the first node
    LinkedNode<T> *parent = head;
    LinkedNode<T> *current = parent->next_node();

    // current is the node about to be removed
    // parent is the node pointing (parent) to current
    if (current != nullptr) {
        LinkedNode<T> *p = current->next_node();
        // search for the last node
        while (p != nullptr) {
            parent = current;
            current = p;
            p = p->next_node();
        }
        // remove it and update the parent
        delete current;
        parent->link(nullptr);
    } 
}

// default is to print
template <class T>
void traverse_list(LinkedNode<T> *head) {
    // FIXME: head is skipped...
    LinkedNode<T> *p = head->next_node();
    while (p != nullptr) {
        cout << p->get_item() << ", ";
        p = p->next_node();
    }
    cout << endl;
}

// traverse list with custom function
template <class T>
void traverse_list(LinkedNode<T> *head, void (*f) (LinkedNode<T>*)) {
    // skip the head
    LinkedNode<T> *p = head->next_node();
    while (p != nullptr) {
        f(p);
        p = p->next_node();
    }
    f(p);
}

// delete all the linked nodes after head
template <class T>
void free_list(LinkedNode<T> *head) {
    LinkedNode<T> *p = head->next_node();
    LinkedNode<T> *next;        // node after the to-be deleted node
    while (p != nullptr) {
        next = p->next_node();
        cout << "deleting... " << p->get_item() << endl;
        delete p;
        p = next;
    }
}

// print item in a single node
template <class T>
void print_node(LinkedNode<T> *node) {
    if (node != nullptr)
        cout << node->get_item() << ", ";
    else
        cout << endl;
}

// non-empty initializing list
template<class T>
LinkedNode<T>* create_linked_list(std::initializer_list<T> lst) {
    // head has a dummy item 0
    LinkedNode<T> *linked_node = new LinkedNode<T>(0);
    const T* first = lst.begin();
    for (const T* v=first; v != lst.end(); v++) {
        insert_list(linked_node, *v);
    }
    return linked_node;
}

#endif
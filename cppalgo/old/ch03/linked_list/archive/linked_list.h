/*
*   Deprecated
*   Operators for Linked List
*   @author: Fra
*/

#ifndef _LINKED_LISH_H
#define _LINKED_LISH_H
#include <iostream>
#include "linked_list_node.h"

using namespace std;


// create dynamic linked node structure
// call linked node constructor
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
    // update link from the new node
    node->link(head->next_node());
    // update link from the head
    head->link(node);

};

template <class T>
void traverse_list(LinkedNode<T> *head) {
    // skip the head
    LinkedNode<T> *p = head->next_node();
    while (p != 0) {
        cout << p->get_item() << ", ";
        p = p->next_node();
    }
    cout << endl;
}


template <class T>
void traverse_list(LinkedNode<T> *head, void (*f) (LinkedNode<T>*)) {
    // skip the head
    LinkedNode<T> *p = head->next_node();
    while (p != 0) {
        f(p);
        p = p->next_node();
    }
    f(p);
}

template <class T>
void free_list(LinkedNode<T> *head) {
    LinkedNode<T> *p = head->next_node();
    LinkedNode<T> *next;        // node after the to-be deleted node
    while (p != 0) {
        next = p->next_node();
        delete p;
        p = next;
    }
}

template <class T>
void print_node(LinkedNode<T> *node) {
    if (node != 0)
        cout << node->get_item() << ", ";
    else
        cout << endl;
}


#endif
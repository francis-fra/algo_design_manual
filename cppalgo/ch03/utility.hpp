#ifndef _REV_LINKED_LIST_H
#define _REV_LINKED_LIST_H

#include "Linked_List.hpp"
#include "BST.hpp"
#include <iostream>

using namespace Algo;

// immutable
template<class T>
LinkedList<T>* get_reverse_linked_list(const LinkedList<T> &L) {
    LinkedList<T>* R = new LinkedList<T>();

    LinkedNode<T>* source = L.first();
    LinkedNode<T>* dest;
    while (source != nullptr) {
        // add the new node to head
        R->prepend(source->item);
        // advance the source
        source = source->next;
    }
    return R;
}

template<class T>
void add_node(BSTNode<T>* node, LinkedList<T>* L) {

    if (node == nullptr)
        return;

    if (node->left != nullptr)
        add_node(node->left, L);

    if (node->right != nullptr)
        add_node(node->right, L);

    // after adding all branches, add this node
    L->insert(node->item);
}

template<class T>
LinkedList<T>* BST_to_LinkedList(const BST<T> &B) {
    LinkedList<T>* L = new LinkedList<T>();

    if (B.isEmpty())
        return L;

    BSTNode<T>* root = B.root();

    add_node(root, L);
    // add_node(root->left, L);
    // add_node(root->right, L);


    return L;

}


#endif
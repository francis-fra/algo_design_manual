/*
*   Operators for Linked List
*   @author: Fra
*/

#ifndef _BINARY_TREE_H
#define _BINARY_TREE_H
#include <iostream>

using namespace std;

template <class T>
class btree {
private:
    T item;
    btree<T> *parent;
    btree<T> *left;
    btree<T> *right;
    btree() {};         // default constructor not callable
public:
    btree(btree* parent, T item) {
        this->parent = parent;
        this->item = item;
        this->left = nullptr;
        this->right = nullptr;
    }
    // copy constructor -- not necessary for tree pointers
    btree(const btree& tree) {
        this->parent = tree.parent;
        this->item = tree.item;
        this->left = tree.left;
        this->right = tree.right;
    }

    ~btree() {
        if (this->left != nullptr)
            delete this->left;
        if (this->right != nullptr)
            delete this->right;
        cout << "deleting node..." << item << endl;
    }

    // TODO: initializing list constructor
    // btree(std::initializer_list<T> lst) {
    //     this->parent = nullptr;
    //     this->item = *lst.begin();
    //     this->left = nullptr;
    //     this->right = nullptr;
    // }

    T get() { return item; };
    void set(T value) { item = value; };

    // {- friends -}
    template <class K>
    friend void insert_btree(btree<K>*, const K&);
    template <class K>
    friend void traverse_btree(btree<K> *tree, void (*f)(btree<K> *));
    template <class K>
    friend btree<K>* search_tree(btree<K> *tree, const K& item);
    template <class K>
    friend K min(btree<K>* tree);
    // template <class K>
    // friend void delete_btree(btree<K> *tree);
};


template <class T>
btree<T>* create_btree(const T& item, btree<T>* parent= nullptr) {
    return new btree<T>(parent, item);
}

template <class T>
btree<T>* create_btree(std::initializer_list<T> lst) {
    T first = *(lst.begin());
    btree<T>* head = new btree<T>(nullptr, first);
    const T* second = lst.begin() + 1;
    for (const T* v=second; v!= lst.end(); v++) {
        insert_btree(head, *v);
    }
    return head;
}

template <class T>
void insert_btree(btree<T>* head, const T& item) {
    if (head->item < item) {
        // insert to the right leaf
        if (head->right == nullptr) {
            head->right = create_btree(item, head);
        } else {
            insert_btree(head->right, item);
        }
    } else {
        // insert to the left leaf
        if (head->left == nullptr) {
            head->left = create_btree(item, head);
        } else {
            insert_btree(head->left, item);
        }
    }
} 

template <class T>
void traverse_btree(btree<T> *tree, void (*f)(btree<T> *)) {
    if (tree == nullptr) {
        return;
    } else {
        traverse_btree(tree->left, f);
        f(tree);
        traverse_btree(tree->right, f);
    }
}

template <class T>
void print(btree<T> *b) {
    cout << b->get() << " ";
}


template <class T>
btree<T>* search_tree(btree<T> *tree, const T& item) {
   if (tree == nullptr) {
       return nullptr;
   } else {
       if (tree->item > item) {
           if (tree->left == nullptr) {
               return nullptr;
           } else {
               return search_tree(tree->left, item);
           }
       } else if (tree->item < item) {
           if (tree->right == nullptr) {
               return nullptr;
           } else {
               return search_tree(tree->right, item);
           }
       } else {
           return tree;
       }
   }

}

template <class T>
T min(btree<T> *tree) {
    if (tree->left == nullptr) {
        return tree->item;
    } else {
        return min(tree->left);
    }

}
// template <class T>
// void delete_btree(btree<T> *tree) {
//     if (tree == nullptr) {
//         return;
//     } else {
//         if (tree->left != nullptr)
//             delete_btree(tree->left);
//         if (tree->right != nullptr)
//             delete_btree(tree->right);
//         delete tree;
//     }
// }

#endif
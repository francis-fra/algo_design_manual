#ifndef _BST_H
#define _BST_H

#include <iostream>
#include "Comparator.hpp"
#include "Actor.hpp"
using namespace std;

namespace Algo {

    template<class T>
    struct BSTNode {
        BSTNode<T>(const T& v): item{v}, left{nullptr}, right{nullptr} {};
        T item;
        BSTNode<T>* left;
        BSTNode<T>* right;
        bool is_leaf_node() {
            return ((right == nullptr) && (left == nullptr));
        };
        bool contains(const T& target) {
            return (item == target);
        };
    };

    template<class T>
    class BST {
        public:

            BST<T>(bool ascending=true): head{nullptr}, Cmp{Comparator<T>{ascending}} {};

            // copy constructor
            BST<T>(const BST& B) {
                copy_all(B);
            };

            // dest is a new node, copy the left and right branch for this node
            void copy_branch(const BSTNode<T>* src, BSTNode<T>* dest) {

                if (src->left != nullptr) {
                    BSTNode<T> *leftnode = new BSTNode<T>(src->left->item);
                    dest->left = leftnode;
                    copy_branch(src->left, dest->left);
                }

                if (src->right != nullptr) {
                    BSTNode<T> *rightnode = new BSTNode<T>(src->right->item);
                    dest->right = rightnode;
                    copy_branch(src->right, dest->right);
                }
            };

            void copy_all(const BST& B) {
                // ERROR: head must be setup first, it is undefined yet...
                // otherwise it passes nothing
                // copy_branch(B.root(), this->head);
                BSTNode<T>* src = B.root();

                if (src == nullptr) {
                    this->head = nullptr;
                } else {
                    // set up the head first
                    BSTNode<T> *node = new BSTNode<T>(src->item);
                    this->head = node;
                    // now we can pass the head as it is not nullptr anymore
                    copy_branch(src, this->head);
                }
            }

            void free_all() {
                free_leaf(this->head);
                // must set to nullptr as the object still exists
                this->head = nullptr;
            };

            // move constructor
            BST<T>(BST<T>&& B) {
                this->head = B.root();
                B.head = nullptr;
            };

            // copy operator
            BST<T>& operator=(BST<T>& B) {
                free_all();
                copy_all(B);
            };

            // move operator
            BST<T>& operator=(BST<T>&& B) {
                free_all();
                this->head = B.head;
                B.head = nullptr;
                return *this;
            };

            ~BST<T>() {
                free_leaf(this->head);
                // no need to set this->head as nullptr anymore
            };

            void insert(const T& item) {

                BSTNode<T> *node = new BSTNode<T>(item);
                // set head porinting to the first item if empty
                if (isEmpty()) {
                    this->head = node;
                } else {
                    leaf_insert(this->head, node);
                }
            };

            void remove(const T& item) {
                // remember to set head to nullptr if empty

                if (isEmpty()) 
                    return;

                // find parent of the target and the target
                BSTNode<T>* target;
                BSTNode<T>* parent;
                BSTNode<T>* left_most_node;
                // target is on the left of the parent
                bool target_on_left = true;
                // target is at the head
                bool head_is_target = false;

                // check the head first
                if (this->head->item == item) {
                    // no parent for the head node
                    target = this->head;
                    head_is_target = true;
                } else {
                    // parent containing the target
                    parent = this->parent_search(this->head, item);
                    // DEBUG
                    // cout << "parent is " << parent->item << endl;
                    // cout << "left of parent is " << parent->left->item << endl;
                    // cout << "right of parent is " << parent->right->item << endl;

                    // no parent no target
                    if (parent == nullptr)
                        return;

                    // the target is either on the left or the right of the parent
                    if (parent->left == nullptr) {
                        target_on_left = false;
                        head_is_target = false;
                        target = parent->right;
                    } else if (parent->left->item == item) {
                        target_on_left = true;
                        head_is_target = false;
                        target = parent->left;
                    } else {
                        target_on_left = false;
                        head_is_target = false;
                        target = parent->right;
                    }
                }

                // parent and target were found here
                // when deleted, move the leftmost leaf in the right subtree
                // leaf node
                if (is_leaf_node(target) == true) {
                    if (head_is_target == false) {
                        if (target_on_left == true)
                            parent->left = nullptr;
                        else
                            parent->right = nullptr;
                    } else {
                        this->head = nullptr;
                    }
                    delete target; 
                    // DEBUG
                    // cout << "target on left " << target_on_left << endl;
                    // cout << "head is target " << head_is_target << endl;
                    return;
                }
                // cout << "left node? " << is_leaf_node(target) << endl;

                // one child only
                if (target->right == nullptr) {
                    if (head_is_target == false) {
                        if (target_on_left == true)
                            parent->left = target->left;
                        else
                            parent->right = target->left;
                    } else {
                        this->head = target->left;
                    }
                    delete target; 
                    return; 
                } 
                if (target->left == nullptr) {
                    if (head_is_target == false) {
                        if (target_on_left == true)
                            parent->left = target->right;
                        else
                            parent->right = target->right;
                    } else {
                        this->head = target->right;
                    }
                    delete target; 
                    return; 
                } 
                
                // there are two children
                left_most_node = this->find_leftmost_node(target->right);
                // link the target children
                // avoid recurrent links
                if (target->left != left_most_node)
                    left_most_node->left = target->left;
                if (target->right != left_most_node)
                    left_most_node->right = target->right;

                if (head_is_target == false) {
                    if (target_on_left == true)
                        parent->left = left_most_node;
                    else 
                        parent->right = left_most_node;
                } else {
                    this->head = left_most_node;
                }

                delete target;

            };

            
            T last() {
                if (isEmpty())
                    throw range_error("Tree is empty");

                return find_last(this->head);
            };

            T front() {
                if (isEmpty())
                    throw range_error("Tree is empty");

                return this->head->item;
            };

            void forEach(Actor<T>& A) {
                traverse(this->head, A);
            };

            // search the node containing the item
            BSTNode<T>* search(const T& item) {
                return search_leaf(this->head, item);
            };


            bool isEmpty() const {
                return this->head == nullptr;
            };

            BSTNode<T>* root() const {
                return head;
            };

            // note that different class name required
            template<class K>
            friend ostream& operator<<(ostream& out, const BST<K>& B);

        private:
            BSTNode<T>* head;
            Comparator<T> Cmp;
            // resursive insert
            // never call leaf_insert if current is nullptr
            void leaf_insert(BSTNode<T>* current, BSTNode<T>* node) {
                // right branch else left branch
                if (Cmp(current->item, node->item)) {
                    if (current->right == nullptr) {
                        current->right = node;
                    } else {
                        leaf_insert(current->right, node);
                    }
                } else {
                    if (current->left == nullptr) {
                        current->left = node;
                    } else {
                        leaf_insert(current->left, node);
                    }
                }
            };
            // recursive call
            void show_leaf(BSTNode<T>* N) const {
                if (N == nullptr)
                    return;
                show_leaf(N->left);
                cout << N->item << " |";
                show_leaf(N->right);
            };

            void free_leaf(BSTNode<T>* node) {
                if (node == nullptr)
                    return;
                // delete left and right
                free_leaf(node->left);
                free_leaf(node->right);
                // remove the links between parent and children
                node->left = nullptr;
                node->right = nullptr;
                // then delete itself
                delete node;
            };

            // the leftmost node
            T find_last(BSTNode<T>* node) {
                if (node->left == nullptr)
                    return node->item;
                else
                    return find_last(node->left);
            };

            BSTNode<T>* find_leftmost_node(BSTNode<T>* node) {
                if (node->left == nullptr)
                    return node;
                else
                    return find_leftmost_node(node->left);
            };

            void traverse(BSTNode<T>* Node, Actor<T>& A) {
                if (Node == nullptr)
                    return;
                traverse(Node->left, A);
                A(Node->item);
                traverse(Node->right, A);
            };

            BSTNode<T>* search_leaf(BSTNode<T>* node, const T& item) {
                if (node == nullptr) {
                    return nullptr;
                } else if (node->item == item) {
                    return node;
                } else {
                    BSTNode<T>* result = search_leaf(node->left, item);
                    if (result == nullptr) {
                        return search_leaf(node->right, item);
                    } else {
                        return result;
                    }
                }
            };

            // find the parent node pointing to the target
            BSTNode<T>* parent_search(BSTNode<T>* node, const T& item) {
                if (node == nullptr) {
                    return nullptr;
                } else if (node_contains_item(node->left, item) || 
                        (node_contains_item(node->right, item))) {
                    return node;
                } else {
                    // recursive search: left branch 
                    // return (parent_search(node->left, item) || 
                    //             (parent_search(node->right, item)));
                    BSTNode<T>* result = parent_search(node->left, item);
                    if (result == nullptr) {
                        return parent_search(node->right, item);
                    } else {
                        return result;
                    }
                }

            };

            bool node_contains_item(BSTNode<T>* node, const T& item) const {
                if (node == nullptr) {
                    return false;
                } else {
                    return node->contains(item);
                }
                // if (node == nullptr) {
                //     return false;
                // } else if (node->item == item) {
                //     return true;
                // } else {
                //     return false;
                // }
            };

            // assume true if node is nullptr
            bool is_leaf_node(BSTNode<T>* node) const {
                // return ((node->right == nullptr) && (node->left == nullptr));
                if (node == nullptr) {
                    return true;
                } else {
                    return node->is_leaf_node();
                }
            }


    }; // end BST


    template<class T>
    ostream& operator<<(ostream& out, const BST<T>& B) {
        B.show_leaf(B.root());
        return out;
    };


} // end namespace

#endif
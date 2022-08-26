#include <stdio.h>
#include <stdlib.h>
#include "btree.h"

// create binary node with initialization
// a node is a component in a binary tree
// returns the pointer to the node
btree *create_bnode(btree* parent, itemType item) {

    btree *tree = malloc(sizeof(btree));
    tree->item = item;
    tree->left = NULL;
    tree->right = NULL;
    tree->parent = parent;
    return tree;
}

// insert item to an existing binary tree
void insert_btree(btree **tree, btree *parent, itemType item) {

    if (*tree == NULL) {
        btree *node = create_bnode(parent, item);
        *tree = node;
    } else if (item > (*tree)->item) {
        // address of the right tree
        insert_btree(&((*tree)->right), *tree, item);
    } else {
        // address of the left tree
        insert_btree(&((*tree)->left), *tree, item);
    }

}

// apply (pointer) function f to each leaf node
void traverse_btree(btree *tree, void (*f)(btree *)) {

    if (tree != NULL) {
        traverse_btree(tree->left, f);
        f(tree);
        traverse_btree(tree->right, f);
    }

}

// transforming functions of the tree
void print(btree *tree) {
    if (tree != NULL)
        printf("%d\n", tree->item);
}

void dble(btree *tree) {
    if (tree != NULL)
        tree->item *= 2;
}

// returns the leaf node containing the target
btree *search_tree(btree *tree, itemType item) {

  if (tree == NULL) {
    return NULL;
  } else if (tree->item == item) {
    return tree;
  } else if (tree->item < item) {
    return search_tree(tree->right, item);
  } else {
    return search_tree(tree->left, item);
  }
}

// find the minimum value (the leftmost leaf node)
itemType minTreeVal(btree *tree) {

    if (tree == NULL) {
        return -1;
    }
    btree *p = tree;
    while (p->left != NULL) {
       p = p->left;
    }
    return p->item;
}


// error: No copy!!
void copy_tree(btree *b, btree *src) {
  b = src;
}


void copy_btree(btree **b, btree *src) {
  *b = src;
}
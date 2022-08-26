#include <stdio.h>
#include <stdlib.h>
#include "include/btree.h"

bnode*
create_bnode(itemType item) {
    bnode* bnp = malloc(sizeof(bnode));
    bnp->item = item;
    bnp->parent= NULL;
    bnp->left= NULL;
    bnp->right= NULL;
    return bnp;
}

// head is just a pointer to exiting node: no need to allocate space
btree
create_btree() {
    btree tree = NULL;
    return tree;
}

// insert empty node to root of binary tree
btree
insert_bnode(btree root, bnode* n) {

    if (root == NULL) {
        // tree->root = n;
        root = n;
        return root;
    }

    if (n->item < root->item) {
        if (root->left == NULL) {
            root->left = n;
            n->parent = root;
        } else {
            insert_bnode_to_branch(root->left, root, n);
        }
    } else {
        if (root->right == NULL) {
            root->right = n;
            n->parent = root;
        } else {
            insert_bnode_to_branch(root->right, root, n);
        }
    }
    return root;
}

// insert empty node to branch of binary tree
// current is a valid bnode - must not be NULL
void
insert_bnode_to_branch(bnode* current, bnode* parent, bnode* n) {
    if (n->item < current->item) {
        if (current->left == NULL) {
            current->left = n;
            n->parent = current;
        } else {
            insert_bnode_to_branch(current->left, current, n);
        }
    } else {
        if (current->right == NULL) {
            current->right = n;
            n->parent = current;
        } else {
            insert_bnode_to_branch(current->right, current, n);
        }
    }

}

void
print_btree(btree tree) {
    if (tree != NULL) {
        print_btree(tree->left);
        printf("%d ", tree->item);
        print_btree(tree->right);
    }
    // printf("\n");
}
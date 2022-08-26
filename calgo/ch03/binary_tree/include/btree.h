#ifndef __BTREE_H__
#define __BTREE_H__

typedef int itemType;

typedef struct bnode{
    itemType item;
    struct bnode *parent;
    struct bnode *left;
    struct bnode *right;
} bnode;

typedef bnode* btree;

// typedef struct btree {
//     bnode* root;
// } btree;

// typedef bnode* btree;

bnode* create_bnode(itemType item);
btree create_btree();
// void delete_btree(btree **tree, itemType item);

btree insert_bnode(btree root, bnode* n);
void insert_bnode_to_branch(bnode* current, bnode* parent, bnode* n);
// void traverse_btree(btree *tree, void (*f)(btree *));
void print_btree(btree tree);
// void dble(btree *b);

// btree *search_tree(btree *tree, itemType item);
// itemType minTreeVal(btree *b);
// itemType maxTreeVal(btree *b);

// void copy_tree(btree *b, btree *c);
// void copy_btree(btree **b, btree *c);
#endif
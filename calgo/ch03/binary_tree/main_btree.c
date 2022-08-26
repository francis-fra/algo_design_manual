#include <stdio.h>
#include <stdlib.h>
#include "include/btree.h"

int
main()
{
    itemType item=5;
    bnode* bn5 = create_bnode(item);
    bnode* bn3 = create_bnode(3);
    bnode* bn1 = create_bnode(1);
    bnode* bn10 = create_bnode(10);

    btree root = create_btree();
    // btree root;

    root = insert_bnode(root, bn5);
    // root = insert_bnode(root, bn3);
    root = insert_bnode(root, bn1);
    root = insert_bnode(root, bn10);

    print_btree(root);

    free(bn5);
    free(bn3);
    free(bn10);
    free(bn1);

}
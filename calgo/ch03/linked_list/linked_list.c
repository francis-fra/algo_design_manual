// #include <linked_list.h>
#include "include/linked_list.h"
#include <stdio.h>
#include <stdlib.h>

// craete head only
list 
create_list() {
    list head = malloc(sizeof(node));
    return head;
}

node*
create_node(itemType item) {
    node* pn = malloc(sizeof(node));
    pn->item = item;
    return pn;
}

void
insert_item(list lst, itemType item) {
    node* pn = lst;
    while(pn->next) {
        pn = pn->next;
    }
    node* new_node = create_node(item);
    pn->next = new_node;
}

void
insert_node(list lst, node* n) {
    node* pn = lst;
    while(pn->next) {
        pn = pn->next;
    }
    pn->next = n;
}

void
print_node(node *node) {
    printf("%d ", node->item);
}

void
print_list(list lst) {
    node* pn = lst;
    while(pn->next) {
        pn = pn->next;
        print_node(pn);
    }
}
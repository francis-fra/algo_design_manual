#include "queue.h"
#include <stdio.h>
#include <stdlib.h>

// ------------------------------------------------------------
// queue
// ------------------------------------------------------------
// craete head only
// head has no item, first item is located the node after head
queue
create_queue() {
    queue head = malloc(sizeof(node));
    head->next = NULL;
    return head;
}

node*
create_node(itemType item) {
    node* pn = malloc(sizeof(node));
    pn->item = item;
    pn->next = NULL;
    return pn;
}

// FIFO
void
insert_queue_item(queue lst, itemType item) {
    node* new_node = create_node(item);
    insert_queue_node(lst, new_node);
}

void
insert_queue_node(queue lst, node* n) {
    node* pn = lst;
    while(pn->next) {
        pn = pn->next;
    }
    pn->next = n;
}


node* 
take_queue_node(queue lst) {
    // check if any 
    if (lst->next == NULL) {
        // printf("Empty");
        return NULL;
    } else {
        node *first = lst->next;
        lst->next = first->next;
        return first;
    }
}

void
print_node(node *node) {
    printf("%d ", node->item);
}

void
print_queue(queue lst) {
    node* pn = lst;
    while(pn->next) {
        pn = pn->next;
        print_node(pn);
    }
}

// ------------------------------------------------------------
// stack

stack
create_stack() {
    stack head = malloc(sizeof(node));
    head->next = NULL;
    return head;
}

// LIFO
void
insert_stack_item(stack lst, itemType item) {
    node* new_node = create_node(item);
    insert_stack_node(lst, new_node);
}

void
insert_stack_node(stack lst, node* n) {
    // node* pn = lst;
    n->next = lst->next;
    lst->next = n;
}


// TODO
node* 
take_stack_node(stack lst) {
    // check if any 
    if (lst->next == NULL) {
        return NULL;
    } else {
        node *first = lst->next;
        lst->next = first->next;
        return first;
    }
}


void
print_stack(stack lst) {
    node* pn = lst;
    while(pn->next) {
        pn = pn->next;
        print_node(pn);
    }
}
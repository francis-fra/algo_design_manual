#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

/*
typedef int itemType; 

typedef struct list {
    itemType item;
    struct list *next;
} list;
*/

// search and delete item
void delete_list(list **lst, itemType item) {
    // find item
    list *parent = predecessor(*lst, item);
    // remove the node
    if (parent != NULL) {
        list *child = parent->next;
        parent->next = child->next;
        free(child);
    } 
    else {
        // NULL can mean NOT FOUND or the HEAD
        if ((*lst)->item == item) {
            // need to free the first node
            list *second = (*lst)->next; // second node 
            free(*lst);
            *lst = second;
        } 
    }
}

// return the first node which contains the item
list *predecessor(list *lst, itemType item) {
    list* p = lst;
    list* parent = NULL;

    while (p != NULL) {
        if (p->item == item) {
            return parent;
        }
        else {
            parent = p;
            p = p ->next;
        }
    }
    return NULL;

}


// insert item at the front of the list
void insert_list(list **lst, itemType item) {

    list *p;
    p = malloc(sizeof(list));
    p->item = item;
    p->next = *lst;
    // lst is the pointer to (the pointer of struct)
    *lst = p;
}


// create and initialize list
list* create_list(itemType item) {

    list *p;
    p = malloc(sizeof(list));
    p->item = item;
    p->next = NULL;
    return p;
}

// print every node in the linked list 
void traverse_list2(list *lst) {
   list *p = lst;
   while(p != NULL) {
       printf("%d\n", p->item);
       p = p->next;
   }
}

// delete linked list
void free_list(list *lst) {
   list *p = lst;
   while(p != NULL) {
       list *next = p->next;
       free(p);
       p = next;
   }
}

void traverse_list(list *lst, void (*f)(list*)) {
    list *p = lst;
    while(p != NULL) {
       list *next = p->next;
       f(p);
       p = next;
    }
}

// transform functions
void print_item(list *lst) {
    printf("%d\n", lst->item);
}

void free_item(list *lst) {
    free(lst);
}

void inc_item(list *lst) {
    lst->item += 1;
}


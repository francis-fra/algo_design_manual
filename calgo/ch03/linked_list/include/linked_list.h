#ifndef __LINKED_LIST__
#define __LINKED_LIST__
typedef int itemType; 

typedef struct node {
    itemType item;
    struct node* next;
} node;

typedef node* list;

list create_list();
node* create_node(itemType item);
void insert_item(list lst, itemType item);
void insert_node(list lst, node* n);
// void traverse_list2(list *lst);
// void free_list(list *lst);
// void traverse_list(list *lst, void (*f)(list*));
void print_node(node *node);
void print_list(list lst);
// void free_item(list *lst);
// void inc_item(list *lst);
// list *predecessor(list *lst, itemType item);
// void delete_list(list **lst, itemType item);

#endif
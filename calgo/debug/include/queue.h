#ifndef __QUEUE__
#define __QUEUE__

typedef int itemType; 

typedef struct node {
    itemType item;
    struct node* next;
} node;

typedef node* queue;

queue create_queue();
node* create_node(itemType item);
void insert_item(queue lst, itemType item);
void insert_node(queue lst, node* n);
void print_node(node *node);
void print_queue(queue lst);

#endif
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
void insert_queue_item(queue lst, itemType item);
void insert_queue_node(queue lst, node* n);
void print_node(node *node);
void print_queue(queue lst);
// itemType take_item(queue lst);
node* take_queue_node(queue lst);


typedef node* stack;

stack create_stack();
// node* create_node(itemType item);
void insert_stack_item(stack lst, itemType item);
void insert_stack_node(stack lst, node* n);
void print_stack(stack lst);

// itemType take_item(stack lst);
node* take_stack_node(stack lst);

#endif
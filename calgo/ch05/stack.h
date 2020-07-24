#include <stdbool.h>

typedef int itemType; 

typedef struct sknode {
    itemType item;
    struct sknode *next;
} sknode;

typedef struct stack {
    int size;
    int capacity;
    sknode *root;
} stack;

stack *create_stack(int capacity);
bool push(stack *s, itemType item);
itemType pop(stack *s);
itemType peek(stack *s);
void traverse_stack(stack *s, void (*f) (sknode*));
void print_item(sknode *node);

  


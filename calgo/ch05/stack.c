#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "stack.h" 

bool push(stack *s, itemType item) {

    // insert item to the top
    if (s->size < s->capacity) {

        sknode *p;
        p = malloc(sizeof(sknode));
        p->item = item;
        // point to the current sknode 
        p->next = s->root;
        s->root = p;
        s->size++;
    }
}

itemType peek(stack *s) {

    if (s->size > 0) {
        return s->root->item;
    } 

}


itemType pop(stack *s) {

    if (s->size > 0) {
        itemType item = s->root->item;
        
        sknode *top = s->root;
        sknode *next = top->next;
        s->root = next;
        s->size--;
        free(top);
        return item;
    }

}

stack *create_stack(int capacity) {

    stack *p = malloc(sizeof(stack));
    p->size = 0;
    p->capacity = capacity;
    p->root = NULL;
    return p;
}

void print_item(sknode *node) {
    printf("%d\n", node->item);
}
 

void traverse_stack(stack *s, void (*f) (sknode*)) {

    sknode *node = s->root;
    while (node != NULL) {
        f(node);
        node = node->next;
    }

}



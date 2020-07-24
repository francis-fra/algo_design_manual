#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(void) {
    
    printf("testing\n");
    // create am empty list
    list *lst = malloc(sizeof(list));
    free(lst);

    // create an initial list
    list *newlist = create_list(4);
    //printf("%d\n", newlist->item);


    // insert
    // pass as reference to modify
    insert_list(&newlist, 10);
    insert_list(&newlist, 100);
    //traverse_list(newlist);
    traverse_list(newlist, &print_item);
    printf("Add one...\n");
    traverse_list(newlist, &inc_item);
    traverse_list(newlist, &print_item);

    // find predecessor
    /* list *p = predecessor(newlist, 11); */
    /* printf("previous item = %d\n", p->item); */
    // delete this item
    printf("Delete item\n");
    delete_list(&newlist, 101);
    delete_list(&newlist, 5);
    delete_list(&newlist, 15);
    traverse_list(newlist, &print_item);

    traverse_list(newlist, &free_item);

    /* free_list(newlist); */
    return 0;
}

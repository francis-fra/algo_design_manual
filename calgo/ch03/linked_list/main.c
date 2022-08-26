#include <stdio.h>
#include <stdlib.h>
#include "include/linked_list.h"

int
main()
{
    itemType item=5;
    node* n5 = create_node(item);
    node* n3 = create_node(3);

    // print_node(n);
    list head = create_list();
    insert_node(head, n5);
    insert_node(head, n3);
    insert_item(head, 9);

    print_list(head);

    free(n5);
    free(n3);
    free(head);

}
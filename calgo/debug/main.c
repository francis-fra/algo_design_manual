#include <stdio.h>
#include "misc.h"
#include "queue.h"

void
main() {
    int arr[6] = {3,4,5,6,7,8};
    queue q = create_queue();
    node *n = create_node(9);
    // print_node(n);
    insert_node(q, n);
    print_queue(q);

    print_array(arr, 6);
}
#include <unistd.h>     // getopt
#include <stdio.h>
#include <stdlib.h>
// #include <graph.h>
// #include <weighted_graph.h>
// #include <queue.h>
#include <string.h>
#include "misc.h"
#include <search.h>

void
generate_subsets(int n) {

    int a[5];
    backtrack(a, 0, n, &is_all_loop, &construct_binary_candidates,
            &make_move, &process_solution, &unmake_move);

}

int 
main() {

    generate_subsets(3);
    exit(EXIT_SUCCESS);

}

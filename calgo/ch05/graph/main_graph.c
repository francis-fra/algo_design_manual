// ./main_graph < input_file

#include <unistd.h>     // getopt
#include <stdio.h>
#include <stdlib.h>
#include <graph.h>
#include <weighted_graph.h>
#include <queue.h>
#include <string.h>
// new
#include "misc.h"


void
dotest() {
    // DEBUG
    int arr[6] = {3,4,5,6,7,8};
    // print_array(arr, 6);
    queue q = create_queue();
    stack s = create_stack();
    for (int k=0; k<6; k++) {
        insert_queue_item(q, arr[k]);
        insert_stack_item(s, arr[k]);
    }
    // print_stack(s);
    // print_queue(q);
    printf("queue\n");
    node* n;
    while (n = take_queue_node(q)) {
        printf("%d\n", n->item);
    }

    printf("stack\n");
    while (n = take_stack_node(s)) {
        printf("%d\n", n->item);
    }
}

void find_path_test(Graph *g, int u, int v, char* method) {
    bool found = find_path(g, u, v, method);
}

void edge_test() {
    Edge* head = make_undirected_edge(1, 1);
    Edge* p1 = make_undirected_edge(2, 1);
    Edge* p2 = make_undirected_edge(3, 1);
    head->next = p1;
    p1->next = p2;
    p2->next = NULL;
    print_edge_link(head);
    head = remove_edge_link(head, 7);
    print_edge_link(head);
}

void
span_tree_test(Graph* g, int v) {
    // prim(g, v);
    kruskal(g, v);
}

void
shortest_path_test(Graph *g, int u, int v) {
    shortest_path(g, u, v);
}


void
union_test(Graph* g) {
    Set_union s; 
    Edge_pair e[MAX_EDGES];

    init_union(g, &s);
    // loop all edges and update
    to_edge_array(g, e);

    qsort(&e, g->numEdge, sizeof(Edge_pair), &edge_pair_cmp);
    for (int k=0; k < g->numEdge; k++) {
        printf("%d -> %d (%d)\n", e[k].x, e[k].y, e[k].weight);
    }
}

int
main(int argc, char *argv[]) {

    bool directed = false;
    bool weighted = false;
    Graph *g;
    int c;
    char* method = "bfs";
    while ((c = getopt (argc, argv, "dws:")) != -1)
        switch (c)
        {
            case 'd':
                directed = true;
                break;
            case 'w':
                weighted = true;
                break;
            case 's':
                method = optarg;
                break;
            default:
                abort();
        }

    if (optind < argc) {
        g = fread_graph(argv[optind], directed, weighted);
    } else {
        g = read_graph(directed, weighted);
    }

    // span_tree_test(g, 0);
    shortest_path_test(g, 1, 4);
    // union_test(g);
    // print_graph(g);





    // find_path_test(g, 2, 1, "dfs");
    // printf("\n");
    // find_path_test(g, 1, 4, "dfs");


    // if (strcmp(method,"bfs") == 0) {
    //     bfs(g, 1);
    //     // 1 2 5 6 3 0 4
    // } else {
    //     dfs(g, 1);
    //     // 1 6 5 4 3 0 2
    // }

    // print_array(gdata->parent, g->numVertex);
    // printf("----------- %s -----------\n", method);
    // find_path(g, 1, 0, method);
    // twocolor(g);

    // Graph copy;
    // memcpy(&copy, g, sizeof(Graph));
    // // print_graph(g);
    // g = delete_edge(g, 3);
    // GData *gdata = dfs(g, 4, &dummy_edge, &dummy_vertex, &print_vertex);
    // gdata = dfs(g, 4, &dummy_edge, &dummy_vertex, &count_vertex);
    // print_array(gdata->data, g->numVertex);


    // print_graph(g);
    // print_graph(&copy);

    // print_graph(g);
    // printf("----------- %s -----------\n", method);
    // bool found = find_path(g, 1, 2, method);
    // printf("\n");
    // printf("found? %d\n", found);

    // FIXME
    // articulate(g);
    
    // dotest();
    // pass!!
    // edge_test();



    exit(EXIT_SUCCESS);
}
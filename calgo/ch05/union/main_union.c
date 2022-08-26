#include <stdlib.h>
#include <stdio.h>
#include "misc.h"

#define MAX_VERTEX 10

void
slow_connect(int u, int v, int p[]) {
    if (p[u] == p[v]) return; 
    // change all parent to new parent
    int old = p[u];
    for (int k=0; k<MAX_VERTEX; k++) {
        if (p[k] == old) p[k] = p[v];
    }
    printf("%d %d  ", u, v);
    print_array(p, MAX_VERTEX);
}

void
quick_connect(int u, int v, int p[]) {
    // find parent of v
    int v_parent = p[v];
    while (v_parent != p[v_parent]) {
        v_parent = p[v_parent];
    }
    // find parent of v
    int u_parent = p[u];
    while (u_parent != p[u_parent]) {
        u_parent = p[u_parent];
    }
    // parent of u becomes parent of v
    p[u_parent] = v_parent;

    printf("%d %d  ", u, v);
    print_array(p, MAX_VERTEX);
}

void
read_edges(char* filename, int p[]) {
    int u, v;
    int parent;
    FILE* fp = fopen(filename, "r");
    while(fscanf(fp, "%d %d", &u, &v) > 0) {
        // slow_connect(u, v, p);
        quick_connect(u, v, p);
    }

    fclose(fp);
}



int
main() {

    // initialize
    int p[MAX_VERTEX];
    for (int k=0; k<MAX_VERTEX; k++) {
        p[k] = k;
    }
    read_edges("data.txt", p);
    // print_array(p, MAX_VERTEX);

}
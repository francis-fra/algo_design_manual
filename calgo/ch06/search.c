#include <search.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <misc.h>

// k is the current step: populating a[k]
void
backtrack(int a[], int k, int input, 
            bool(* is_a_solution) (int[], int, int),
            void(* construct_candidates) (int[], int , int , int[], int*),
            void(* make_move) (int[], int, int),
            void(* process_solution) (int[], int, int),
            void(* unmake_move) (int[], int, int)) {

    int c[MAXCANDIDATES];
    int ncandidates;

    if (is_a_solution(a, k, input)) {
        process_solution(a, k, input);
        // printf("k = %d: ", k);
        print_array(a, input);
    } else {
        // inc k for the next permutation
        k = k+1;
        // fill c array
        construct_candidates(a, k, input, c, &ncandidates);
        // loop for each candidate
        for (int j=0; j<ncandidates; j++) {
            // a[k] = c[j];
            a[k-1] = c[j];
            make_move(a, k, input);
            // recursion
            backtrack(a, k, input, is_a_solution, construct_candidates,
                make_move, process_solution, unmake_move);
            unmake_move(a, k, input);
        }
    }
}

bool
is_all_loop(int a[], int k, int input) {
    // stop the loop when k reached the limit: imput
    return k == input;
}

void
construct_binary_candidates(int a[], int k, int n, int c[], int* ncandidates) {
    // try only true/false
    c[0] = true;
    c[1] = false;
    // num filled
    *ncandidates = 2;
}

void 
process_solution(int a[], int k, int input) {
    int i;
    // print set
    // a: 1 0 1 -> {1 3}
    printf("{");
    for (i=0; i<k; i++) {
        if (a[i] == true) printf(" %d", i+1);
    }
    printf(" }\n");

}

void make_move(int a[], int k, int input){}
void unmake_move(int a[], int k, int input){}



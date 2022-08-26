#ifndef __SEARCH_H__
#define __SEARCH_H__

#include <stdbool.h>

typedef int Data;
#define MAXCANDIDATES 100

// void backtrack(int a[], int k, Data intput);
void backtrack(int a[], int k, int input, 
            bool(* is_a_solution) (int[], int, int),
            void(* construct_candidates) (int[], int , int , int[], int*),
            void(* make_move) (int[], int, int),
            void(* process_solution) (int[], int, int),
            void(* unmake_move) (int[], int, int));

bool is_all_loop(int a[], int k, int input);
void construct_binary_candidates(int a[], int k, int n, int c[], int* ncandidates);
void process_solution(int a[], int k, int input);
void make_move(int a[], int k, int input);
void unmake_move(int a[], int k, int input);

#endif
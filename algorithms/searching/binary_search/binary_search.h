#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stdio.h>
#include <assert.h>

#define arr_size(arr) sizeof(arr) / sizeof(int)

// Iterative implementation
int binary_search(int *arr, int val, int len);
// Recursive implementation
int binary_search_rec(int *arr, int val, int l, int r);

// Tests
void test_binary_search();
void test_binary_search_rec();
void run_all_tests();

#endif //BINARY_SEARCH_H

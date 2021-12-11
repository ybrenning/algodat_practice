/**
 * @author Yannick Brenning
 * @date 08.12.2021
 * @brief Implementation of binary search
 */

#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <stdio.h>
#include <assert.h>

#define arr_size(arr) sizeof(arr) / sizeof(int)

// Iterative implementation
int binary_search(int *arr, int val, unsigned int len);
// Recursive implementation
int binary_search_rec(int *arr, int val, unsigned int l, unsigned int r);

// Tests
void test_binary_search();
void test_binary_search_rec();
void run_all_tests();

#endif //BINARY_SEARCH_H

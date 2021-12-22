/**
 * @author Yannick Brenning
 * @date 23.12.2021
 * @brief Implementation of merge sort
 */

#ifndef MERGE_SORT_H
#define MERGE_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define ARR_LEN 10
#define NUM_OF_TESTS 5

// Generate a randomized list of int between 1 and 100
void create_list(int *arr);
// Merge two sorted arrays
void merge(int *arr, unsigned int l, unsigned int m, unsigned int r);
// Implementation of merge sort
void merge_sort(int *arr, unsigned int l, unsigned int r);
// Testing
void test_merge_sort();

#endif //MERGE_SORT_H

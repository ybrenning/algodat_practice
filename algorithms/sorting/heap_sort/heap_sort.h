/**
 * @author Yannick Brenning
 * @date 21.12.2021
 * @brief Implementation of heapsort using min-heapify
 */

#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define ARR_LEN 10
#define NUM_OF_TESTS 5

// Generate a randomized list of int between 1 and 100
void create_list(int *arr);
// Implementation of heapsort
void heap_sort(int *arr, int len);

// Testing
void test_heap_sort();

#endif //HEAP_SORT_H

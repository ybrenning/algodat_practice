/**
 * @author Yannick Brenning
 * @date 10.12.2021
 * @brief Implementation of insertion sort
 */

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

#define ARR_LEN 10
#define NUM_OF_TESTS 5

// Generate a randomized list of int between 1 and 100
void create_list(int *arr);
// Implementation of insertion sort
void insertion_sort(int *arr, unsigned int len);
// Testing
void test_insertion_sort();

#endif //INSERTION_SORT_H

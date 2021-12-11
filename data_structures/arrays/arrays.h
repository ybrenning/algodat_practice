/**
 * @author Yannick Brenning
 * @date 21.11.2021
 * @brief Implementation of a dynamic array data structure
 */

#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define DEF_CAPACITY 16
#define RESIZE_FACTOR 2

typedef struct dynamic_array {
    int size;
    int capacity;
    int *data;
} DArray;

// Check if pointer address is valid
void check_address(void *address);
// initialize the capacity of the darray
int init_capacity(int capacity);
// Grow the capacity based on the RESIZE_FACTOR
int darray_grow(int capacity);
// Shrink the capacity based on the RESIZE_FACTOR
int darray_shrink(int capacity);
// Initialize the darray
DArray *darray_init(int capacity);
// Free darray memory
void darray_destroy(DArray **darray);
// Check if the darray is empty
bool darray_isempty(DArray *darray);
// Get value at specific index in darray
int darray_get(DArray *darray, int index);
// Push elem to the end of the darray
void darray_push(DArray *darray, int val);
// Remove last elem of the darray
int darray_pop(DArray *darray);
// Insert elem at index in darray
void darray_insert(DArray *darray, int val, int index);
// Delete elem at index in darray
int darray_delete(DArray *darray, int index);
// Print content of darray onto console
void darray_print(DArray *darray);
// Linear search for val in the darray
int darray_find(DArray *darray, int val);

// Tests
void test_darray_init();
void test_darray_destroy();
void test_darray_isempty();
void test_darray_push();
void test_darray_get();
void test_darray_pop();
void test_darray_insert();
void test_darray_delete();
void test_darray_find();
void run_all_tests();

#endif //ARRAYS_H

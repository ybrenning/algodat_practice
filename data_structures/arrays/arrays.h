/**
 * @author Yannick Brenning
 * @date 21.11.2021
 * @brief Implementation of a dynamic array data structure
 */

#ifndef ARRAYS_H
#define ARRAYS_H

#include <stdio.h>
#include <stdbool.h>

#define DEF_CAPACITY ((size_t) 1 << 4)
#define RESIZE_FACTOR (1 << 1)

typedef struct dynamic_array {
    size_t size;
    size_t capacity;
    int *data;
} darray_t;

// Initialize the capacity of the darray
size_t init_capacity(int capacity);
// Grow the capacity based on RESIZE_FACTOR
size_t darray_grow(size_t capacity);
// Shrink the capacity based on RESIZE_FACTOR
size_t darray_shrink(size_t capacity);

// Initialize the darray
darray_t *darray_init(int capacity);
// Free darray memory
void darray_destroy(darray_t **darray);
// Check if the darray is empty
bool darray_isempty(darray_t *darray);
// Get value at specific index in darray
int darray_get(darray_t *darray, int index);
// Push elem to the end of the darray
void darray_push(darray_t *darray, int val);
// Remove and return last elem of the darray
int darray_pop(darray_t *darray);
// Insert elem at index in darray
bool darray_insert(darray_t *darray, int val, int index);
// Delete and return elem at index in darray
int darray_delete(darray_t *darray, int index);
// Print content of darray onto console
void darray_print(darray_t *darray);
// Linear search for val in the darray
int darray_find(darray_t *darray, int val);

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

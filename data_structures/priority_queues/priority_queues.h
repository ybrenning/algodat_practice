/**
 * @author Yannick Brenning
 * @date 19.12.2021
 * @brief Implementation of priority queues using max heap
 */

#ifndef PRIORITY_QUEUES_H
#define PRIORITY_QUEUES_H

#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE ((size_t) 1 << 6)

typedef struct max_heap_t {
    size_t size;
    size_t capacity;
    int data[MAX_SIZE];
} max_heap_t;

// Initialize new heap
max_heap_t *heap_init();
// Deallocate memory of heap
void heap_destroy(max_heap_t **heap);
// Get max value in heap
int heap_get_max(max_heap_t *heap);
// get size of heap
size_t heap_get_size(max_heap_t *heap);
// Check if heap is empty
bool heap_is_empty(max_heap_t *heap);
// Insert value into the heap
bool heap_insert(max_heap_t *heap, int val);
// Get max value (first value) of heap
int heap_extract_max(max_heap_t *heap);

// Moves item from bottom of heap upwards
// until heap is rearranged. Used for insertions.
void heapify_up(max_heap_t *heap);
// Moves item from top of heap downwards
// until heap is rearranged.
// Used for deletion of top heap element.
void heapify_down(max_heap_t *heap);

// Testing
void test_heap_init();
void test_heap_get_max();
void test_heap_get_size();
void test_heap_is_empty();
void test_heap_insert();
void test_heap_extract_max();
void run_all_tests();

#endif //PRIORITY_QUEUES_H

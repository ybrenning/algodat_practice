/**
 * @author Yannick Brenning
 * @date 19.12.2021
 * @brief Implementation of priority queues using max heap
 */

#ifndef PRIORITY_QUEUES_H
#define PRIORITY_QUEUES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include <assert.h>

#define MAX_SIZE 1000

typedef struct max_heap_t {
    unsigned int size;
    unsigned int capacity;
    int data[MAX_SIZE];
} max_heap_t;

max_heap_t *heap_init();
void heap_destroy(max_heap_t *heap);
int heap_get_max(max_heap_t *heap);
unsigned int heap_get_size(max_heap_t *heap);
bool heap_is_empty(max_heap_t *heap);
void heap_insert(max_heap_t *heap, int val);
int heap_extract_max(max_heap_t *heap);

// Moves item from bottom of heap upwards
// until heap is rearranged - used for insertions
void heapify_up(max_heap_t *heap);
// Moves item from top of heap downwards
// until heap is rearranged - used for deletion
// of top heap element
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

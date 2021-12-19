#ifndef PRIORITY_QUEUES_H
#define PRIORITY_QUEUES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_SIZE 1000

typedef struct max_heap_t {
    unsigned int size;
    unsigned int capacity;
    int data[MAX_SIZE + 1];
} max_heap_t;

max_heap_t *heap_init();
void heap_destroy(void *heap);
int heap_get_max(max_heap_t *heap);
unsigned int heap_get_size(max_heap_t *heap);
bool heap_is_empty(max_heap_t *heap);
void heap_insert(max_heap_t *heap, int val);
int heap_extract_max(max_heap_t *heap);

#endif //PRIORITY_QUEUES_H

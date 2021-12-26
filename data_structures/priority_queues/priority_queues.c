/**
 * @author Yannick Brenning
 * @date 19.12.2021
 * @brief Implementation of priority queues using max heap
 */

#include "priority_queues.h"

void swap(int *item_1, int *item_2) {
    int temp = *item_1;
    *item_1 = *item_2;
    *item_2 = temp;
}

unsigned int get_left_child_index(unsigned int index) {
    return (index * 2) + 1;
}

unsigned int get_right_child_index(unsigned int index) {
    return (index * 2) + 2;
}

int get_parent_index(int index) {
    return (index - 1) / 2;
}

bool has_left_child(max_heap_t *heap, unsigned int index) {
    return get_left_child_index(index) < heap->size;
}

bool has_right_child(max_heap_t *heap, unsigned int index) {
    return get_right_child_index(index) < heap->size;
}

bool has_parent(max_heap_t *heap, int index) {
    return get_parent_index(index) >= 0;
}

int get_left_child(max_heap_t *heap, unsigned int index) {
    return heap->data[get_left_child_index(index)];
}

int get_right_child(max_heap_t *heap, unsigned int index) {
    return heap->data[get_right_child_index(index)];
}

int get_parent(max_heap_t *heap, unsigned int index) {
    return heap->data[get_parent_index(index)];
}

void heapify_up(max_heap_t *heap) {
    int i = ((int) heap->size) - 1;
    while (has_parent(heap, i) && get_parent(heap, i) < heap->data[i]) {
        // While the parent has a lower val (e.g. the heap is out of order)
        // swap the parent val with the current val, until we reach the root
        // e.g. the element without a parent
        swap(&heap->data[get_parent_index(i)], &heap->data[i]);
        // Set the current position to the old parent and continue
        i = get_parent_index(i);
    }
}

void heapify_down(max_heap_t *heap) {
    unsigned int i = 0;
    // While current index has a left child
    while (has_left_child(heap, i)) {
        // Get the index of the larger child
        unsigned int larger_child_index = get_left_child_index(i);
        if (has_right_child(heap, i) && get_right_child(heap, i) > get_left_child(heap, i))
            larger_child_index = get_right_child_index(i);

        // If our current element is larger than the larger child,
        // then we have the correct placement in the heap
        if (heap->data[i] > heap->data[larger_child_index]) break;
        // Otherwise, swap the current element with the larger child
        else swap(&heap->data[i], &heap->data[larger_child_index]);

        i = larger_child_index;
    }
}

max_heap_t *heap_init() {
    max_heap_t *heap = (max_heap_t *) malloc(sizeof(max_heap_t));
    assert(heap);
    heap->size = 0;
    heap->capacity = MAX_SIZE;

    return heap;
}

void heap_destroy(max_heap_t *heap) {
    free(heap);
}

int heap_get_max(max_heap_t *heap) {
    if (heap_is_empty(heap)) return -1;
    else return heap->data[0];
}

unsigned int heap_get_size(max_heap_t *heap) {
    return heap->size;
}

bool heap_is_empty(max_heap_t *heap) {
    return heap_get_size(heap) == 0;
}

void heap_insert(max_heap_t *heap, int val) {
    if (heap->size == heap->capacity) return;

    // Insert the new val at the end
    // and increase heap size
    heap->data[heap->size++] = val;

    // Rearrange the heap
    heapify_up(heap);
}

int heap_extract_max(max_heap_t *heap) {
    if (heap_is_empty(heap)) return INT_MAX;

    int retval = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    // Rearrange the heap
    heapify_down(heap);

    return retval;
}

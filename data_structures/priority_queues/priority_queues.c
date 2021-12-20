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

int get_left_child_index(unsigned int index) {
    return (index * 2) + 1;
}

int get_right_child_index(unsigned int index) {
    return (index * 2) + 2;
}

int get_parent_index(unsigned int index) {
    return (index - 1) / 2;
}

void heapify_up(max_heap_t *heap) {
    unsigned int i = heap->size - 1;
    while (i != 0 && heap->data[get_parent_index(i)] < heap->data[i]) {
        // While the parent has a lower val (e.g. the heap is out of order)
        // swap the parent val with the current val, until we reach the root
        swap(&heap->data[get_parent_index(i)], &heap->data[i]);
        // Set the current position to the old parent and continue
        i = get_parent_index(i);
    }
}

void heapify_down(max_heap_t *heap) {
    unsigned int i = 0;
    // While current index has a left child
    while (get_left_child_index(i) < heap->size) {
        // Get the index of the larger child
        unsigned int larger_child_index = get_left_child_index(i);
        if (get_right_child_index(i) < heap->size
        && heap->data[get_right_child_index(i)] > heap->data[get_left_child_index(i)]) {
            larger_child_index = get_right_child_index(i);
        }

        printf("%d\n", i);
        if (heap->data[i] > heap->data[larger_child_index]) break;
        else swap(&i, &larger_child_index);

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

void heap_destroy(void *heap) {
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

// Testing
void test_heap_init() {
    max_heap_t *heap = heap_init();
    assert(heap);
    assert(heap->size == 0);
    assert(heap->capacity == MAX_SIZE);

    heap_destroy(heap);
}

void test_heap_get_max() {
    max_heap_t *heap = heap_init();
    assert(heap_get_max(heap) == -1);

    heap->data[0] = 1;
    heap->size++;
    assert(heap_get_max(heap) == 1);

    heap->data[0] = 2;
    heap->data[1] = 1;
    heap->size++;
    assert(heap_get_max(heap) == 2);

    heap_destroy(heap);
}

void test_heap_get_size() {
    max_heap_t *heap = heap_init();
    assert(heap_get_size(heap) == 0);

    heap_insert(heap, 1);
    assert(heap_get_size(heap) == 1);

    heap_insert(heap, 2);
    assert(heap_get_size(heap) == 2);

    heap_destroy(heap);
}

void test_heap_is_empty() {
    max_heap_t *heap = heap_init();
    assert(heap_is_empty(heap));

    heap_insert(heap, 1);
    assert(!heap_is_empty(heap));

    heap_destroy(heap);
}

void test_heap_insert() {
    max_heap_t *heap = heap_init();
    heap_insert(heap, 1);
    assert(heap->data[0] == 1);

    heap_insert(heap, 2);
    assert(heap->data[0] == 2);

    heap_insert(heap, 3);
    assert(heap->data[0] == 3);
    assert(heap->data[1] == 1);

    heap_destroy(heap);
}

void test_heap_extract_max() {
    max_heap_t *heap = heap_init();
    assert(heap_extract_max(heap) == INT_MAX);

    heap_insert(heap, 1);
    assert(heap_extract_max(heap) == 1);
    assert(heap_is_empty(heap));

    heap_insert(heap, 2);
    heap_insert(heap, 3);
    heap_insert(heap, 4);
    assert(heap_extract_max(heap) == 4);
    assert(heap_get_size(heap) == 2);

    heap_destroy(heap);
}

void run_all_tests() {
    test_heap_init();
    test_heap_get_max();
    test_heap_get_size();
    test_heap_is_empty();
    test_heap_insert();
    test_heap_extract_max();
}

int main() {
    run_all_tests();
    return 0;
}
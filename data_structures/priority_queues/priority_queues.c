#include "priority_queues.h"

void swap(int *item_1, int *item_2) {
    int temp = *item_1;
    *item_1 = *item_2;
    *item_2 = temp;
}

int get_left_child_index(unsigned int index) {
    return (index * 2)+ 1;
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
        if (get_right_child_index(i) > heap->size
        && heap->data[get_right_child_index(i)] < heap->data[get_left_child_index(i)]) {
            larger_child_index = get_right_child_index(i);
        }

        if (heap->data[i] > heap->data[larger_child_index]) break;
        else swap(&i, &larger_child_index);

        i = larger_child_index;
    }
}

max_heap_t *heap_init() {
    max_heap_t *heap = (max_heap_t *) malloc(sizeof(max_heap_t));
    assert(heap);
    heap->size = 0;
    heap->capacity = MAX_SIZE + 1;

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
    heap->data[heap->size] = val;

    // Increase size of heap
    unsigned int i = heap->size++;
    // Rearrange the heap
    heapify_up(heap);
}

int heap_extract_max(max_heap_t *heap) {
    if (heap_is_empty(heap)) return -1;

    int retval = heap->data[0];
    heap->data[0] = heap->data[heap->size - 1];
    heap->size--;
    // Rearrange the heap
    heapify_down(heap);

    return retval;
}

int main() {
    max_heap_t *heap = heap_init();
    heap_insert(heap, 1);
    printf("%d\n", heap->data[0]);

    heap_insert(heap, 2);
    printf("%d\n", heap->data[0]);

    heap_insert(heap, 3);
    printf("%d\n", heap->data[0]);

    printf("%d\n", heap_extract_max(heap));
    printf("%d\n", heap->data[0]);
    printf("%d\n", heap->data[1]);


    heap_destroy(heap);
    return 0;
}
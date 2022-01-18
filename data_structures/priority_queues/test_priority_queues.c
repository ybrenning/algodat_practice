#include <assert.h>
#include <limits.h>
#include "priority_queues.h"

void test_heap_init() {
    max_heap_t *heap = heap_init();
    assert(heap);
    assert(heap->size == 0);
    assert(heap->capacity == MAX_SIZE);

    heap_destroy(&heap);
}

void test_heap_get_max() {
    max_heap_t *heap = heap_init();
    assert(heap_get_max(heap) == INT_MAX);

    heap->data[0] = 1;
    heap->size++;
    assert(heap_get_max(heap) == 1);

    heap->data[0] = 2;
    heap->data[1] = 1;
    heap->size++;
    assert(heap_get_max(heap) == 2);

    heap_destroy(&heap);
}

void test_heap_get_size() {
    max_heap_t *heap = heap_init();
    assert(heap_get_size(heap) == 0);

    heap_insert(heap, 1);
    assert(heap_get_size(heap) == 1);

    heap_insert(heap, 2);
    assert(heap_get_size(heap) == 2);

    heap_destroy(&heap);
}

void test_heap_is_empty() {
    max_heap_t *heap = heap_init();
    assert(heap_is_empty(heap));

    heap_insert(heap, 1);
    assert(!heap_is_empty(heap));

    heap_destroy(&heap);
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

    heap_destroy(&heap);
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
    assert(heap_extract_max(heap) == 3);

    heap_destroy(&heap);
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

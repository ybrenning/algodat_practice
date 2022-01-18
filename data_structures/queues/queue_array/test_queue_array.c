#include <stdio.h>
#include <assert.h>
#include "queue_array.h"

void test_queue_init() {
    queue_t *my_queue = queue_init();
    assert(my_queue->front == -1 && my_queue->rear == -1);
    queue_destroy(&my_queue);
}

void test_queue_destroy() {
    queue_t *my_queue = queue_init();
    queue_destroy(&my_queue);
    assert(my_queue == NULL);
}

void test_queue_isempty() {
    queue_t *my_queue = queue_init();
    assert(queue_isempty(my_queue));

    enqueue(my_queue, 1);
    assert(!queue_isempty(my_queue));

    queue_destroy(&my_queue);
}

void test_queue_isfull() {
    queue_t *my_queue = queue_init();
    assert(!queue_isfull(my_queue));

    for (int i = 0; i < MAX_SIZE; i++) {
        enqueue(my_queue, i + 1);
    }

    assert(queue_isfull(my_queue));

    queue_destroy(&my_queue);
}

void test_enqueue() {
    queue_t *my_queue = queue_init();
    enqueue(my_queue, 1);
    enqueue(my_queue, 2);
    assert(my_queue->data[my_queue->front] == 1);
    assert(my_queue->data[my_queue->rear] == 2);

    queue_destroy(&my_queue);

    my_queue = queue_init();
    for (int i = 0; i < MAX_SIZE; i++) {
        enqueue(my_queue, i + 1);
    }

    assert(my_queue->data[my_queue->rear] == MAX_SIZE);
    assert(my_queue->data[my_queue->front] == 1);

    assert(!enqueue(my_queue, MAX_SIZE + 1));
    assert(my_queue->data[my_queue->rear] == MAX_SIZE);

    queue_destroy(&my_queue);
}

void test_dequeue() {
    queue_t *my_queue = queue_init();
    assert(dequeue(my_queue) == -1);

    enqueue(my_queue, 1);
    enqueue(my_queue, 2);
    enqueue(my_queue, 3);
    assert(dequeue(my_queue) == 1);
    assert(dequeue(my_queue) == 2);
    assert(dequeue(my_queue) == 3);

    queue_destroy(&my_queue);
}

void run_all_tests() {
    test_queue_init();
    test_queue_destroy();
    test_queue_isempty();
    test_queue_isfull();
    test_enqueue();
    test_dequeue();
}

int main() {
    run_all_tests();
    return 0;
}

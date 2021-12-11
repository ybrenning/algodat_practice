/**
 * @author Yannick Brenning
 * @date 25.11.2021
 * @brief Implementation of the queue data structure using arrays
 */

#include "queue_array.h"

void check_address(void *address) {
    if (!address) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

Queue *queue_init() {
    Queue *my_queue = (Queue *) malloc(sizeof(Queue));
    check_address(my_queue);

    my_queue->front = -1;
    my_queue->rear = -1;
    return my_queue;
}

void queue_destroy(Queue *queue) {
    free(queue);
    queue = NULL;
}

bool queue_isempty(Queue *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

bool queue_isfull(Queue *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(Queue *queue, int val) {
    /* If the queue is empty, we move the front "pointer" to the first elem of the queue */
    if (queue_isempty(queue)) {
        queue->front++;
        queue->rear++;
        queue->data[queue->front] = val;
    } else if (queue_isfull(queue)) {
        return;
    } else {
        /* Otherwise, we only move the rear pointer to the next elem and insert the value */
        queue->rear++;
        queue->data[queue->rear] = val;
    }
}

int dequeue(Queue *queue) {
    int retval = -1;
    if (queue_isempty(queue)) {
        return retval;
    } else {
        retval = queue->data[queue->front];
        /* Check if front and rear pointer are on the same elem -- this means the queue only contains one elem */
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        /* Otherwise, move the front pointer along to the next elem */
        } else {
            queue->data[queue->front] = 0;
            queue->front++;
        }

        return retval;
    }
}

void queue_print(Queue *queue) {
    if (queue_isempty(queue)) {
        printf("[ ]\n");
        return;
    }

    printf("[ ");
    for (int i = queue->front; i < queue->rear; i++) {
        printf("%d, ", queue->data[i]);
    } printf("%d ]\n", queue->data[queue->rear]);
}

/* Tests */
void test_queue_init() {
    Queue *my_queue = queue_init();
    assert(my_queue->front == -1 && my_queue->rear == -1);
    queue_destroy(my_queue);
}

void test_queue_isempty() {
    Queue *my_queue = queue_init();
    assert(queue_isempty(my_queue));
    enqueue(my_queue, 1);
    assert(!queue_isempty(my_queue));
    queue_destroy(my_queue);
}

void test_queue_isfull() {
    Queue *my_queue = queue_init();
    assert(!queue_isfull(my_queue));

    for (int i = 0; i < MAX_SIZE; i++) {
        enqueue(my_queue, i + 1);
    }

    assert(queue_isfull(my_queue));
    queue_destroy(my_queue);
}

void test_enqueue() {
    Queue *my_queue = queue_init();
    enqueue(my_queue, 1);
    enqueue(my_queue, 2);
    assert(my_queue->data[my_queue->front] == 1);
    assert(my_queue->data[my_queue->rear] == 2);
    queue_destroy(my_queue);

    my_queue = queue_init();
    for (int i = 0; i < MAX_SIZE; i++) {
        enqueue(my_queue, i + 1);
    }

    assert(my_queue->data[my_queue->rear] == MAX_SIZE);
    assert(my_queue->data[my_queue->front] == 1);

    enqueue(my_queue, MAX_SIZE + 1);
    assert(my_queue->data[my_queue->rear] == MAX_SIZE);
    queue_destroy(my_queue);
}

void test_dequeue() {
    Queue *my_queue = queue_init();
    assert(dequeue(my_queue) == -1);

    enqueue(my_queue, 1);
    enqueue(my_queue, 2);
    enqueue(my_queue, 3);
    assert(dequeue(my_queue) == 1);
    assert(dequeue(my_queue) == 2);
    assert(dequeue(my_queue) == 3);
    queue_destroy(my_queue);
}

void run_all_tests() {
    test_queue_init();
    test_queue_isempty();
    test_queue_isfull();
    test_enqueue();
    test_dequeue();
}

int main() {
    run_all_tests();
    return 0;
}
/**
 * Author: Yannick Brenning
 * Date: 25.11.2021
 * Description: Implementation of the queue data structure using arrays
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
        printf("Queue is full.\n");
    } else {
        /* Otherwise, we only move the rear pointer to the next elem and insert the value */
        queue->rear++;
        queue->data[queue->rear] = val;
    }
}

int dequeue(Queue *queue) {
    int retval = -1;
    if (queue_isempty(queue)) {
        printf("Queue already empty.\n");
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

int main() {
    Queue *my_queue = queue_init();

    enqueue(my_queue, 3);
    enqueue(my_queue, 55);
    enqueue(my_queue, 9);
    enqueue(my_queue, 22);
    queue_print(my_queue);

    dequeue(my_queue);
    queue_print(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);
    dequeue(my_queue);
    queue_print(my_queue);

    enqueue(my_queue, 66);
    queue_print(my_queue);
    enqueue(my_queue, 43);
    queue_print(my_queue);
    enqueue(my_queue, 2);
    queue_print(my_queue);
    enqueue(my_queue, 99);
    queue_print(my_queue);

    return 0;
}
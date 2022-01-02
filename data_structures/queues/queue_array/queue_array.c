/**
 * @author Yannick Brenning
 * @date 25.11.2021
 * @brief Implementation of the queue data structure using arrays
 */

#include "queue_array.h"

queue_t *queue_init() {
    queue_t *my_queue = (queue_t *) malloc(sizeof(queue_t));
    assert(my_queue);

    my_queue->front = -1;
    my_queue->rear = -1;

    return my_queue;
}

void queue_destroy(queue_t **queue) {
    free(*queue);
    *queue = NULL;
}

bool queue_isempty(queue_t *queue) {
    return (queue->front == -1 && queue->rear == -1);
}

bool queue_isfull(queue_t *queue) {
    return (queue->rear == MAX_SIZE - 1);
}

void enqueue(queue_t *queue, int val) {
    // If the queue is empty, we move the front "pointer"
    // to the first elem of the queue
    if (queue_isempty(queue)) {
        queue->front++;
        queue->rear++;
        queue->data[queue->front] = val;
    } else if (!queue_isfull(queue)) {
        // We move the rear pointer to
        // the next elem and insert the value
        queue->rear++;
        queue->data[queue->rear] = val;
    }
}

int dequeue(queue_t *queue) {
    int retval = -1;
    if (queue_isempty(queue))
        return retval;
    else {
        retval = queue->data[queue->front];
        // Check if front and rear pointer are on the same elem
        // This means the queue only contains one elem
        if (queue->front == queue->rear) {
            queue->front = -1;
            queue->rear = -1;
        // Otherwise, move the front pointer along to the next elem
        } else {
            queue->data[queue->front] = EMPTY_SLOT;
            queue->front++;
        }

        return retval;
    }
}

void queue_print(queue_t *queue) {
    if (queue_isempty(queue)) {
        printf("[ ]\n");
        return;
    }

    printf("[ ");
    for (int i = queue->front; i < queue->rear; i++) {
        printf("%d, ", queue->data[i]);
    }

    printf("%d ]\n", queue->data[queue->rear]);
}

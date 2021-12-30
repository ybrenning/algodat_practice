/**
 * @author Yannick Brenning
 * @date 25.11.2021
 * @brief Implementation of the queue data structure using arrays
 */

#ifndef QUEUE_ARRAY_H
#define QUEUE_ARRAY_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#define MAX_SIZE 10
#define EMPTY_SLOT 0

typedef struct queue_t {
    int data[MAX_SIZE];
    int front;
    int rear;
} queue_t;

// Check if pointer address is valid
void check_address(void *address);
// Initialize queue pointer
queue_t *queue_init();
// Free queue memory
void queue_destroy(queue_t **queue);
// Check if queue is empty
bool queue_isempty(queue_t *queue);
// Check if queue is full
bool queue_isfull(queue_t *queue);
// Place value at end of queue
void enqueue(queue_t *queue, int val);
// Remove first value in queue
int dequeue(queue_t *queue);
// Print content of queue onto console
void queue_print(queue_t *queue);

// Tests
void test_queue_init();
void test_queue_destroy();
void test_queue_isempty();
void test_queue_isfull();
void test_enqueue();
void test_dequeue();
void run_all_tests();

#endif //QUEUE_ARRAY_H

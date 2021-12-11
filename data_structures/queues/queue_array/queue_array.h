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

typedef struct Queue {
    int data[MAX_SIZE];
    int front;
    int rear;
} Queue;

// Check if pointer address is valid
void check_address(void *address);
// Initialize queue pointer
Queue *queue_init();
// Free queue memory
void queue_destroy(Queue *queue);
// Check if queue is empty
bool queue_isempty(Queue *queue);
// Check if queue is full
bool queue_isfull(Queue *queue);
// Place value at end of queue
void enqueue(Queue *queue, int val);
// Remove first value in queue
int dequeue(Queue *queue);
// Print content of queue onto console
void queue_print(Queue *queue);

// Tests
void test_queue_init();
void test_queue_isempty();
void test_queue_isfull();
void test_enqueue();
void test_dequeue();
void run_all_tests();

#endif //QUEUE_ARRAY_H

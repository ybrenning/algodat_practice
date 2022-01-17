/**
 * @author Yannick Brenning
 * @date 03.01.2021
 * @brief Implementation of doubly linked lists
 */

#ifndef DOUBLY_LINKED_LISTS_H
#define DOUBLY_LINKED_LISTS_H

#include <stdbool.h>

typedef struct node_t {
    int val;
    struct node_t *next;
    struct node_t *prev;
} node_t;

// Initialize Doubly Linked List
node_t *dllist_init(int val);
// Deallocates list memory
void dllist_destroy(node_t **head);
// Check if list is empty
bool dllist_isempty(node_t *head);
// Get val of node at index
int dllist_get(node_t *head, unsigned int index);
// Append node to end of list
void dllist_append(node_t **head, int val);
// Push node to front of list
void dllist_push(node_t **head, int val);
// Insert node at index
bool dllist_insert(node_t **head, int val, unsigned int index);
// Remove tail node of list
int dllist_remove_last(node_t **head);
// Remove head node of list
int dllist_remove_first(node_t **head);
// Delete node at index
int dllist_delete(node_t **head, unsigned int index);
// Reverse the list
void dllist_reverse(node_t **head);
// Print contents of list onto console
void dllist_print(node_t *head);

// Tests
void test_dllist_init();
void test_dllist_destroy();
void test_dllist_get();
void test_dllist_append();
void test_dllist_push();
void test_dllist_insert();
void test_dllist_remove_first();
void test_dllist_remove_last();
void test_dllist_delete();
void test_dllist_reverse();
void run_all_tests();

#endif //DOUBLY_LINKED_LISTS_H

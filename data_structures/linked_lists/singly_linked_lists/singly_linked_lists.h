/**
 * @author Yannick Brenning
 * @date 24.11.2021
 * @brief Implementation of singly linked lists
 */

#ifndef SINGLY_LINKED_LISTS_H
#define SINGLY_LINKED_LISTS_H

#include <stdbool.h>

typedef struct node_t {
    int val;
    struct node_t *next;
} node_t;

// Initialize Singly Linked List
node_t *llist_init(int val);
// Deallocates llist memory
void llist_destroy(node_t **head);
// Return number of elems in llist
unsigned int llist_size(node_t *head);
// Check if llist is empty
bool llist_isempty(node_t *head);
// Get val of node at index
int llist_get(node_t *head, int index);
// Append node to llist
void llist_append(node_t **head, int val);
// Push node to beginning of llist
void llist_push(node_t **head, int val);
// Remove last node of llist
int llist_remove_last(node_t **head);
// Remove first node of llist
int llist_remove_first(node_t **head);
// Insert node at index
bool llist_insert(node_t **head, int val, int index);
// Remove node at index
int llist_delete_index(node_t **head, int index);
// Remove first node with value
int llist_delete_val(node_t **head, int val);
// Find first node with specified val in llist
int llist_find(node_t *head, int val);
// Reverse the llist
void llist_reverse(node_t **head);
// Print contents of llist onto console
void llist_print(node_t *head);

// Tests
void test_llist_init();
void test_llist_destroy();
void test_llist_size();
void test_llist_isempty();
void test_llist_get();
void test_llist_append();
void test_llist_push();
void test_llist_remove_last();
void test_llist_remove_first();
void test_llist_insert();
void test_llist_delete_index();
void test_llist_delete_val();
void test_llist_find();
void test_llist_reverse();
void run_all_tests();

#endif //SINGLY_LINKED_LISTS_H

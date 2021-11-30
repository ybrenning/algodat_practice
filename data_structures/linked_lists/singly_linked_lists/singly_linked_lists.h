/**
 * Author: Yannick Brenning
 * Date: 24.11.2021
 * Description: Implementation of singly linked lists
 */

#ifndef SINGLY_LINKED_LISTS_H
#define SINGLY_LINKED_LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

// Check if address is valid
void check_address(void *address);
// Initialize Linked List
Node *llist_init(int val);
// Return number of elems in llist
int llist_size(Node *head);
// Check if llist is empty
bool llist_isempty(Node *head);
// Get val of node at index
int llist_get(Node *head, int index);
// Append node to llist
void llist_append(Node **head, int val);
// Push node to beginning of llist
void llist_push(Node **head, int val);
// Remove last node of llist
int llist_remove_last(Node **head);
// Remove first node of llist
int llist_remove_first(Node **head);
// Insert node at index
void llist_insert(Node **head, int val, int index);
// Find first node with specified val in llist
int llist_find(Node *head, int val);
// Reverse the llist
void llist_reverse(Node **head);
// Print contents of llist onto console
void llist_print(Node *head);

// Tests
void test_llist_init();
void test_llist_size();
void test_llist_isempty();
void test_llist_get();
void test_llist_append();
void test_llist_push();
void test_llist_remove_last();
void test_llist_remove_first();
void test_llist_insert();
void test_llist_find();
void test_llist_reverse();
void run_all_tests();

#endif //SINGLY_LINKED_LISTS_H

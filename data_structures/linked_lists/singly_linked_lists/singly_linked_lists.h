/**
 * Author: Yannick Brenning
 * Date: 24.11.2021
 * Description: Implementation of singly linked lists
 */

#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

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

#endif //LINKED_LISTS_H

#ifndef LINKED_LISTS_H
#define LINKED_LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node {
    int val;
    struct Node *next;
} Node;

void check_address(void *address);
Node *llist_init(int val);
void llist_append(Node **head, int val);
void llist_push(Node **head, int val);
int llist_remove_last(Node **head);
int llist_remove_first(Node **head);
void llist_insert(Node **head, int val, int index);
int llist_find(Node *head, int val);
void llist_reverse(Node **head);
void llist_print(Node *head);

#endif //LINKED_LISTS_H

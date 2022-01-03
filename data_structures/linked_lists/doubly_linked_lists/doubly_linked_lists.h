#ifndef DOUBLY_LINKED_LISTS_H
#define DOUBLY_LINKED_LISTS_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct node_t {
    int val;
    struct node_t *next;
    struct node_t *prev;
} node_t;

node_t *dllist_init(int val);
void dllist_destroy(node_t **head);
bool is_empty(node_t *head);
void dllist_append(node_t *head, int val);
void dllist_push(node_t **head, int val);
void dllist_insert(node_t **head, int val, unsigned int index);
int dllist_remove_last(node_t **head);
int dllist_remove_first(node_t **head);
int dllist_delete(node_t **head, unsigned int index);
void dllist_print(node_t *head);

#endif //DOUBLY_LINKED_LISTS_H

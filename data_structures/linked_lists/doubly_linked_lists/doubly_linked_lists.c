/**
 * @author Yannick Brenning
 * @date 03.01.2021
 * @brief Implementation of doubly linked lists
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "doubly_linked_lists.h"

node_t *dllist_init(const int val) {
    node_t *head = (node_t *) malloc(sizeof(node_t));
    assert(head);

    head->val = val;
    head->prev = NULL;
    head->next = NULL;

    return head;
}

void dllist_destroy(node_t **head) {
    if (dllist_isempty(*head)) {
        return;
    }

    node_t *curr = *head;
    node_t *temp;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }

    *head = NULL;
}

bool dllist_isempty(node_t *head) {
    return (head == NULL);
}

int dllist_get(node_t *head, const unsigned int index) {
    if (dllist_isempty(head)) {
        return -1;
    }

    node_t *curr = head;
    for (int i = 0; i < index; i++) {
        if (curr->next == NULL) {
            return -1;
        }

        curr = curr->next;
    }

    return curr->val;
}

void dllist_append(node_t **head, const int val) {
    if (dllist_isempty(*head)) {
        *head = dllist_init(val);
        return;
    }

    node_t *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = NULL;
    new_node->prev = curr;

    curr->next = new_node;
}

void dllist_push(node_t **head, const int val) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->val = val;
    new_node->prev = NULL;
    new_node->next = *head;

    (*head)->prev = new_node;
    *head = new_node;
}

bool dllist_insert(node_t **head, const int val, const unsigned int index) {
    if (dllist_isempty(*head) && index != 0) {
        return false;
    }

    if (index == 0) {
        dllist_push(head, val);
        return true;
    }

    node_t *curr = *head;
    for (int i = 0; i < index - 1; i++) {
        if (curr->next == NULL) {
            return false;
        }

        curr = curr->next;
    }

    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->val = val;
    new_node->prev = curr;
    new_node->next = curr->next;

    curr->next = new_node;

    return true;
}

int dllist_remove_last(node_t **head) {
    int retval = -1;

    if (dllist_isempty(*head)) {
        return retval;
    }

    if ((*head)->next == NULL) {
        retval = (*head)->val;

        free(*head);
        *head = NULL;

        return retval;
    }

    node_t *curr = *head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }

    retval = curr->next->val;
    free(curr->next);
    curr->next = NULL;

    return retval;
}

int dllist_remove_first(node_t **head) {
    int retval = -1;

    if (dllist_isempty(*head)) {
        return retval;
    }

    retval = (*head)->val;

    if ((*head)->next == NULL) {

        free(*head);
        *head = NULL;

        return retval;
    }

    node_t *temp = (*head)->next;
    temp->prev = NULL;
    free(*head);
    (*head) = temp;

    return retval;
}

int dllist_delete(node_t **head, const unsigned int index) {
    int retval = -1;
    if (dllist_isempty(*head)) {
        return retval;
    }

    if (index == 0) {
        return dllist_remove_first(head);
    }

    // Get to the node before the one we want to delete
    // such that curr->next is the node to be removed
    node_t *curr = *head;
    for (int i = 0; i < index - 1; i++) {
        // Check if we are out of bounds
        if (curr->next == NULL) {
            return retval;
        }

        curr = curr->next;
    }

    if (curr->next == NULL) {
        return retval;
    }

    retval = curr->next->val;
    node_t *new_next = curr->next->next;

    if (new_next == NULL) {
        return dllist_remove_last(head);
    } else {
        new_next->prev = curr;
    }

    free(curr->next);
    curr->next = new_next;

    return retval;
}

void dllist_reverse(node_t **head) {
    node_t *curr = *head;
    node_t *temp = NULL;
    while (curr != NULL) {
        // Reversing doubly linked list simply
        // requires us to swap each prev and next node
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;

        curr = curr->prev;
    }

    // Set new head to last node of old llist
    // NULL <- old_head -> <- node_1 -> ... <- temp -> <- old_tail -> NULL
    if (temp != NULL) {
        *head = temp->prev;
    }
}

void dllist_print(node_t *head) {
    if (dllist_isempty(head))
        printf("[ ]\n");
    else {
        printf("[ ");

        node_t *curr = head;
        while (curr->next != NULL) {
            printf("%d ", curr->val);
            curr = curr->next;
        }

        printf("%d ]\n", curr->val);
    }
}

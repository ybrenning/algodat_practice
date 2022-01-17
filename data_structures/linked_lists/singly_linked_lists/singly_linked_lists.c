/**
 * @author Yannick Brenning
 * @date 24.11.2021
 * @brief Implementation of singly linked lists
 */

#include <stdlib.h>
#include <assert.h>
#include "singly_linked_lists.h"

node_t *llist_init(int val) {
    node_t *head = (node_t *) malloc(sizeof(node_t));
    assert(head);
    head->val = val;
    head->next = NULL;

    return head;
}

unsigned int llist_size(node_t *head) {
    int size = 0;
    node_t *curr = head;
    while (curr != NULL) {
        curr = curr->next;
        size++;
    }

    return size;
}

bool llist_isempty(node_t *head) {
    return (head == NULL);
}

int llist_get(node_t *head, int index) {
    if (index < 0 || llist_isempty(head)) {
        return -1;
    }

    node_t *curr = head;
    for (int i = 0; i < index; i++) {
        // Check if index out of bounds
        if (curr->next == NULL) {
            return -1;
        }

        curr = curr->next;
    }

    return curr->val;
}

void llist_append(node_t **head, int val) {
    if (llist_isempty(*head)) {
        *head = llist_init(val);
        return;
    }

    node_t *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->val = val;
    new_node->next = NULL;

    curr->next = new_node;
}

void llist_push(node_t **head, int val) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->next = *head;
    new_node->val = val;

    *head = new_node;
}

int llist_remove_last(node_t **head) {
    int retval = -1;
    if (llist_isempty(*head)) {
        return retval;
    }

    if ((*head)->next == NULL) {
        retval = (*head)->val;

        free(*head);
        *head = NULL;

        return retval;
    }

    // Get to second last node and change its next pointer
    node_t *curr = *head;
    while (curr->next->next != NULL) {
        curr = curr->next;
    }

    retval = curr->next->val;
    free(curr->next);
    curr->next = NULL;

    return retval;
}

int llist_remove_first(node_t **head) {
    if (llist_isempty(*head)) {
        return -1;
    }

    int retval = (*head)->val;

    node_t *temp = *head;
    *head = temp->next;
    free(temp);

    return retval;
}

void llist_print(node_t *head) {
    if (llist_isempty(head)) {
        printf("[ ]\n");
    } else {
        node_t *curr = head;
        printf("[ ");
        while (curr->next != NULL) {
            printf("%d ", curr->val);
            curr = curr->next;
        }

        printf("%d ]\n", curr->val);
    }
}

bool llist_insert(node_t **head, int val, int index) {
    if (index < 0 || llist_isempty(*head)) {
        return false;
    }

    if (index == 0) {
        llist_push(head, val);
        return true;
    }

    node_t *curr = *head;
    // Get to node before index, such that curr->next
    // can be set to our new node
    for (int i = 0; i < index - 1; i++) {
        // Check if index is out of bounds
        if (curr->next == NULL) {
            return false;
        }

        curr = curr->next;
    }

    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->val = val;

    node_t *temp = curr->next;
    curr->next = new_node;
    new_node->next = temp;

    return true;
}

int llist_delete_index(node_t **head, int index) {
    if (index < 0 || llist_isempty(*head)) {
        return -1;
    }

    if (index == 0) {
        return llist_remove_first(head);
    }

    // Get to node before index, such that
    // curr->next is the node to be removed
    node_t *curr = *head;
    for (int i = 0; i < index - 1; i++) {
        // Check if index is out of bounds
        if (curr == NULL) {
            return -1;
        }

        curr = curr->next;
    }

    if (curr->next == NULL) {
        return -1;
    }

    if (curr->next->next == NULL) {
        return llist_remove_last(head);
    }

    int retval = curr->next->val;
    node_t *temp = curr->next;
    curr->next = curr->next->next;
    free(temp);

    return retval;
}

int llist_delete_val(node_t **head, int val) {
    if (llist_isempty(*head)) {
        return -1;
    }

    int curr_index = 0;
    node_t *curr = *head;
    while (curr != NULL) {
        if (curr->val == val) {
            return llist_delete_index(head, curr_index);
        }

        curr = curr->next;
        curr_index++;
    }

    return -1;
}

int llist_find(node_t *head, int val) {
    int index = 0;
    node_t *curr = head;
    while (curr != NULL) {
        if (curr->val == val) {
            return index;
        }

        curr = curr->next;
        index++;
    }

    return -1;
}

void llist_reverse(node_t **head) {
    if (llist_isempty(*head) || (*head)->next == NULL) {
        return;
    }

    node_t *curr = *head;
    node_t *next = NULL, *prev = NULL;
    // Traverse entire list and reverse each pointer
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;

        curr = next;
    }

    // Set head node to last node of old list
    *head = prev;

    // Visual representation:
    // old_head -> node_1 -> ... -> prev -> old_tail -> NULL
}

void llist_destroy(node_t **head) {
    node_t *curr = *head;
    while (curr != NULL) {
        node_t *next = curr->next;
        free(curr);
        curr = next;
    }

    *head = NULL;
}

/**
 * Author: Yannick Brenning
 * Date: 24.11.2021
 * Description: Implementation of singly linked lists
 */

#include "singly_linked_lists.h"

void check_address(void *address) {
    if (!address) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

Node *llist_init(int val) {
    Node *head = (Node *) malloc(sizeof(Node));
    check_address(head);
    head->val = val;
    head->next = NULL;

    return head;
}

int llist_size(Node *head) {
    int count = 0;
    Node *curr = head;
    while (curr != NULL) {
        curr = curr->next;
        count++;
    }

    return count;
}

bool llist_isempty(Node *head) {
    return (head == NULL);
}

void llist_append(Node **head, int val) {
    if (llist_isempty(*head)) {
        *head = llist_init(val);
        return;
    }

    /* If llist not empty, traverse nodes and change next pointer of last */
    Node *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = (Node *) malloc(sizeof(Node));
    curr->next->val = val;
    curr->next->next = NULL;
}

int llist_get(Node *head, int index) {
    if (index < 0) return -1;
    if (llist_isempty(head)) return -1;

    Node *curr = head;
    for (int i = 0; i < index; i++) {
        /* Check if index out of bounds */
        if (curr->next == NULL) return -1;
        curr = curr->next;
    }

    return curr->val;
}

void llist_push(Node **head, int val) {
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->next = *head;
    new_node->val = val;
    *head = new_node;
}

int llist_remove_last(Node **head) {
    int retval;
    Node *curr = *head;
    if (llist_isempty(*head)) return -1;
    if ((*head)->next == NULL) {
        retval = (*head)->val;
        *head = NULL;
        return retval;
    }

    /* Get to second last node and change its next pointer */
    while (curr->next->next != NULL) {
        curr = curr->next;
    }

    retval = curr->next->val;
    free(curr->next);
    curr->next = NULL;
    return retval;
}

int llist_remove_first(Node **head) {
    int retval = (*head)->val;
    Node *front = *head;

    *head = front->next;
    free(front);
    return retval;
}

void llist_print(Node *head) {
    if (llist_isempty(head)) {
        printf("[ ]\n");
        return;
    }

    Node *curr = head;
    printf("[ ");
    while (curr->next != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    } printf("%d ]\n", curr->val);
}

void llist_insert(Node **head, int val, int index) {
    if (index < 0 || llist_isempty(*head)) return;
    if (index == 0) {
        llist_push(head, val);
        return;
    }

    Node *curr = *head;
    /* Get to node before index, such that curr->next can be our new node */
    for (int i = 0; i < index - 1; i++) {
        /* Check if index is out of bounds */
        if (curr->next == NULL) return;
        curr = curr->next;
    }
    Node *new_node = (Node *) malloc(sizeof(Node));
    new_node->val = val;
    Node *temp = curr->next;
    curr->next = new_node;
    new_node->next = temp;
}

int llist_find(Node *head, int val) {
    int index = 0;
    Node *curr = head;
    while (curr != NULL) {
        if (curr->val == val) return index;
        curr = curr->next;
        index++;
    }

    return -1;
}

void llist_reverse(Node **head) {
    if (llist_isempty(*head) || (*head)->next == NULL) return;
    Node *curr = *head;
    Node *prev = NULL;
    Node *next;

    /* Traverse entire llist and reverse each next pointer */
    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    /* Set head to last elem of the old llist */
    *head = prev;
}

void llist_destroy(Node **head) {
    Node *curr = *head;
    while (curr != NULL) {
        Node *next = curr->next;
        free(curr);
        curr = next;
    }

    head = NULL;
}

int main() {

    /* Some tests */
    Node *head = llist_init(2);
    Node **p_head = &head;

    llist_print(head);
    llist_remove_last(p_head);
    llist_print(head);

    llist_append(p_head, 3);
    llist_print(head);
    llist_append(p_head, 4);
    llist_append(p_head, 5);
    llist_append(p_head, 6);
    llist_print(head);
    llist_push(p_head, 1);
    llist_print(head);

    llist_remove_last(p_head);
    llist_print(head);
    llist_remove_first(p_head);
    llist_print(head);

    llist_insert(p_head, 50, 9);
    llist_print(head);

    printf("%d\n", llist_find(head, 5));
    llist_reverse(p_head);
    llist_print(head);

    llist_destroy(p_head);
    return 0;
}
/**
 * @author Yannick Brenning
 * @date 24.11.2021
 * @brief Implementation of singly linked lists
 */

#include "singly_linked_lists.h"

void check_address(void *address) {
    if (!address) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

node_t *llist_init(int val) {
    node_t *head = (node_t *) malloc(sizeof(node_t));
    check_address(head);
    head->val = val;
    head->next = NULL;

    return head;
}

int llist_size(node_t *head) {
    int count = 0;
    node_t *curr = head;
    while (curr != NULL) {
        curr = curr->next;
        count++;
    }

    return count;
}

bool llist_isempty(node_t *head) {
    return (head == NULL);
}

int llist_get(node_t *head, int index) {
    if (index < 0) return -1;
    if (llist_isempty(head)) return -1;

    node_t *curr = head;
    for (int i = 0; i < index; i++) {
        /* Check if index out of bounds */
        if (curr->next == NULL) return -1;
        curr = curr->next;
    }

    return curr->val;
}

void llist_append(node_t **head, int val) {
    if (llist_isempty(*head)) {
        *head = llist_init(val);
        return;
    }

    /* If llist not empty, traverse nodes and change next pointer of last */
    node_t *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = (node_t *) malloc(sizeof(node_t));
    curr->next->val = val;
    curr->next->next = NULL;
}

void llist_push(node_t **head, int val) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->next = *head;
    new_node->val = val;
    *head = new_node;
}

int llist_remove_last(node_t **head) {
    int retval;
    node_t *curr = *head;
    if (llist_isempty(*head)) return -1;
    if ((*head)->next == NULL) {
        retval = (*head)->val;
        free(*head);
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

int llist_remove_first(node_t **head) {
    if (llist_isempty(*head)) return -1;

    int retval = (*head)->val;
    node_t *front = *head;

    *head = front->next;
    free(front);
    return retval;
}

void llist_print(node_t *head) {
    if (llist_isempty(head)) {
        printf("[ ]\n");
        return;
    }

    node_t *curr = head;
    printf("[ ");
    while (curr->next != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    } printf("%d ]\n", curr->val);
}

void llist_insert(node_t **head, int val, int index) {
    if (index < 0 || llist_isempty(*head)) return;
    if (index == 0) {
        llist_push(head, val);
        return;
    }

    node_t *curr = *head;
    /* Get to node before index, such that curr->next can be our new node */
    for (int i = 0; i < index - 1; i++) {
        /* Check if index is out of bounds */
        if (curr->next == NULL) return;
        curr = curr->next;
    }
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->val = val;
    node_t *temp = curr->next;
    curr->next = new_node;
    new_node->next = temp;
}

int llist_find(node_t *head, int val) {
    int index = 0;
    node_t *curr = head;
    while (curr != NULL) {
        if (curr->val == val) return index;
        curr = curr->next;
        index++;
    }

    return -1;
}

void llist_reverse(node_t **head) {
    if (llist_isempty(*head) || (*head)->next == NULL) return;
    node_t *curr = *head;
    node_t *prev = NULL;
    node_t *next;

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

void llist_destroy(node_t **head) {
    node_t *curr = *head;
    while (curr != NULL) {
        node_t *next = curr->next;
        free(curr);
        curr = next;
    }

    head = NULL;
}

void test_llist_init() {
    node_t *head = llist_init(1);
    assert(head->val == 1);
    assert(head->next == NULL);
    llist_destroy(&head);
}

void test_llist_size() {
    node_t *head = llist_init(1);
    assert(llist_size(head) == 1);

    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL;
    assert(llist_size(head) == 2);
    llist_destroy(&head);
}

void test_llist_isempty() {
    node_t *head = llist_init(1);
    assert(!llist_isempty(head));

    free(head);
    head = NULL;
    assert(llist_isempty(head));
    llist_destroy(&head);
}

void test_llist_get() {
    node_t *head = llist_init(1);
    assert(llist_get(head, 0) == 1);

    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL;
    assert(llist_get(head, 1) == 2);
    assert(llist_get(head, -1) == -1);
    assert(llist_get(head, 2) == -1);
    llist_destroy(&head);
}

void test_llist_append() {
    node_t *head = llist_init(1);
    llist_append(&head, 2);
    llist_append(&head, 3);
    assert(llist_get(head, 1) == 2);
    assert(llist_get(head, 2) == 3);
    llist_destroy(&head);
}

void test_llist_push() {
    node_t *head = llist_init(1);
    llist_push(&head, 2);
    assert(llist_get(head, 0) == 2);
    llist_destroy(&head);
}

void test_llist_remove_last() {
    node_t *head = llist_init(1);
    assert(llist_remove_last(&head) == 1);
    assert(llist_isempty(head));
    assert(llist_remove_last(&head) == -1);

    llist_append(&head, 2);
    llist_append(&head, 3);
    assert(llist_remove_last(&head) == 3);
    assert(llist_get(head, 1) == -1);
    llist_destroy(&head);
}

void test_llist_remove_first() {
    node_t *head = llist_init(1);
    assert(llist_remove_first(&head) == 1);
    assert(llist_remove_first(&head) == -1);

    llist_append(&head, 2);
    llist_append(&head, 3);
    llist_append(&head, 4);
    assert(llist_remove_first(&head) == 2);
    assert(llist_get(head, 0) == 3);
    llist_destroy(&head);
}

void test_llist_insert() {
    node_t *head = llist_init(1);

    // Check if we can insert at front
    llist_insert(&head, 2, 0);
    assert(llist_get(head, 0) == 2);

    // Check if we can insert in middle
    llist_append(&head, 3);
    llist_append(&head, 4);
    llist_insert(&head, 5, 1);
    assert(llist_get(head, 1) == 5);
    assert(llist_get(head, 4) == 4);

    // Check if we can insert at end
    llist_insert(&head, 6, 5);
    assert(llist_get(head, 5) == 6);
    llist_destroy(&head);
}

void test_llist_find() {
    node_t *head = llist_init(1);
    assert(llist_find(head, 1) == 0);
    assert(llist_find(head, 2) == -1);

    llist_append(&head, 2);
    llist_append(&head, 3);
    llist_append(&head, 4);
    assert(llist_find(head, 3) == 2);
    llist_destroy(&head);
}

void test_llist_reverse() {
    node_t *head = llist_init(1);
    llist_reverse(&head);
    assert(llist_get(head, 0) == 1);

    llist_append(&head, 2);
    llist_append(&head, 3);
    llist_append(&head, 4);
    llist_reverse(&head);
    assert(llist_get(head, 0) == 4);
    assert(llist_get(head, 1) == 3);
    assert(llist_get(head, 2) == 2);
    assert(llist_get(head, 3) == 1);
    llist_destroy(&head);
}

void run_all_tests() {
    test_llist_init();
    test_llist_size();
    test_llist_isempty();
    test_llist_get();
    test_llist_append();
    test_llist_push();
    test_llist_remove_last();
    test_llist_remove_first();
    test_llist_insert();
    test_llist_find();
    test_llist_reverse();
}

int main() {
    run_all_tests();
    return 0;
}
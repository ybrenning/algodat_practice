#include "singly_linked_lists.h"

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

#include "doubly_linked_lists.h"

void test_dllist_init() {
    node_t *head = dllist_init(1);
    assert(head->val == 1);
    assert(head->next == NULL && head->prev == NULL);
    assert(!is_empty(head));

    dllist_destroy(&head);
}

void test_dllist_destroy() {
    node_t *head = dllist_init(1);
    dllist_destroy(&head);
    assert(head == NULL);
}

void test_dllist_get() {
    node_t *head = dllist_init(1);
    assert(dllist_get(head, 0) == 1);
    assert(dllist_get(head, 1) == -1);

    head->next = (node_t *) malloc(sizeof(node_t));
    head->next->val = 2;
    head->next->next = NULL;
    head->next->prev = head;
    assert(dllist_get(head, 1) == 2);

    dllist_destroy(&head);
}

void test_dllist_append() {
    node_t *head = dllist_init(1);
    assert(dllist_get(head, 0) == 1);
    dllist_append(&head, 2);
    assert(head->next->val == 2);

    dllist_append(&head, 3);
    assert(dllist_get(head, 2) == 3);

    dllist_destroy(&head);
}

void test_dllist_push() {
    node_t *head = dllist_init(1);
    dllist_push(&head, 2);
    assert(dllist_get(head, 0) == 2);

    dllist_push(&head, 3);
    assert(dllist_get(head, 0) == 3);
    assert(head->prev == NULL);
    assert(head->next->prev->val == head->val);

    dllist_destroy(&head);
}

void test_dllist_insert() {
    node_t *head = dllist_init(1);
    dllist_insert(&head, 2, 1);
    assert(dllist_get(head, 1) == 2);

    dllist_append(&head, 3);
    dllist_append(&head, 4);
    dllist_insert(&head, 5, 2);
    assert(dllist_get(head, 2) == 5);

    dllist_destroy(&head);
}

void test_dllist_remove_first() {
    node_t *head = dllist_init(1);
    assert(dllist_remove_first(&head) == 1);
    assert(is_empty(head));

    dllist_append(&head, 3);
    dllist_append(&head, 2);
    dllist_append(&head, 1);
    assert(dllist_remove_first(&head) == 3);
    assert(dllist_get(head, 0) == 2);

    dllist_destroy(&head);
}

void test_dllist_remove_last() {
    node_t *head = dllist_init(1);
    assert(dllist_remove_last(&head) == 1);
    assert(is_empty(head));

    dllist_append(&head, 1);
    dllist_append(&head, 2);
    dllist_append(&head, 3);
    assert(dllist_remove_last(&head) == 3);
    assert(dllist_remove_last(&head) == 2);

    dllist_destroy(&head);
}

void test_dllist_delete() {
    node_t *head = dllist_init(1);
    assert(dllist_delete(&head, 1) == -1);
    assert(dllist_delete(&head, 0) == 1);
    assert(is_empty(head));

    assert(dllist_delete(&head, 0) == -1);

    dllist_append(&head, 1);
    dllist_append(&head, 2);
    dllist_append(&head, 3);
    assert(dllist_delete(&head, 1) == 2);
    assert(dllist_get(head, 1) == 3);

    dllist_destroy(&head);
}

void test_dllist_reverse() {
    node_t *head = dllist_init(1);

    for (int i = 2; i <= 5; i++) {
        dllist_append(&head, i);
    }

    dllist_reverse(&head);
    for (int i = 5, j = 0; j < 5; i--, j++) {
        assert(dllist_get(head, j) == i);
    }

    dllist_destroy(&head);
}

void run_all_tests() {
    test_dllist_init();
    test_dllist_destroy();
    test_dllist_get();
    test_dllist_append();
    test_dllist_push();
    test_dllist_insert();
    test_dllist_remove_first();
    test_dllist_remove_last();
    test_dllist_delete();
    test_dllist_reverse();
}

int main() {
    run_all_tests();
    return 0;
}

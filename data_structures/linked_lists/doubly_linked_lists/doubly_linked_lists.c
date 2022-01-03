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
    if (is_empty(*head))
        return;

    node_t *curr = *head;
    node_t *temp;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }

    *head = NULL;
}

bool is_empty(node_t *head) {
    return head == NULL;
}

void dllist_append(node_t *head, const int val) {
    if (is_empty(head)) {
        head = (node_t *) malloc(sizeof(node_t));
        head->val = val;
        head->next = NULL;
        head->prev = NULL;
    } else {
        node_t *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }

        node_t *new_node = (node_t *) malloc(sizeof(node_t));
        new_node->val = val;
        new_node->next = NULL;
        new_node->prev = curr;

        curr->next = new_node;
    }
}

void dllist_push(node_t **head, const int val) {
    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->val = val;
    new_node->prev = NULL;
    new_node->next = *head;

    (*head)->prev = new_node;
    *head = new_node;
}

void dllist_insert(node_t **head, const int val, const unsigned int index) {
    if (is_empty(*head))
        return;
    else if (index == 0)
        dllist_push(head, val);

    node_t *curr = *head;
    for (int i = 0; i < index - 1; i++) {
        if (curr->next == NULL)
            return;
        curr = curr->next;
    }

    node_t *new_node = (node_t *) malloc(sizeof(node_t));
    new_node->val = val;
    new_node->prev = curr;
    new_node->next = curr->next;

    curr->next = new_node;
}

int dllist_remove_last(node_t **head) {
    int retval;
    if (is_empty(*head))
        retval = -1;
    else if ((*head)->next == NULL) {
        retval = (*head)->val;

        free(*head);
        *head = NULL;
    } else {
        node_t *curr = *head;
        while (curr->next->next != NULL) {
            curr = curr->next;
        }

        retval = curr->next->val;
        free(curr->next);
        curr->next = NULL;
    }

    return retval;
}

int dllist_remove_first(node_t **head) {
    int retval;
    if (is_empty(*head))
        retval = -1;
    else if ((*head)->next == NULL) {
        retval = (*head)->val;

        free(*head);
        *head = NULL;
    } else {
        retval = (*head)->val;

        node_t *temp = (*head)->next;
        temp->prev = NULL;
        free(*head);
        (*head) = temp;
    }

    return retval;
}

int dllist_delete(node_t **head, const unsigned int index) {
    int retval = -1;
    if (is_empty(*head))
        return retval;
    else if (index == 0) {
        return dllist_remove_first(head);
    } else {
        node_t *curr = *head;
        for (int i = 0; i < index - 1; i++) {
            if (curr->next == NULL)
                return retval;
            curr = curr->next;
        }

        retval = curr->next->val;
        node_t *new_next = curr->next->next;

        if (new_next == NULL)
            return dllist_remove_last(head);
        else
            new_next->prev = curr;

        free(curr->next);
        curr->next = new_next;

        return retval;
    }
}

void dllist_print(node_t *head) {
    if (is_empty(head))
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
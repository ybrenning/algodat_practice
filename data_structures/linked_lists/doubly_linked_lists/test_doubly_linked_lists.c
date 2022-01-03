#include "doubly_linked_lists.h"

int main() {
    node_t *dllist = dllist_init(0);

    dllist_append(dllist, 1);
    dllist_append(dllist, 2);
    dllist_append(dllist, 5);
    dllist_append(dllist, 9);
    dllist_append(dllist, 3);
    dllist_push(&dllist, 44);
    dllist_push(&dllist, 33);
    dllist_insert(&dllist, 100, 0);
    dllist_remove_last(&dllist);
    dllist_remove_first(&dllist);
    dllist_remove_first(&dllist);
    dllist_delete(&dllist, 5);

    dllist_print(dllist);
    printf("PREVIOUS NODE OF 0: %d\n", dllist->next->prev->val);
    printf("NEXT NODE OF 0: %d\n", dllist->next->next->val);
    printf("%s\n", is_empty(dllist) ? "true" : "false");

    dllist_destroy(&dllist);
    return 0;
}
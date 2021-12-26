#include "binary_search_trees.h"

void test_bst_insert() {
    bst_node_t *root = NULL;
    root = bst_insert(root, 1);
    assert(root->val == 1);
    assert(root->left == NULL && root->right == NULL);

    root = bst_insert(root, 2);
    assert(root->right->val == 2);
    bst_destroy(root);
}

void test_bst_node_count() {
    bst_node_t *root = NULL;
    root = bst_insert(root, 1);
    assert(bst_node_count(root) == 1);
    bst_destroy(root);
}

void test_bst_is_val_in_tree() {
    bst_node_t *root = NULL;
    root = bst_insert(root, 1);
    assert(bst_is_val_in_tree(root, 1));
    assert(!bst_is_val_in_tree(root, 2));

    root = bst_insert(root, 2);
    assert(bst_is_val_in_tree(root, 2));
    bst_destroy(root);
}

void test_bst_get_height() {
    bst_node_t *root = NULL;
    root = bst_insert(root, 1);
    assert(bst_get_height(root) == 0);

    root = bst_insert(root, 2);
    assert(bst_get_height(root) == 1);

    root = bst_insert(root, 0);
    assert(bst_get_height(root) == 1);

    root = bst_insert(root, 3);
    assert(bst_get_height(root) == 2);

    bst_destroy(root);
}

void test_bst_get_min() {
    bst_node_t *root = NULL;
    root = bst_insert(root, 1);
    assert(bst_get_min(root) == 1);

    root = bst_insert(root, 2);
    root = bst_insert(root, 3);
    root = bst_insert(root, 0);
    assert(bst_get_min(root) == 0);

    bst_destroy(root);
}

void test_bst_get_max() {
    bst_node_t *root = NULL;
    root = bst_insert(root, 1);
    assert(bst_get_max(root) == 1);

    root = bst_insert(root, 2);
    root = bst_insert(root, 3);
    root = bst_insert(root, 4);
    assert(bst_get_max(root) == 4);

    bst_destroy(root);
}

void test_bst_is_valid() {
    bst_node_t *root = NULL;
    root = bst_insert(root, 1);
    assert(bst_is_valid(root));

    bst_node_t *new_node = (bst_node_t *) malloc(sizeof(bst_node_t));
    new_node->val = 2;
    new_node->left = NULL;
    new_node->right = NULL;
    root->left = new_node;
    assert(!bst_is_valid(root));

    bst_destroy(root);
}

void test_is_subtree_greater() {
    bst_node_t *root = NULL;
    root = bst_insert(root, 1);
    root = bst_insert(root, 2);
    root = bst_insert(root, 3);
    root = bst_insert(root, 4);
    assert(is_subtree_greater(root, 0));
    assert(!is_subtree_greater(root, 2));
    assert(!is_subtree_greater(root, 5));

    bst_destroy(root);
}

void test_is_subtree_lesser() {
    bst_node_t *root = NULL;
    root = bst_insert(root, 1);
    root = bst_insert(root, 2);
    root = bst_insert(root, 3);
    root = bst_insert(root, 0);
    assert(is_subtree_lesser(root, 4));
    assert(!is_subtree_lesser(root, 1));
    assert(!is_subtree_lesser(root->right, 1));
    assert(is_subtree_lesser(root->right, 4));

    bst_destroy(root);
}

void test_bst_delete_val() {
    bst_node_t *root = NULL;
    root = bst_insert(root, 1);
    root = bst_delete_val(root, 1);
    assert(root == NULL);

    root = bst_insert(root, 2);
    root = bst_insert(root, 1);
    root = bst_insert(root, 3);
    root = bst_insert(root, 4);

    assert(bst_delete_val(root, 3) != NULL);
    assert(!bst_is_val_in_tree(root, 3));
    assert(root->right->val == 4);

    bst_destroy(root);
}

void test_bst_get_successor() {
    bst_node_t *root = NULL;
    root = bst_insert(root, 1);
    assert(bst_get_successor(root, 1) == -1);
    assert(bst_get_successor(root, 2) == -1);

    root = bst_insert(root, 3);
    assert(bst_get_successor(root, 1) == 3);

    root = bst_insert(root, 2);
    root = bst_insert(root, 4);
    root = bst_insert(root, 6);
    assert(bst_get_successor(root, 4) == 6);
    assert(bst_get_successor(root, 2) == 3);

    bst_destroy(root);
}

void test_bst_get_predecessor() {
    bst_node_t *root = NULL;
    root = bst_insert(root, 1);
    assert(bst_get_predecessor(root, 1) == -1);
    assert(bst_get_predecessor(root, 2) == -1);

    root = bst_insert(root, 2);
    root = bst_insert(root, 3);
    assert(bst_get_predecessor(root, 3) == 2);

    root = bst_insert(root, 0);
    assert(bst_get_predecessor(root, 1) == 0);

    bst_destroy(root);
}

void run_all_tests() {
    test_bst_insert();
    test_bst_node_count();
    test_bst_is_val_in_tree();
    test_bst_get_height();
    test_bst_get_min();
    test_bst_get_max();
    test_bst_is_valid();
    test_is_subtree_greater();
    test_is_subtree_lesser();
    test_bst_delete_val();
    test_bst_get_successor();
    test_bst_get_predecessor();
}

int main() {
    run_all_tests();
    return 0;
}

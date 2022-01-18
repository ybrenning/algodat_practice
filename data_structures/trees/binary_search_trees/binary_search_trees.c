/**
 * @author Yannick Brenning
 * @date 11.12.2021
 * @brief Implementation of binary search trees
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "binary_search_trees.h"

bst_node_t *bst_insert(bst_node_t *root, const int val) {
    if (root == NULL) {
        root = (bst_node_t *) malloc(sizeof(bst_node_t));
        assert(root);

        root->val = val;
        root->left = NULL;
        root->right = NULL;
    } else if (val <= root->val){
        root->left = bst_insert(root->left, val);
    } else if (val >= root->val) {
        root->right = bst_insert(root->right, val);
    }

    return root;
}

void bst_destroy(bst_node_t *root) {
    if (root == NULL) {
        return;
    }

    bst_destroy(root->left);
    bst_destroy(root->right);
    free(root);
}

unsigned int bst_node_count(bst_node_t *root) {
    if (root == NULL) {
        return 0;
    } else {
        return 1 + bst_node_count(root->left) + bst_node_count(root->right);
    }
}

bool bst_is_val_in_tree(bst_node_t *root, const int val) {
    if (root == NULL) {
        return false;
    } else if (root->val == val) {
        return true;
    } else {
        bst_is_val_in_tree(root->left, val);
        bst_is_val_in_tree(root->right, val);
    }
}

int bst_get_height(bst_node_t *root) {
    if (root == NULL) {
        return -1;
    }

    int left_height = bst_get_height(root->left);
    int right_height = bst_get_height(root->right);

    return MAX(left_height, right_height) + 1;
}

int bst_get_min(bst_node_t *root) {
    if (root == NULL) {
        return -1;
    }

    bst_node_t *curr = root;
    while (curr->left != NULL) {
        curr = curr->left;
    }

    return curr->val;
}

int bst_get_max(bst_node_t *root) {
    if (root == NULL) {
        return -1;
    }

    bst_node_t *curr = root;
    while (curr->right != NULL) {
        curr = curr->right;
    }

    return curr->val;
}

bool bst_is_valid(bst_node_t *root) {
    if (root == NULL) {
        return true;
    }

    return (
            is_subtree_lesser(root->left, root->val)
            && is_subtree_greater(root->right, root->val)
            && bst_is_valid(root->left) && bst_is_valid(root->right)
            );
}

bool is_subtree_greater(bst_node_t *root, const int val) {
    if (root == NULL) {
        return true;
    }

    return (
            root->val >= val
            && is_subtree_greater(root->left, val)
            && is_subtree_greater(root->right, val)
            );
}

bool is_subtree_lesser(bst_node_t *root, const int val) {
    if (root == NULL) {
        return true;
    }

    return (
            root->val <= val && is_subtree_lesser(root->left, val)
            && is_subtree_lesser(root->right, val)
            );
}

bst_node_t *bst_delete_val(bst_node_t *root, const int val) {
    if (root == NULL) {
        return root;
    } else if (root->val > val) {
        root->left = bst_delete_val(root->left, val);
    } else if (root->val < val) {
        root->right = bst_delete_val(root->right, val);
    }

    // Node has been found and will now be deleted
    else {
        // Case 1: node has no children
        if (root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
            return root;
        }
        // Case 2: node has one child
        else if (root->left == NULL && root->right != NULL) {
            bst_node_t *temp = root;
            root = root->right;
            free(temp);
            return root;
        } else if (root->left != NULL && root->right == NULL) {
            bst_node_t *temp = root;
            root = root->left;
            free(temp);
        }
        // Case 3: node has two children
        else {
            // Set our deleted node to the min node of the right subtree
            // This ensures that all left nodes are smaller and all right nodes are greater or eq
            int min = bst_get_min(root->right);
            root->val = min;
            // Remove the node with the value we just copied
            root->right = bst_delete_val(root->right, min);
        }
    }

    return root;
}

int bst_get_successor(bst_node_t *root, const int val) {
    bst_node_t *curr = root;

    // Search the node in the tree - O(h)
    while (curr != NULL) {
        if (val < curr->val) {
            curr = curr->left;
        } else if (val > curr->val) {
            curr = curr->right;
        } else {
            break;
        }
    }

    // Check whether we could find the node with val
    if (curr == NULL) {
        return -1;
    }

    // Case 1: node has a right subtree - O(h)
    if (curr->right != NULL) {
        // Visit the smallest child in the right subtree
        bst_node_t *temp = curr->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }

        return temp->val;
    }

    // Case 2: node has no right subtree - O(h)
    else {
        bst_node_t *ancestor = root;
        bst_node_t *successor = NULL;

        while (ancestor != curr) {
            // Check if the ancestors val is higher than our found node
            if (curr->val < ancestor->val) {
                // This ancestor is a potential candidate for our successor
                successor = ancestor;
                // Keep lowering the value until we get close to curr
                ancestor = ancestor->left;
            } else {
                // Our curr node lies in the right subtree
                ancestor = ancestor->right;
            }
        }

        if (successor != NULL) {
            return successor->val;
        } else {
            return -1;
        }
    }
}

int bst_get_predecessor(bst_node_t *root, const int val) {
    bst_node_t *curr = root;
    while (curr != NULL) {
        if (val < curr->val) {
            curr = curr->left;
        } else if (val > curr->val) {
            curr = curr->right;
        } else {
            break;
        }
    }

    if (curr == NULL) {
        return -1;
    }

    // Case 1: curr has a left subtree
    if (curr->left != NULL) {
        bst_node_t *temp = curr->left;
        while (temp->right != NULL) {
            temp = temp->right;
        }

        return temp->val;
    }

    // Case 2: curr has no left subtree
    bst_node_t *ancestor = root;
    bst_node_t *predecessor = NULL;
    while (ancestor != curr) {
        if (val > ancestor->val) {
            // Potential candidate for pred
            predecessor = ancestor;
            ancestor = ancestor->right;
        } else {
            ancestor = ancestor->left;
        }
    }

    if (predecessor != NULL) {
        return predecessor->val;
    } else {
        return -1;
    }
}

void bst_print_inorder(bst_node_t *root) {
    if (root == NULL) {
        return;
    } else {
        bst_print_inorder(root->left);
        printf("%d ", root->val);
        bst_print_inorder(root->right);
    }
}

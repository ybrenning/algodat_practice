"""
Implementation of the binary search tree data structure
"""


class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert_node(self, val):
        """
        Insert a new node into the BST
        :param val: value of node to be inserted
        :return: None
        """
        if self.root is None:
            self.root = Node(val)
        else:
            self.__insert_rec(self.root, val)

    def __insert_rec(self, node, val):
        """
        Recursive function for the above implementation of insert_node
        :param node: current node being checked
        :param val: value of node to be inserted
        :return: None
        """
        # Go into left subtree
        if val <= node.val:
            # Try to insert a new node as the left
            # child of the current node
            if node.left is None:
                node.left = Node(val)
            elif node.left is not None:
                self.__insert_rec(node.left, val)
        # Go into right subtree
        elif val > node.val:
            # Try to insert a new node as the right
            # child of the current node
            if node.right is None:
                node.right = Node(val)
            elif node.right is not None:
                self.__insert_rec(node.right, val)

    def inorder_traversal(self):
        """
        Print content of BST using inorder traversal
        (Smallest to largest values)
        :return: None
        """
        if self.root is None:
            return
        else:
            self.__inorder_traversal_rec(self.root)
            print("")

    def __inorder_traversal_rec(self, node):
        """
        Recursive function for the above implementation
        :param node:
        :return: None
        """
        if node is None:
            return
        else:
            # Get to leftmost node and begin printing
            self.__inorder_traversal_rec(node.left)
            print(str(node.val), end=" ")
            self.__inorder_traversal_rec(node.right)

    def get_height(self):
        """
        Calculate the height of the BST's root
        (Height = largest number of edges to
        most distant leaf node)
        :return: Height as integer
        """
        return self.__get_height_rec(self.root)

    def __get_height_rec(self, node):
        """
        Recursive function for the above implementation
        :param node: current node being traversed
        :return: Height as integer
        """
        if node is None:
            return -1
        # Check left and right trees for height and return highest
        left_height = self.__get_height_rec(node.left)
        right_height = self.__get_height_rec(node.right)

        return max(left_height, right_height) + 1

    def get_min(self):
        return BinarySearchTree.__get_min(self.root)

    @staticmethod
    def __get_min(node):
        curr = node
        while curr.left is not None:
            curr = curr.left
        return curr.val

    def get_max(self):
        curr = self.root
        while curr.right is not None:
            curr = curr.right
        return curr.val

    def find_node(self, val):
        """
        Find node with value inside BST
        :param val: value to search for
        :return: boolean
        """
        return self.__find_rec(self.root, val)

    def __find_rec(self, node, val):
        """
        Recursive function for the above implementation
        :param node: current node being checked
        :param val: value to search for
        :return: boolean
        """
        if node is None:
            return False
        elif node.val == val:
            return True
        elif node.val > val:
            return self.__find_rec(node.left, val)
        else:
            return self.__find_rec(node.right, val)

    def is_valid(self):
        """
        Check if a BST is valid by definition
        :return: boolean
        """
        return self.__is_valid(self.root)

    def __is_valid(self, node):
        """
        Recursive function for the above implementation
        :param node: current node of which the subtrees will be checked
        :return: boolean
        """
        if node is None:
            return True
        # Check if the left and right subtrees are lesser and greater
        # (meaning the definition is true for the current node)
        # Then repeat this check for every node in the tree
        return self.is_subtree_lesser(node.left, node.val) and self.is_subtree_greater(node.right, node.val) \
               and self.__is_valid(node.left) and self.__is_valid(node.right)

    def is_subtree_greater(self, node, val):
        if node is None:
            return True
        return node.val > val and self.is_subtree_greater(node.left, val) and self.is_subtree_greater(node.right, val)

    def is_subtree_lesser(self, node, val):
        if node is None:
            return True
        return node.val <= val and self.is_subtree_lesser(node.left, val) and self.is_subtree_lesser(node.right, val)

    def delete_node(self, val):
        """
        Remove a node from the tree
        :param val: value of node to be deleted
        :return: root of updated tree
        """
        return self.__delete_node_rec(self.root, val)

    def __delete_node_rec(self, node, val):
        """
        Recursive function for the above implementation
        :param node: current node being checked
        :param val: value of node to be deleted
        :return: root of updated tree
        """
        if node is None:
            return node
        # Search the left subtree
        elif node.val > val:
            node.left = self.__delete_node_rec(node.left, val)
        # Search the right subtree
        elif node.val < val:
            node.right = self.__delete_node_rec(node.right, val)
        # If the val is equal to the current node's val, then delete the current node
        else:
            # Case 1 and 2: node has one or no children
            if node.left is None:
                temp = node.right
                node = None
                return temp
            elif node.right is None:
                temp = node.left
                node = None
                return temp
            # Case 3: Node with two children
            # Get the lowest value of our right subtree
            min_val = self.__get_min(node.right)
            # Set the new node to this lowest value
            # and remove the duplicate value from the right subtree
            node.val = min_val
            node.right = self.__delete_node_rec(node.right, min_val)

        return node


def main():
    # Generate the following tree:
    #
    #           50
    #         /    \
    #       40      60
    #              /  \
    #            55   80

    bst = BinarySearchTree()
    bst.insert_node(50)
    bst.insert_node(40)
    bst.insert_node(60)
    bst.insert_node(80)
    bst.insert_node(55)
    bst.inorder_traversal()

    invalid_bst = BinarySearchTree()
    invalid_bst.insert_node(20)
    invalid_bst.root.left = Node(30)

    print(invalid_bst.is_valid())
    print(bst.is_valid())

    bst.delete_node(80)
    bst.inorder_traversal()


if __name__ == "__main__":
    main()

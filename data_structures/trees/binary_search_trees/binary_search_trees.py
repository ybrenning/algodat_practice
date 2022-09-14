"""
Implementation of binary search trees.
"""

from __future__ import annotations


class Node:
    def __init__(self, val: int) -> None:
        self.val = val
        self.left: Node | None = None
        self.right: Node | None = None


class BinarySearchTree:
    def __init__(self) -> None:
        self.root: Node | None = None

    def insert(self, val: int) -> None:
        if self.root is None:
            self.root = Node(val)
        else:
            self.__insert(self.root, val)

    def __insert(self, node: Node, val: int) -> None:
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
                self.__insert(node.left, val)
        # Go into right subtree
        elif val > node.val:
            # Try to insert a new node as the right
            # child of the current node
            if node.right is None:
                node.right = Node(val)
            elif node.right is not None:
                self.__insert(node.right, val)

    def inorder_traversal(self) -> None:
        """
        Print content of BST using inorder traversal
        (Smallest to largest values)
        :return: None
        """

        if self.root is None:
            return
        else:
            self.__inorder_traversal(self.root)
            print("")

    def __inorder_traversal(self, node: Node) -> None:
        """
        Recursive function for the above implementation
        :param node: current node being printed
        :return: None
        """

        if node is None:
            return
        else:
            # Get to leftmost node and begin printing
            self.__inorder_traversal(node.left)
            print(str(node.val), end=" ")
            self.__inorder_traversal(node.right)

    def get_height(self) -> int:
        """
        Calculate the height of the BST's root
        (Height = largest number of edges to
        most distant leaf node)
        :return: Height as integer
        """

        return self.__get_height(self.root)

    def __get_height(self, node: Node) -> int:
        """
        Recursive function for the above implementation
        :param node: current node being traversed
        :return: Height as integer
        """

        if node is None:
            return -1
        # Check left and right trees for height and return highest
        left_height = self.__get_height(node.left)
        right_height = self.__get_height(node.right)

        return max(left_height, right_height) + 1

    def get_min(self) -> int:
        return BinarySearchTree.__get_min(self.root)

    @staticmethod
    def __get_min(node: Node) -> int:
        """
        Finds minimum value of a subtree
        :param node: root of the tree or subtree
        :return: smallest value in subtree
        """

        curr = node
        while curr.left is not None:
            curr = curr.left
        return curr.val

    def get_max(self) -> int:
        return BinarySearchTree.__get_max(self.root)

    @staticmethod
    def __get_max(node: Node) -> int:
        """
        Finds maximum value of a subtree
        :param node: root of the tree or subtree
        :return: largest value in subtree
        """

        curr = node
        while curr is not None:
            curr = curr.right
        return curr.val

    def find_node(self, val: int) -> bool:
        """
        Find node with value inside BST
        :param val: value to search for
        :return: boolean
        """

        return self.__find(self.root, val)

    def __find(self, node: Node, val: int) -> bool:
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
            return self.__find(node.left, val)
        else:
            return self.__find(node.right, val)

    def is_valid(self) -> bool:
        """
        Check if a BST is valid by [definition](https://en.wikipedia.org/wiki/Binary_search_tree#Definition)
        :return: validity status
        """

        return self.__is_valid(self.root)

    def __is_valid(self, node: Node) -> bool:
        """
        Recursive function for the above implementation
        :param node: current node of which the subtrees will be checked
        :return: validity of current subtree
        """

        if node is None:
            return True

        # Check if the left and right subtrees are lesser and greater
        # (meaning the definition is true for the current node)
        # Then repeat this check for every node in the tree
        return (
            self.is_subtree_lesser(node.left, node.val)
            and self.is_subtree_greater(node.right, node.val)
            and self.__is_valid(node.left)
            and self.__is_valid(node.right)
        )

    def is_subtree_greater(self, node: Node, val: int) -> bool:
        if node is None:
            return True

        return (
            node.val > val
            and self.is_subtree_greater(node.left, val)
            and self.is_subtree_greater(node.right, val)
        )

    def is_subtree_lesser(self, node: Node, val: int) -> bool:
        if node is None:
            return True

        return (
            node.val <= val
            and self.is_subtree_lesser(node.left, val)
            and self.is_subtree_lesser(node.right, val)
        )

    def delete(self, val: int) -> Node:
        """
        Remove a node from the tree
        :param val: value of node to be deleted
        :return: root of updated tree
        """

        return self.__delete_node(self.root, val)

    def __delete_node(self, node: Node, val: int) -> Node | None:
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
            node.left = self.__delete_node(node.left, val)
        # Search the right subtree
        elif node.val < val:
            node.right = self.__delete_node(node.right, val)
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
            node.right = self.__delete_node(node.right, min_val)

        return node

    def get_successor(self, val: int) -> int:
        """
        Find the next highest number in the tree
        :param val: value of node to get successor of
        :return: value of successor node
        """

        curr = self.root
        while curr is not None:
            if val < curr.val:
                curr = curr.left
            elif val > curr.val:
                curr = curr.right
            else:
                break

        # Check whether we could find the node or not
        if curr is None:
            return -1

        # Case 1: node has a right subtree
        if curr.right is not None:
            temp = curr.right
            # Find the smallest value in the right subtree
            while temp.left is not None:
                temp = temp.left

            return temp.val

        # Case 2: node has no right subtree
        else:
            ancestor = self.root
            successor = None

            while ancestor is not curr:
                # Check if ancestors val is higher than our found node
                if curr.val < ancestor.val:
                    # Found a potential candidate for the successor
                    successor = ancestor
                    # Keep lowering the val until we get
                    # as close as possible to our found node
                    ancestor = ancestor.left
                else:
                    # Our successor lies in the right subtree
                    ancestor = ancestor.right

            if successor is None:
                # We tried to find the succ of
                # our highest node in the BST
                return -1
            else:
                return successor.val

    def get_predecessor(self, val: int) -> int:
        """
        Find the next lowest number in the tree
        :param val: value of node to get predecessor of
        :return: value of predecessor node
        """

        curr = self.root
        while curr is not None:
            if val < curr.val:
                curr = curr.left
            elif val > curr.val:
                curr = curr.right
            else:
                break

        if curr is None:
            return -1

        # Case 1: curr has a left subtree
        if curr.left is not None:
            # Get the highest val in the left subtree
            temp = curr.left
            while temp.right is not None:
                temp = temp.right

            return temp.val

        # Case 2: curr has no left subtree
        ancestor = self.root
        predecessor = None

        while ancestor is not curr:
            if val > ancestor.val:
                predecessor = ancestor
                ancestor = ancestor.right
            else:
                ancestor = ancestor.left

        if predecessor is None:
            # We tried to find the pred
            # of the minimum node
            return -1
        else:
            return predecessor.val


def main():

    # Generate the following tree:
    #
    #           50
    #         /    \
    #       40      60
    #              /  \
    #            55   80

    bst = BinarySearchTree()
    bst.insert(50)
    bst.insert(40)
    bst.insert(60)
    bst.insert(80)
    bst.insert(55)
    bst.inorder_traversal()

    invalid_bst = BinarySearchTree()
    invalid_bst.insert(20)
    invalid_bst.root.left = Node(30)

    print(invalid_bst.is_valid())
    print(bst.is_valid())

    bst.delete(80)
    bst.inorder_traversal()

    print(bst.get_successor(55))
    print(bst.get_predecessor(60))


if __name__ == "__main__":
    main()

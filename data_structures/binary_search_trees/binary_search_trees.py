class Node:
    def __init__(self, val):
        self.val = val
        self.left = None
        self.right = None


class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert_node(self, val):
        if self.root is None:
            self.root = Node(val)
        else:
            self.__insert_rec(self.root, val)

    def __insert_rec(self, node, val):
        if val <= node.val:
            if node.left is None:
                node.left = Node(val)
            elif node.left is not None:
                self.__insert_rec(node.left, val)
        elif val > node.val:
            if node.right is None:
                node.right = Node(val)
            elif node.right is not None:
                self.__insert_rec(node.right, val)

    def inorder_traversal(self):
        if self.root is None:
            return
        else:
            self.__inorder_traversal_rec(self.root)

    def __inorder_traversal_rec(self, node):
        if node is None:
            return
        else:
            self.__inorder_traversal_rec(node.left)
            print(str(node.val))
            self.__inorder_traversal_rec(node.right)

    def get_height(self):
        return self.__get_height_rec(self.root)

    def __get_height_rec(self, node):
        if node is None:
            return -1
        left_height = self.__get_height_rec(node.left)
        right_height = self.__get_height_rec(node.right)

        return max(left_height, right_height) + 1

    def get_min(self):
        curr = self.root
        while curr.left is not None:
            curr = curr.left
        return curr.val

    def get_max(self):
        curr = self.root
        while curr.right is not None:
            curr = curr.right
        return curr.val

    def find_node(self, val):
        return self.__find_rec(self.root, val)

    def __find_rec(self, node, val):
        if node is None:
            return False
        elif node.val == val:
            return True
        elif node.val > val:
            return self.__find_rec(node.left, val)
        else:
            return self.__find_rec(node.right, val)

    def is_valid(self):
        return self.__is_valid(self.root)

    def __is_valid(self, node):
        if node is None:
            return True
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


def main():
    bst = BinarySearchTree()
    bst.insert_node(50)
    bst.insert_node(40)
    bst.insert_node(60)
    bst.insert_node(80)
    bst.inorder_traversal()

    bst2 = BinarySearchTree()
    bst2.insert_node(20)
    bst2.root.left = Node(30)
    print(bst.is_valid())


if __name__ == "__main__":
    main()

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
            self.insert_rec(self.root, val)

    def insert_rec(self, node, val):
        if val <= node.val:
            if node.left is None:
                node.left = Node(val)
            elif node.left is not None:
                self.insert_rec(node.left, val)
        elif val > node.val:
            if node.right is None:
                node.right = Node(val)
            elif node.right is not None:
                self.insert_rec(node.right, val)

    def inorder_traversal(self, root):
        if root is None:
            return
        self.inorder_traversal(root.left)
        print(root.val, end=" ")
        self.inorder_traversal(root.right)

    def get_height(self, root):
        if root is None:
            return -1
        left_height = self.get_height(root.left)
        right_height = self.get_height(root.right)

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


def main():
    bst = BinarySearchTree()
    bst.insert_node(50)
    bst.insert_node(40)
    bst.insert_node(60)
    bst.insert_node(80)
    bst.inorder_traversal(bst.root)


if __name__ == "__main__":
    main()

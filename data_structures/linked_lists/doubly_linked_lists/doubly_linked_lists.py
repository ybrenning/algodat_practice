"""
Implementation of Doubly Linked Lists.
"""

from typing import Any


class Node:
    def __init__(self, val: Any) -> None:
        self.val = val
        self.next: Node | None= None
        self.prev: Node | None = None


class DoublyLinkedList:
    def __init__(self) -> None:
        self.head: Node | None = None
        self.size = 0

    def is_empty(self) -> bool:
        return self.size == 0

    def append(self, val: Any) -> None:
        if self.is_empty():
            self.head = Node(val)
        else:
            curr = self.head
            while curr.next is not None:
                curr = curr.next
            new_node = Node(val)
            new_node.prev = curr

            curr.next = new_node
        self.size += 1

    def push(self, val: Any) -> None:
        if self.is_empty():
            self.head = Node(val)
        else:
            new_node = Node(val)
            new_node.prev = None
            new_node.next = self.head

            self.head.prev = new_node
            self.head = new_node

        self.size += 1

    def insert(self, val: Any, index: int) -> None:
        if index < 0 or index > self.size:
            raise IndexError("Index out of bounds")
        elif index == 0:
            self.push(val)
        elif index == self.size:
            self.append(val)
        else:
            curr = self.head
            for _ in range(0, index - 1):
                curr = curr.next

            new_node = Node(val)
            new_node.prev = curr
            new_node.next = curr.next

            curr.next = new_node

            self.size += 1

    def remove_last(self) -> Any:
        if self.is_empty():
            raise IndexError("Removing from empty list")
        elif self.size == 1:
            retval = self.head.val
            self.head = None
        else:
            curr = self.head
            while curr.next.next is not None:
                curr = curr.next

            retval = curr.next.val
            curr.next = None

        self.size -= 1
        return retval

    def pop(self) -> Any:
        if self.is_empty():
            raise IndexError("Pop from empty list")
        else:
            retval = self.head.val
            new_head = self.head.next

            self.head = None
            self.head = new_head

        self.size -= 1
        return retval

    def delete(self, index: int) -> Any:
        if index < 0 or index > self.size:
            raise IndexError("Index out of bounds")
        elif index == 0:
            return self.pop()
        elif index == self.size:
            return self.remove_last()
        else:
            curr = self.head
            for _ in range(0, index - 1):
                curr = curr.next

            retval = curr.next.val

            if curr.next.next is not None:
                curr.next.next.prev = curr

            curr.next = curr.next.next

        self.size -= 1
        return retval

    def get(self, index: int) -> Any:
        if self.is_empty() or index < 0 or index >= self.size:
            raise IndexError("Index out of bounds")
        else:
            curr = self.head
            for _ in range(0, index):
                curr = curr.next

            return curr.val

    def reverse(self) -> None:
        if not self.size <= 1:
            curr = self.head
            temp = None
            while curr is not None:
                temp = curr.prev
                curr.prev = curr.next
                curr.next = temp

                curr = curr.prev

            self.head = temp.prev

    def __str__(self) -> str:
        if self.is_empty():
            return "[ ]"
        else:
            output = "[ "
            curr = self.head
            for _ in range(0, self.size):
                output += str(curr.val) + " "
                curr = curr.next

            output += "]"

        return output


def main():

    # Driver code to construct the following linked list:
    #
    # None <- 1 -> <- 2 -> <- 3 -> <- 4 -> <- 5 -> None

    linked_list = DoublyLinkedList()
    linked_list.append(1)
    linked_list.append(2)
    linked_list.append(3)
    linked_list.append(4)
    linked_list.append(5)

    # Demonstrate basic operations on linked list

    linked_list.push(0)
    linked_list.insert(6, 5)
    linked_list.remove_last()
    linked_list.pop()
    linked_list.delete(4)
    print(linked_list.get(2))

    linked_list.append("A")

    print(linked_list)

    # Swaps each prev and next pointer
    # using a temp node to store the prev node

    # None <- old_head -> <- node_1 -> ... <- temp -> <- old_tail -> None

    # On the final step, curr is at the old_tail node, meaning temp is the prev
    # (the second node of the new list, second last of old list)
    # Set the head variable to be the prev value of the temp node (old_tail)

    linked_list.reverse()

    print(linked_list)


if __name__ == "__main__":
    main()

"""
Implementation of Singly Linked Lists.
"""

from __future__ import annotations
from typing import Any


class Node:
    def __init__(self, val: Any) -> None:
        self.val = val
        self.next: Node | None = None


class SinglyLinkedList:
    def __init__(self) -> None:
        self.head: Node | None = None
        self.size = 0

    def __str__(self) -> str:
        output = "[ "

        curr = self.head
        while curr is not None:
            output += f"{curr.val} "
            curr = curr.next

        output += "]"

        return output

    def __len__(self):
        return self.size

    def is_empty(self) -> bool:
        return self.size == 0

    def append(self, val: Any) -> None:
        """
        Inserts node at the end of the list
        :param val: value to be stored in node
        :return: None
        >>> linked_list = SinglyLinkedList()
        >>> linked_list.append(1)
        >>> linked_list.append(2)
        >>> linked_list.append(3)
        >>> print(linked_list)
        [ 1 2 3 ]
        """

        if self.is_empty():
            self.push(val)
        else:
            curr = self.head
            for _ in range(0, self.size - 1):
                curr = curr.next
            curr.next = Node(val)

            self.size += 1

    def push(self, val: Any) -> None:
        """
        Inserts node at the front of the linked list
        :param val: value to be stored in node
        :return: None
        >>> linked_list = SinglyLinkedList()
        >>> linked_list.push(1)
        >>> linked_list.push(2)
        >>> linked_list.push(3)
        >>> print(linked_list)
        [ 3 2 1 ]
        """

        if self.is_empty():
            self.head = Node(val)
        else:
            new_node = Node(val)
            new_node.next = self.head
            self.head = new_node

        self.size += 1

    def insert(self, val: Any, index: int) -> None:
        """
        Insert new node at the given index
        :param val: value to be stored in node
        :param index: position of insertion
        :return: None
        >>> linked_list = SinglyLinkedList()
        >>> linked_list.append(1)
        >>> linked_list.append(2)
        >>> linked_list.append(3)
        >>> linked_list.append(4)
        >>> linked_list.insert(5, 1)
        >>> print(linked_list)
        [ 1 5 2 3 4 ]
        >>> linked_list.insert(6, 3)
        >>> print(linked_list)
        [ 1 5 2 6 3 4 ]
        """

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

            temp = curr.next
            curr.next = new_node
            new_node.next = temp

            self.size += 1

    def delete(self, index: int) -> Any:
        """
        Remove node at index
        :param index: index of node
        :return: value of deleted node
        >>> linked_list = SinglyLinkedList()
        >>> linked_list.append(1)
        >>> linked_list.append(2)
        >>> linked_list.append(3)
        >>> linked_list.append(4)
        >>> linked_list.delete(0)
        >>> print(linked_list)
        [ 2 3 4 ]
        >>> linked_list.delete(1)
        >>> print(linked_list)
        [ 2 4 ]
        >>> linked_list.delete(len(linked_list) - 1)
        >>> print(linked_list)
        [ 2 ]
        """

        if self.is_empty():
            raise IndexError("Remove from empty list")
        elif index < 0 or index >= self.size:
            raise IndexError("Index out of bounds")

        curr = self.head
        if index == 0:
            self.head = self.head.next
        elif index == self.size - 1:
            for _ in range(0, self.size - 1):
                curr = curr.next
            curr.next = None
        else:
            for _ in range(0, index - 1):
                curr = curr.next
            curr.next = curr.next.next

        self.size -= 1

    def get(self, index: int) -> Any:
        """
        Returns value of node at index
        :param index: position of node
        :return: value of node
        >>> linked_list = SinglyLinkedList()
        >>> linked_list.append(1)
        >>> linked_list.append(2)
        >>> linked_list.append(3)
        >>> print(linked_list.get(1))
        2
        """

        if self.is_empty() or index < 0 or index >= self.size:
            raise IndexError("Index out of bounds")

        if index == 0:
            return self.head.val
        else:
            curr = self.head
            for _ in range(0, index):
                curr = curr.next

            return curr.val

    def reverse(self) -> None:
        """
        Reverses the list
        :return: None
        >>> linked_list = SinglyLinkedList()
        >>> linked_list.append(1)
        >>> linked_list.append(2)
        >>> linked_list.append(3)
        >>> linked_list.reverse()
        >>> print(linked_list)
        [ 3 2 1 ]
        """

        if not self.is_empty() and not self.size == 1:
            curr = self.head
            prev = None
            while curr is not None:
                next = curr.next
                curr.next = prev
                prev = curr
                curr = next

            self.head = prev


def main():
    # Driver code to demonstrate basic operations

    linked_list = SinglyLinkedList()
    linked_list.push(3)
    print(linked_list.size)

    linked_list.append(4)
    print(linked_list.size)

    linked_list.append(50)
    print(linked_list.size)

    linked_list.insert(30, 3)
    print(linked_list.size)
    print(linked_list)

    print(linked_list.get(2))
    print(linked_list.get(0))
    print(linked_list)

    linked_list.delete(2)
    print(linked_list)

    linked_list.reverse()
    print(linked_list)


if __name__ == "__main__":
    main()

"""
Implementation of Singly Linked Lists.
"""

from __future__ import annotations
from typing import Any


class Node:
    """Implementation of a node which contains a value and points to another node.

    The node stores data of any type and a pointer to another node, which is set to None by default.

    See also:
        SinglyLinkedList
    """

    def __init__(self, val: Any) -> None:
        self.val: Any = val
        self.next: Node | None = None


class SinglyLinkedList:
    """Implementation of a singly linked list.

    The list is initialized as "empty" with a head Node set to None and a size set to zero.

    See also:
        https://en.wikipedia.org/wiki/Linked_list
    """

    def __init__(self) -> None:
        self.head: Node | None = None
        self.size: int = 0

    def __str__(self) -> str:
        output = "[ "

        curr = self.head
        while curr is not None:
            output += f"{curr.val} "
            curr = curr.next

        output += "]"

        return output

    def __len__(self) -> int:
        return self.size

    def is_empty(self) -> bool:
        return self.size == 0

    def append(self, val: Any) -> None:
        """Inserts node at the end of the list.

        Args:
            val: Value to be stored in node

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
                assert curr is not None
                curr = curr.next

            assert curr is not None
            curr.next = Node(val)

            self.size += 1

    def push(self, val: Any) -> None:
        """Inserts node at the front of the linked list.

        Args:
            val: Value to be stored in node

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
        """Insert new node at the given index.

        Args:
            val: Value to be stored in node
            index: Position of insertion

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
                assert curr is not None
                curr = curr.next

            new_node = Node(val)

            assert curr is not None
            temp = curr.next
            curr.next = new_node
            new_node.next = temp

            self.size += 1

    def pop(self) -> Any:
        """Removes node from end of list.

        Returns:
            Value of deleted node

        >>> linked_list = SinglyLinkedList()
        >>> linked_list.append(1)
        >>> linked_list.append(2)
        >>> linked_list.append(3)
        >>> linked_list.append(4)
        >>> linked_list.pop()
        4
        >>> print(linked_list)
        [ 1 2 3 ]
        >>> linked_list.pop()
        3
        >>> print(linked_list)
        [ 1 2 ]
        """

        if self.is_empty():
            raise IndexError("Remove from empty list")

        curr = self.head
        for _ in range(0, self.size - 2):
            assert curr is not None
            curr = curr.next
        assert curr is not None and curr.next is not None

        retval = curr.next.val
        curr.next = None

        self.size -= 1
        return retval

    def delete(self, index: int) -> Any:
        """Remove node at index.

        Args:
            index: Index of node

        Returns:
            Value of deleted node

        >>> linked_list = SinglyLinkedList()
        >>> linked_list.append(1)
        >>> linked_list.append(2)
        >>> linked_list.append(3)
        >>> linked_list.append(4)
        >>> linked_list.delete(0)
        1
        >>> print(linked_list)
        [ 2 3 4 ]
        >>> linked_list.delete(1)
        3
        >>> print(linked_list)
        [ 2 4 ]
        >>> linked_list.delete(len(linked_list) - 1)
        4
        >>> print(linked_list)
        [ 2 ]
        """

        if self.is_empty():
            raise IndexError("Remove from empty list")
        elif index < 0 or index >= self.size:
            raise IndexError("Index out of bounds")

        assert self.head is not None
        curr = self.head

        if index == 0:
            retval = self.head.val
            self.head = self.head.next
        elif index == self.size - 1:
            return self.pop()
        else:
            for _ in range(0, index - 1):
                assert curr is not None
                curr = curr.next

            assert curr is not None and curr.next is not None
            retval: Any = curr.next.val
            curr.next = curr.next.next

        self.size -= 1
        return retval

    def get(self, index: int) -> Any:
        """Returns value of node at index.

        Args:
            index: Position of node

        Returns:
            Value of node

        >>> linked_list = SinglyLinkedList()
        >>> linked_list.append(1)
        >>> linked_list.append(2)
        >>> linked_list.append(3)
        >>> print(linked_list.get(1))
        2
        """

        if self.is_empty() or index < 0 or index >= self.size:
            raise IndexError("Index out of bounds")

        assert self.head is not None
        if index == 0:
            return self.head.val
        else:
            curr = self.head
            for _ in range(0, index):
                assert curr is not None
                curr = curr.next

            assert curr is not None
            return curr.val

    def reverse(self) -> None:
        """Reverses the list.

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


def main() -> None:
    import doctest

    doctest.testmod()


if __name__ == "__main__":
    main()

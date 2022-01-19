"""
Implementation of priority queues using max heap.
"""

from __future__ import annotations


class MaxHeap:
    def __init__(self) -> None:
        self.data: list[int] = []

    def swap(self, index_1: int, index_2: int) -> None:
        temp = self.data[index_1]
        self.data[index_1] = self.data[index_2]
        self.data[index_2] = temp

    @staticmethod
    def get_left_child_index(index: int) -> int:
        return (2 * index) + 1

    @staticmethod
    def get_right_child_index(index: int) -> int:
        return (2 * index) + 2

    @staticmethod
    def get_parent_index(index: int) -> int:
        return (index - 1) // 2

    def has_left_child(self, index: int) -> bool:
        return self.get_left_child_index(index) < len(self.data)

    def has_right_child(self, index: int) -> bool:
        return self.get_right_child_index(index) < len(self.data)

    def has_parent(self, index: int) -> bool:
        return self.get_parent_index(index) >= 0

    def get_left_child(self, index: int) -> int:
        return self.data[self.get_left_child_index(index)]

    def get_right_child(self, index: int) -> int:
        return self.data[self.get_right_child_index(index)]

    def get_parent(self, index: int) -> int:
        return self.data[self.get_parent_index(index)]

    def is_empty(self) -> bool:
        return len(self.data) == 0

    def insert(self, val: int) -> None:
        """
        Insert a new value into the heap
        :param val: value to be inserted
        :return: None
        """

        self.data.append(val)

        # Heapify up: rearranges heap by moving
        # element from the bottom (end of list) up
        i = len(self.data) - 1
        while self.has_parent(i) and self.get_parent(i) < self.data[i]:
            self.swap(self.get_parent_index(i), i)
            i = self.get_parent_index(i)

    def extract_max(self) -> int:
        """
        Remove the top (max) element from the heap
        :return: value of top element
        """

        if self.is_empty():
            raise IndexError("Extract from empty heap")

        # Get the top value and replace it with the bottom value
        retval = self.data[0]
        self.data[0] = self.data.pop()

        # Heapify down: rearranges heap by
        # moving element from the top (front of list) down
        i = 0
        while self.has_left_child(i):
            larger_child_index = self.get_left_child_index(i)
            if self.has_right_child(i) and self.get_right_child(i) > self.get_left_child(i):
                larger_child_index = self.get_right_child_index(i)

            if self.data[i] > self.data[larger_child_index]:
                break
            else:
                self.swap(i, larger_child_index)#

            i = larger_child_index

        return retval


def main():

    # Generates the following heap:
    #           50
    #         /  \
    #       4     2
    #     / \
    #    1   3

    h = MaxHeap()
    h.insert(1)
    h.insert(50)
    h.insert(2)
    h.insert(3)
    h.insert(4)

    print(h.data)
    print(h.extract_max())
    print(h.data)


if __name__ == "__main__":
    main()

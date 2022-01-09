"""
Implementation of queues using lists.
"""

from typing import Any


class Queue:
    def __init__(self) -> None:
        self.queue: list[Any] = []

    def is_empty(self) -> bool:
        return len(self.queue) == 0

    def enqueue(self, item: Any) -> None:
        self.queue.append(item)

    def dequeue(self) -> Any:
        if self.is_empty():
            raise IndexError("Dequeue from empty queue")
        return self.queue.pop(0)

    def __str__(self) -> str:
        output = "[ "
        for i in range (0, len(self.queue)):
            output += str(self.queue[i]) + " "

        return output + "]"


def main():

    # Driver code to construct the following queue:
    #
    #           4 - 22 - 1 - 30

    my_queue = Queue()
    my_queue.enqueue(4)
    my_queue.enqueue(22)
    my_queue.enqueue(1)
    my_queue.enqueue(30)
    print(my_queue)

    # Demonstrate  dequeue operation

    my_queue.dequeue()
    my_queue.dequeue()
    print(my_queue)

    print(my_queue.isempty())


if __name__ == "__main__":
    main()

class Queue:
    def __init__(self):
        self.queue = []

    def isempty(self):
        return len(self.queue) == 0

    def enqueue(self, item):
        self.queue.append(item)

    def dequeue(self):
        if self.isempty():
            return None
        return self.queue.pop(0)

    def __str__(self):
        output = "[ "
        for i in range (0, len(self.queue)):
            output += str(self.queue[i]) + " "
        return output + "]"


if __name__ == "__main__":
    my_queue = Queue()
    my_queue.enqueue(4)
    my_queue.enqueue(22)
    my_queue.enqueue(1)
    my_queue.enqueue(77)
    print(my_queue)

    my_queue.dequeue()
    my_queue.dequeue()
    print(my_queue)

    print(my_queue.isempty())

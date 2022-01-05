class Node:
    def __init__(self, val):
        self.val = val
        self.next = None
        self.prev = None


class DoublyLinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def is_empty(self):
        return self.size == 0

    def append(self, val):
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

    def push(self, val):
        if self.is_empty():
            self.head = Node(val)
        else:
            new_node = Node(val)
            new_node.prev = None
            new_node.next = self.head

            self.head.prev = new_node
            self.head = new_node

        self.size += 1

    def insert(self, val, index):
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

    def remove_last(self):
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

    def pop(self):
        if self.is_empty():
            raise IndexError("Pop from empty list")
        else:
            retval = self.head.val
            new_head = self.head.next

            self.head = None
            self.head = new_head

        self.size -= 1
        return retval

    def delete(self, index):
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

    def __str__(self):
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
    linked_list = DoublyLinkedList()
    linked_list.append(1)
    linked_list.append(2)
    linked_list.append(3)
    linked_list.append(4)
    linked_list.append(5)
    linked_list.push(0)
    linked_list.insert(60, 5)
    linked_list.remove_last()
    linked_list.pop()
    linked_list.delete(4)

    print(linked_list)


if __name__ == "__main__":
    main()

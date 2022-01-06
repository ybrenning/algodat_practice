class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


class LinkedList:
    def __init__(self):
        self.head = None
        self.size = 0

    def get(self, index):
        """
        Returns value of node at index
        :param index: index of node
        :return: value of node
        """
        if index < 0 or index >= self.size:
            return -1
        elif index == 0:
            return self.head.val
        else:
            curr = self.head
            for _ in range(0, index):
                curr = curr.next

            return curr.val

    def push(self, val):
        """
        Inserts node at the front of the linked list
        :param val: value to be stored in node
        :return: None
        """
        if self.head is None:
            self.head = Node(val)
        else:
            new_node = Node(val)
            new_node.next = self.head
            self.head = new_node

        self.size += 1

    def append(self, val):
        """
        Inserts node at the end of the linked list
        :param val: value to be stored in node
        :return: None
        """
        if self.size == 0:
            self.push(val)
        else:
            curr = self.head
            for _ in range(0, self.size - 1):
                curr = curr.next
            curr.next = Node(val)

            self.size += 1

    def insert(self, val, index):
        """
        Insert new node at index
        :param val: value to be stored in node
        :param index: index of new node
        :return: None
        """
        if index < 0 or index > self.size:
            return
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

    def delete(self, index):
        """
        Remove node at index
        :param index: index of node
        :return: None
        """
        curr = self.head
        if index < 0 or index >= self.size:
            return
        elif index == 0:
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

    def __str__(self):
        output = "["
        curr = self.head
        while curr is not None:
            output += " " + str(curr.val) + ","
            curr = curr.next

        output = output[:-1]
        output += " ]"

        return output


def main():
    linked_list = LinkedList()
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
    print(linked_list.get(5))
    print(linked_list)

    linked_list.delete(2)
    print(linked_list)


if __name__ == "__main__":
    main()

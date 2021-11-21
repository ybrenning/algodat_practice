class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


class LinkedList:
    def __init__(self):
        self.size = 0
        self.head = None

    def get_at_index(self, index):
        if index < 0 or index >= self.size:
            return -1
        elif index == 0:
            return self.head.val
        else:
            curr = self.head
            for i in range(0, index):
                curr = curr.next
            return curr.val

    def add_at_head(self, val):
        """
        Inserts node at the front of the linkedlist
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

    def add_at_tail(self, val):
        """
        Inserts node at the end of the linkedlist
        :param val: value to be stored in node
        :return: None
        """
        if self.size == 0:
            self.add_at_head(val)
        else:
            curr = self.head
            for i in range(0, self.size - 1):
                curr = curr.next
            curr.next = Node(val)
            self.size += 1

    def add_at_index(self, val, index):
        """
        Insert new node at index
        :param val: value to be stored in node
        :param index: index of new node
        :return: None
        """
        if index < 0 or index > self.size:
            return
        elif index == 0:
            self.add_at_head(val)
        elif index == self.size:
            self.add_at_tail(val)
        else:
            curr = self.head
            for i in range(0, index - 1):
                curr = curr.next
            new_node = Node(val)
            temp = curr.next
            curr.next = new_node
            new_node.next = temp
            self.size += 1

    def remove_at_index(self, index):
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
            for i in range(0, self.size - 1):
                curr = curr.next
            curr.next = None
        else:
            for i in range(0, index - 1):
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


if __name__ == "__main__":
    my_llist = LinkedList()
    my_llist.add_at_head(3)
    print(my_llist.size)
    my_llist.add_at_tail(4)
    print(my_llist.size)
    my_llist.add_at_tail(50)
    print(my_llist.size)
    my_llist.add_at_index(30, 3)
    print(my_llist.size)
    print(my_llist)

    print(my_llist.get_at_index(2))
    print(my_llist.get_at_index(0))
    print(my_llist.get_at_index(5))
    print(my_llist)
    my_llist.remove_at_index(2)
    print(my_llist)

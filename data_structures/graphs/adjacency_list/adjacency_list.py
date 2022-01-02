"""
:author: Yannick Brenning
:date: 02.01.2022
:brief: Implementation of graphs using adjacency list
"""


class Node:
    def __init__(self, val):
        self.val = val
        self.next = None


class Graph:
    def __init__(self, directed=True, vertices=5):
        self.directed = directed
        self.vertices = vertices
        self.edges = [None] * vertices

    def has_vertex(self, vertex):
        return 0 <= vertex < self.vertices

    def has_edge(self, vertex_1, vertex_2):
        if self.has_vertex(vertex_1) and self.has_vertex(vertex_2):
            curr = self.edges[vertex_1]
            while curr is not None:
                if curr.val == vertex_2:
                    return True
                curr = curr.next

        return False

    def add_edge(self, vertex_1, vertex_2):
        """
        Add a new edge to the graph
        :param vertex_1: source/starting vertex
        :param vertex_2: target/destinatin vertex
        :return: bool value representing success or failure
        """
        if not self.has_edge(vertex_1, vertex_2):
            node = Node(vertex_2)
            node.next = self.edges[vertex_1]
            self.edges[vertex_1] = node

            if not self.directed:
                node = Node(vertex_1)
                node.next = self.edges[vertex_2]
                self.edges[vertex_2] = node

            return True

        return False

    def delete_node(self, vertex_1, vertex_2):
        """
        Deletes a node from an adjacency list
        :param vertex_1: source, e.g. index of head node
        :param vertex_2: value of node within linkedlist to be deleted
        :return: bool representing success or failure of deletion
        """
        curr = self.edges[vertex_1]
        if curr is not None and curr.val == vertex_2:
            self.edges[vertex_1] = self.edges[vertex_1].next
        else:
            while curr is not None and curr.val != vertex_2:
                prev = curr
                curr = curr.next

            if curr is None:
                return False

            prev.next = curr.next
            return True

    def delete_edge(self, vertex_1, vertex_2):
        """
        Deletes edge from graph
        :param vertex_1: source/starting vertex
        :param vertex_2: target/destination vertex
        :return: bool representing success or failure of deletion
        """
        if not self.has_edge(vertex_1, vertex_2):
            return False

        self.delete_node(vertex_1, vertex_2)
        if not self.directed:
            self.delete_node(vertex_2, vertex_1)

    def dfs(self, vertex):
        """
        Depth-First-Search and print the graph from a specific vertex
        :param vertex: vertex to start from
        :return: None
        """
        visited = [False] * self.vertices
        stack = [vertex]

        while len(stack) > 0:
            curr_vertex = stack.pop()
            visited[curr_vertex] = True
            print(curr_vertex, end=" ")

            # Add all unvisited targets to top of stack
            curr_node = self.edges[curr_vertex]
            while curr_node is not None:
                if not visited[curr_node.val]:
                    stack.append(curr_node.val)
                curr_node = curr_node.next

        print("\n")

    def __str__(self):
        output = ""
        for i in range(0, self.vertices):
            output += str(i) + ": "

            curr = self.edges[i]
            while curr is not None:
                output += str(curr.val) + " "
                curr = curr.next

            output += "\n"

        return output


def main():

    # Driver code to generate the following graph:
    #
    #       0 --> 1, 2, 3
    #       3 --> 1
    #       4 --> 2, 3

    graph = Graph()
    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(0, 3)
    graph.add_edge(2, 4)
    graph.add_edge(3, 1)
    graph.add_edge(4, 2)
    graph.add_edge(4, 3)

    graph.dfs(0)

    graph.delete_edge(3, 1)
    graph.delete_edge(0, 2)
    print(graph)


if __name__ == "__main__":
    main()

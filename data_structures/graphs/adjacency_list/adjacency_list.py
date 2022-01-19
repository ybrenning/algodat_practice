"""
Implementation of graphs using adjacency list
"""


class Node:
    def __init__(self, val: int) -> None:
        self.val = val
        self.next: Node | None = None


class Graph:
    def __init__(self, vertices: int, directed: bool = True) -> None:
        self.directed = directed
        self.vertices = vertices
        self.edges: list[Node | None] = [None] * vertices

    def __str__(self) -> str:
        output = ""
        for i in range(0, self.vertices):
            output += str(i) + ": "

            curr = self.edges[i]
            while curr is not None:
                output += str(curr.val) + " "
                curr = curr.next

            output += "\n"

        return output

    def has_vertex(self, vertex: int) -> bool:
        return 0 <= vertex < self.vertices

    def has_edge(self, vertex_1: int, vertex_2: int) -> bool:
        if self.has_vertex(vertex_1) and self.has_vertex(vertex_2):
            curr = self.edges[vertex_1]
            while curr is not None:
                if curr.val == vertex_2:
                    return True

                curr = curr.next

        return False

    def add_edge(self, vertex_1: int, vertex_2: int) -> bool:
        """
        Add a new edge to the graph.
        :param vertex_1: source/starting vertex
        :param vertex_2: target/destination vertex
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

    def delete_node(self, vertex_1: int, vertex_2: int) -> bool:
        """
        Deletes a node from an adjacency list.
        :param vertex_1: source, e.g. index of head node
        :param vertex_2: value of node within linked list to be deleted
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

    def delete_edge(self, vertex_1: int, vertex_2: int) -> bool:
        """
        Deletes edge from graph.
        :param vertex_1: source/starting vertex
        :param vertex_2: target/destination vertex
        :return: bool representing success or failure of deletion
        """

        if not self.has_edge(vertex_1, vertex_2):
            return False

        self.delete_node(vertex_1, vertex_2)
        if not self.directed:
            self.delete_node(vertex_2, vertex_1)

    def dfs(self, vertex: int) -> None:
        """
        Depth-First-Search and print the
        graph from a specific vertex
        :param vertex: vertex to start from
        :return: None
        """

        visited = [False] * self.vertices
        stack = [vertex]
        visited[vertex] = True

        while len(stack) > 0:
            curr_vertex = stack.pop()
            print(curr_vertex, end=" ")

            # Add all unvisited targets to top of stack
            curr_node = self.edges[curr_vertex]
            while curr_node is not None:
                if not visited[curr_node.val]:
                    stack.append(curr_node.val)
                    visited[curr_node.val] = True
                curr_node = curr_node.next

        print("\n")

    def bfs(self, vertex: int) -> None:
        """
        Breadth-First-Search and print the
        graph from a specific vertex
        :param vertex: starting point
        :return: None
        """

        visited = [False] * self.vertices
        queue = [vertex]
        visited[vertex] = True

        while len(queue) > 0:
            curr_vertex = queue.pop(0)
            print(curr_vertex, end=" ")

            curr_node = self.edges[curr_vertex]
            while curr_node is not None:
                if not visited[curr_node.val]:
                    queue.append(curr_node.val)
                    visited[curr_node.val] = True
                curr_node = curr_node.next

        print("\n")

    def shortest_path(self, start: int, dest: int) -> int:
        """
        Find the shortest path between two vertices using BFS
        :param start: starting/source vertex
        :param dest: destination/target vertex
        :return: path distance as int
        """

        distance: list[int] = [-1] * self.vertices
        distance[start] = 0

        queue: list[int] = [start]
        while len(queue) > 0:
            vertex = queue.pop(0)

            curr_node = self.edges[vertex]
            while curr_node is not None:
                if distance[curr_node.val] == -1:
                    distance[curr_node.val] = distance[vertex] + 1
                    queue.append(curr_node.val)

                curr_node = curr_node.next

        return distance[dest]

    def shortest_paths(self, start: int) -> None:
        """
        Find shortest paths from a starting vertex to all
        other nodes in the graph and print to console
        :param start: starting vertex
        :return: None
        """

        path: list[int | None] = [None] * self.vertices
        distance: list[int] = [-1] * self.vertices

        path[start] = start
        distance[start] = 0

        queue: list[int] = [start]
        while len(queue) > 0:
            size = len(queue)

            while size > 0:
                vertex = queue.pop(0)

                curr_node = self.edges[vertex]
                while curr_node is not None:
                    if distance[curr_node.val] == -1:
                        distance[curr_node.val] = distance[vertex] + 1
                        path[curr_node.val] = vertex
                        queue.append(curr_node.val)

                    curr_node = curr_node.next

                size -= 1

        print(f"Distance from node {start} to...")
        for i in range(0, self.vertices):
            print(f"{i} is {distance[i]} via path {path[i]}")

        print("\n")


def main():

    # Driver code to generate the following graph:
    #
    #       0 --> 1, 2, 3
    #       1 --> 2
    #       2 --> 4
    #       3 --> 1
    #       4 --> 2, 3

    graph = Graph(5)
    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(0, 3)
    graph.add_edge(1, 2)
    graph.add_edge(2, 4)
    graph.add_edge(3, 1)
    graph.add_edge(4, 2)
    graph.add_edge(4, 3)

    print(graph)
    print(graph.shortest_path(1, 4), "\n")

    graph.dfs(0)
    graph.bfs(0)
    graph.shortest_paths(0)

    graph.delete_edge(3, 1)
    graph.delete_edge(0, 2)
    print(graph)


if __name__ == "__main__":
    main()

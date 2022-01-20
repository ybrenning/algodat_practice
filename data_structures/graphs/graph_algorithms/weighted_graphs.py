"""
Implementation of weighted graphs using adjacency list
"""

from __future__ import annotations


class Node:
    def __init__(self, val: int, weight: int) -> None:
        self.val = val
        self.weight = weight
        self.next: Node | None = None


class WeightedGraph:
    def __init__(self, vertices: int, directed: bool = True) -> None:
        self.vertices = vertices
        self.directed = directed
        self.edges: list[Node | None] = [None] * vertices

    def __str__(self) -> str:
        output = ""

        for i in range(0, self.vertices):
            output += f"{i}: "

            curr = self.edges[i]
            while curr is not None:
                output += f"{curr.val} (W: {curr.weight}) "
                curr = curr.next

            output += "\n"

        return output

    def has_vertex(self, vertex: int) -> bool:
        return 0 <= vertex <= self.vertices

    def has_edge(self, vertex_1: int, vertex_2: int) -> bool:
        if self.has_vertex(vertex_1) and self.has_vertex(vertex_2):
            curr = self.edges[vertex_1]
            while curr is not None:
                if curr.val == vertex_2:
                    return True

                curr = curr.next

        return False

    def add_edge(self, vertex_1: int, vertex_2: int, weight: int) -> bool:
        if self.has_edge(vertex_1, vertex_2):
            return False

        new_node = Node(vertex_2, weight)
        new_node.next = self.edges[vertex_1]
        self.edges[vertex_1] = new_node

        if not self.directed:
            new_node = Node(vertex_1, weight)
            new_node.next = self.edges[vertex_2]
            self.edges[vertex_2] = new_node

        return True

    def __delete_node(self, vertex_1: int, vertex_2: int) -> bool:
        if self.edges[vertex_1].next is None:
            self.edges[vertex_1] = None
        else:
            curr = self.edges[vertex_1]
            prev = None
            while curr is not None and curr.val != vertex_2:
                prev = curr
                curr = curr.next

            if curr is None:
                return False

            prev.next = curr.next

            return True

    def delete_edge(self, vertex_1: int, vertex_2: int) -> bool:
        retval = False
        if not self.has_edge(vertex_1, vertex_2):
            return retval

        retval = self.__delete_node(vertex_1, vertex_2)
        if not self.directed:
            retval = self.__delete_node(vertex_2, vertex_1)

        return retval


def main():
    graph = WeightedGraph(5)
    graph.add_edge(1, 3, 5)
    graph.add_edge(1, 2, 1)
    graph.add_edge(2, 4, 8)
    graph.add_edge(0, 1, -5)
    graph.add_edge(4, 3, 2)
    print(graph)

    graph.delete_edge(4, 3)
    print(graph)


if __name__ == "__main__":
    main()

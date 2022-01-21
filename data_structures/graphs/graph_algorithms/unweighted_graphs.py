"""
Implementation of unweighted graphs using adjacency list
"""

from __future__ import annotations


class Graph:
    def __init__(self, vertices: int, directed: bool = True) -> None:
        self.vertices = vertices
        self.directed = directed
        self.edges: list[list[int]] = [[] for _ in range(vertices)]

    def __str__(self) -> str:
        output = ""

        for i in range(0, self.vertices):
            output += f"{i}: "

            for j in range(0, len(self.edges[i])):
                output += f"{self.edges[i][j]} "

            output += "\n"

        return output

    def has_vertex(self, vertex: int) -> bool:
        return 0 <= vertex < self.vertices

    def has_edge(self, vertex_1: int, vertex_2: int) -> bool:
        if self.has_vertex(vertex_1) and self.has_vertex(vertex_2):
            if vertex_2 in self.edges[vertex_1]:
                return True

        return False

    def add_edge(self, vertex_1: int, vertex_2: int) -> bool:
        if self.has_edge(vertex_1, vertex_2):
            return False

        self.edges[vertex_1].append(vertex_2)
        if not self.directed:
            self.edges[vertex_2].append(vertex_1)

        return True

    def delete_edge(self, vertex_1: int, vertex_2: int) -> bool:
        if not self.has_edge(vertex_1, vertex_2):
            return False

        self.edges[vertex_1].remove(vertex_2)
        if not self.directed:
            self.edges[vertex_2].remove(vertex_1)

        return True


def main():
    graph = Graph(5)
    graph.add_edge(0, 1)
    graph.add_edge(0, 2)
    graph.add_edge(2, 4)
    graph.add_edge(4, 3)

    print(graph)


if __name__ == "__main__":
    main()

"""
Implementation of weighted graphs using adjacency list
"""

from __future__ import annotations


class WeightedGraph:
    def __init__(self, vertices: int, directed: bool = True) -> None:
        self.vertices = vertices
        self.directed = directed
        self.edges: list[list[(int, int)]] = [[] for _ in range(vertices)]

    def __str__(self) -> str:
        output = ""

        for i in range(0, self.vertices):
            output += f"{i}: "

            for j in range(0, len(self.edges[i])):
                output += f"{self.edges[i][j][0]} (W: {self.edges[i][j][1]}) "

            output += "\n"

        return output

    def has_vertex(self, vertex: int) -> bool:
        return 0 <= vertex <= self.vertices

    def has_edge(self, vertex_1: int, vertex_2: int) -> bool:
        if self.has_vertex(vertex_1) and self.has_vertex(vertex_2):
            for i in range(0, len(self.edges[vertex_1])):
                if self.edges[vertex_1][i][0] == vertex_2:
                    return True

        return False

    def add_edge(self, vertex_1: int, vertex_2: int, weight: int) -> bool:
        if self.has_edge(vertex_1, vertex_2):
            return False

        self.edges[vertex_1].append((vertex_2, weight))

        if not self.directed:
            self.edges[vertex_2].append((vertex_1, weight))

        return True

    def __delete_edge(self, vertex_1: int, vertex_2: int) -> None:
        for i in range(0, len(self.edges[vertex_1])):
            if self.edges[vertex_1][i][0] == vertex_2:
                self.edges[vertex_1].pop(i)

    def delete_edge(self, vertex_1: int, vertex_2: int) -> bool:
        if not self.has_edge(vertex_1, vertex_2):
            return False

        self.__delete_edge(vertex_1, vertex_2)
        if not self.directed:
            self.__delete_edge(vertex_2, vertex_1)

        return True


def main():
    graph = WeightedGraph(5)
    graph.add_edge(1, 3, 5)
    graph.add_edge(1, 2, 1)
    graph.add_edge(2, 4, 8)
    graph.add_edge(0, 1, -5)
    graph.add_edge(4, 3, 2)

    print(graph)

    # Alternatively:
    other_graph = WeightedGraph(5)
    other_graph.edges = [
        [(1, -5)],
        [(3, 5), (2, 1)],
        [(4, 8)],
        [],
        [(3, 2)]
    ]

    print(other_graph)


if __name__ == "__main__":
    main()

"""
Implementation of Breadth-First-Search
"""

from __future__ import annotations
from unweighted_graphs import Graph


def bfs(graph: Graph, start: int) -> None:
    """
    Print a breadth-first traversal of a graph
    :param graph: graph to be traversed
    :param start: starting point of traversal
    :return: None
    >>> graph = Graph(5)
    >>> graph.add_edge(0, 1)
    >>> graph.add_edge(0, 2)
    >>> graph.add_edge(0, 4)
    >>> graph.add_edge(2, 3)
    >>> graph.add_edge(3, 1)
    >>> bfs(graph, 0)
    0 1 2 4 3
    """

    visited = [False for _ in range(graph.vertices)]

    queue = [start]
    visited[start] = True

    while len(queue) > 0:
        curr = queue.pop(0)
        print(curr, end=" ")

        # Adding unvisited targets to end of queue
        for i in range(0, len(graph.edges[curr])):
            if not visited[graph.edges[curr][i]]:
                queue.append(graph.edges[curr][i])
                visited[graph.edges[curr][i]] = True


def main():
    graph = Graph(5)
    graph.add_edge(0, 4)
    graph.add_edge(0, 1)
    graph.add_edge(1, 2)
    graph.add_edge(1, 3)
    graph.add_edge(3, 2)

    bfs(graph, 0)


if __name__ == "__main__":
    main()

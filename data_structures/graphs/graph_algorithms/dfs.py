"""
Implementation of Depth-First-Search
"""

from __future__ import annotations
from unweighted_graphs import Graph


def dfs(graph: Graph, start: int) -> None:
    """
    Print a depth-first traversal of the graph
    :param graph: graph to be traversed
    :param start: starting point of traversal
    :return: None
    >>> graph = Graph(5)
    >>> graph.add_edge(0, 4)
    >>> graph.add_edge(0, 1)
    >>> graph.add_edge(1, 3)
    >>> graph.add_edge(3, 2)
    >>> dfs(graph, 0)
    0 1 3 2 4
    """

    visited = [False for _ in range(graph.vertices)]

    stack = [start]
    visited[start] = True

    while len(stack) > 0:
        curr = stack.pop()
        print(curr, end=" ")

        # Adding unvisited targets to top of stack
        for i in range(0, len(graph.edges[curr])):
            if not visited[graph.edges[curr][i]]:
                stack.append(graph.edges[curr][i])
                visited[graph.edges[curr][i]] = True

    print("\n")


def main():
    graph = Graph(5)
    graph.add_edge(0, 4)
    graph.add_edge(0, 1)
    graph.add_edge(1, 3)
    graph.add_edge(3, 2)

    dfs(graph, 0)


if __name__ == "__main__":
    main()

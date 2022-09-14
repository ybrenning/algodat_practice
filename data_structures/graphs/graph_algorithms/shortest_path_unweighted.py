"""
Shortest path algorithm implemented using BFS
"""

from __future__ import annotations
from unweighted_graphs import Graph


def shortest_path(graph: Graph, start: int, dest: int):
    """
    Finds shortest path from one node to another in
    an unweighted graph
    :param graph: unweighted graph to perform algorithm on
    :param start: vertex to start from
    :param dest: vertex to reach
    :return: minimum number of edges to traverse in order
    to reach the dest from the point of start
    >>> graph = Graph(5)
    >>> graph.add_edge(0, 1)
    >>> graph.add_edge(1, 2)
    >>> graph.add_edge(2, 3)
    >>> graph.add_edge(3, 4)
    >>> print(shortest_path(graph, 0, 4))
    3
    >>> graph = Graph(5)
    >>> graph.add_edge(0, 1)
    >>> graph.add_edge(0, 2)
    >>> graph.add_edge(1, 2)
    >>> graph.add_edge(1, 3)
    >>> graph.add_edge(2, 4)
    >>> graph.add_edge(3, 4)
    >>> print(shortest_path(graph, 0, 4))
    2
    """

    dist = [-1] * graph.vertices
    dist[start] = 0

    queue = [start]
    while len(queue) > 0:
        curr_vertex = queue.pop(0)

        # Loop over all neighbors of current vertex
        for i in range(0, len(graph.edges[curr_vertex])):
            # Check whether we have visited the current neighbor
            if dist[graph.edges[curr_vertex][i]] == -1:
                dist[graph.edges[curr_vertex][i]] = dist[curr_vertex] + 1
                queue.append(graph.edges[curr_vertex][i])

    return dist[dest]


def main():
    graph = Graph(5)
    graph.edges = [[1], [3], [4], [4, 1], [0, 1]]

    print(shortest_path(graph, 0, 4))


if __name__ == "__main__":
    main()

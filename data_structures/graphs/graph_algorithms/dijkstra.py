"""
Implementation of Dijkstra's algorithm
"""

from __future__ import annotations
from weighted_graphs import WeightedGraph
import heapq


def dijkstra(graph: WeightedGraph, start: int) -> tuple[list[int], list[int]]:
    """
    Dijkstra's shortest path algorithm implementation
    :param graph: weighted graph to perform algorithm on
    :param start: starting point in the graph
    :return: tuple containing list of distances to each node
    and list of nodes from which these destinations are reached
    >>> graph = WeightedGraph()
    >>> graph.add_edge(1, 2, weight=4)
    >>> graph.add_edge(2, 3, weight=5)
    >>> graph.add_edge(2, 4, weight=1)
    >>> print(dijkstra(graph, 1)
    ([None, 0, 4, 9, 5], [-1, 1, 1, 2, 2])
    """

    vis: list[bool] = [False] * graph.vertices  # All unvisited
    dist: list[int | None] = [None] * graph.vertices  # Set to "infinity"
    prev: list[int] = [-1] * graph.vertices  # Keeps track of paths

    dist[start] = 0
    prev[start] = start

    # Priority queue stores
    # `(node index, node weight)` pairs
    pq: list[tuple[int, int]] = []
    heapq.heappush(pq, (start, 0))

    while len(pq) > 0:
        # Remove the next most promising pair
        index, min_value = heapq.heappop(pq)
        vis[index] = True

        # Skip nodes where we already found
        # a better distance before processing it
        if dist[index] is None or dist[index] < min_value:
            continue

        # Loop over all neighbours of current node
        for i in range(len(graph.edges[index])):
            curr_edge_dest: int = graph.edges[index][i][0]  # Current destination node
            curr_edge_weight: int = graph.edges[index][i][1]  # Weight of said destination

            if vis[curr_edge_dest]:
                continue

            # Edge relaxation operation:
            # Adding best distance from start node to current node
            # and cost of getting to destination node
            new_dist = dist[index] + curr_edge_weight
            # Compare to best distance for destination
            if dist[curr_edge_dest] is None or new_dist < dist[curr_edge_dest]:
                prev[curr_edge_dest] = index  # Save the node we got here from
                dist[curr_edge_dest] = new_dist  # Set new lowest distance
                heapq.heappush(pq, (curr_edge_dest, new_dist))  # Add tuple to pq so we visit it later

    return dist, prev


def main():
    graph = WeightedGraph(5)
    graph.edges = [
        [(1, 3), (2, 4)],
        [(2, 6), (0, 1)],
        [(3, 2), (4, 4)],
        [(4, 1)],
        [(1, 5)]
    ]

    print(dijkstra(graph, 2))


if __name__ == "__main__":
    main()

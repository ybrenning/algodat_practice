/**
 * @author Yannick Brenning
 * @date 26.12.2021
 * @brief Implementation of graphs using adjacency matrix
 */

#include "adjacency_matrix.h"

graph_t *graph_init(bool directed, int vertices) {
    graph_t *graph = (graph_t *) malloc(sizeof(graph_t));
    assert(graph);

    graph->directed = directed;
    graph->vertices = vertices;
    graph->edges = (bool **) malloc(vertices * sizeof(bool *));
    assert(graph->edges);

    for (int i = 0; i < vertices; i++) {
        graph->edges[i] = (bool *) calloc(vertices, sizeof(bool));
        assert(graph->edges[i]);
    }

    return graph;
}

void graph_destroy(graph_t *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        free(graph->edges[i]);
    }

    free(graph->edges);
    free(graph);
}

bool vertex_exists(graph_t *graph, unsigned int vertex) {
    if (vertex < 0 || vertex >= graph->vertices) return false;
    return true;
}

bool edge_exists(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2) {
    return graph->edges[vertex_1][vertex_2];
}

bool graph_add_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2) {
    if (!vertex_exists(graph, vertex_1) || !vertex_exists(graph, vertex_2)
    || edge_exists(graph, vertex_1, vertex_2)) {
        return false;
    }

    graph->edges[vertex_1][vertex_2] = true;
    if (!graph->directed) graph->edges[vertex_2][vertex_1] = true;
    return true;
}

void graph_print(graph_t *graph) {
    for (int i = 0; i < graph->vertices; i++) {
        for (int j = 0; j < graph->vertices; j++) {
            if (graph->edges[i][j]) {
                if (graph->directed) printf("%d -> %d\n", i, j);
                else printf("%d -- %d\n", i, j);
            }
        }
    }

    printf("\n");
}

bool graph_delete_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2) {
    if (!vertex_exists(graph, vertex_1) || !vertex_exists(graph, vertex_2)
    || !edge_exists(graph, vertex_1, vertex_2)) {
        return false;
    }

    graph->edges[vertex_1][vertex_2] = false;
    if (!graph->directed) graph->edges[vertex_2][vertex_1] = false;
    return true;
}

// Basic driver Code
int main() {
    graph_t *graph = graph_init(true, 4);
    graph_add_edge(graph, 1, 3);
    graph_add_edge(graph, 2, 3);
    graph_print(graph);

    graph_delete_edge(graph, 1, 3);
    graph_delete_edge(graph, 1, 4);
    graph_print(graph);
    graph_destroy(graph);
    return 0;
}
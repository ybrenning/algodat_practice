/**
 * @author Yannick Brenning
 * @date 26.12.2021
 * @brief Implementation of graphs using adjacency matrix
 */

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "adjacency_matrix.h"

am_graph_t *am_graph_init(bool directed, int vertices) {
    am_graph_t *graph = (am_graph_t *) malloc(sizeof(am_graph_t));
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

void am_graph_destroy(am_graph_t **graph) {
    for (int i = 0; i < (*graph)->vertices; i++) {
        free((*graph)->edges[i]);
    }

    free((*graph)->edges);
    free(*graph);
    *graph = NULL;
}

bool am_graph_vertex_exists(am_graph_t *graph, unsigned int vertex) {
    if (vertex < 0 || vertex >= graph->vertices) return false;
    return true;
}

bool am_graph_edge_exists(am_graph_t *graph, unsigned int vertex_1, unsigned int vertex_2) {
    if (graph->directed) return graph->edges[vertex_1][vertex_2];
    else return graph->edges[vertex_1][vertex_2] && graph->edges[vertex_2][vertex_1];
}

bool am_graph_add_edge(am_graph_t *graph, unsigned int vertex_1, unsigned int vertex_2) {
    if (!am_graph_vertex_exists(graph, vertex_1) || !am_graph_vertex_exists(graph, vertex_2)
    || am_graph_edge_exists(graph, vertex_1, vertex_2)) {
        return false;
    }

    graph->edges[vertex_1][vertex_2] = true;
    if (!graph->directed) graph->edges[vertex_2][vertex_1] = true;
    return true;
}

bool am_graph_delete_edge(am_graph_t *graph, unsigned int vertex_1, unsigned int vertex_2) {
    if (!am_graph_vertex_exists(graph, vertex_1) || !am_graph_vertex_exists(graph, vertex_2)
    || !am_graph_edge_exists(graph, vertex_1, vertex_2)) {
        return false;
    }

    graph->edges[vertex_1][vertex_2] = false;
    if (!graph->directed) graph->edges[vertex_2][vertex_1] = false;
    return true;
}

void graph_print(am_graph_t *graph) {
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

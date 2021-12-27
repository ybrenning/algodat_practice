/**
 * @author Yannick Brenning
 * @date 26.12.2021
 * @brief Implementation of graphs using adjacency matrix
 */

#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

typedef struct graph_t {
    bool directed;
    int vertices;
    bool **edges;
} graph_t;

graph_t *graph_init(bool directed, int vertices);
void graph_destroy(graph_t **graph);
bool vertex_exists(graph_t *graph, unsigned int vertex);
bool edge_exists(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2);
bool graph_add_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2);
bool graph_delete_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2);
void graph_print(graph_t *graph);

#endif //ADJACENCY_MATRIX_H

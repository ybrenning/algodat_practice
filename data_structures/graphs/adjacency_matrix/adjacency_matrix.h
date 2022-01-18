/**
 * @author Yannick Brenning
 * @date 26.12.2021
 * @brief Implementation of graphs using adjacency matrix
 */

#ifndef ADJACENCY_MATRIX_H
#define ADJACENCY_MATRIX_H

#include <stdbool.h>

typedef struct am_graph_t {
    bool directed;
    int vertices;
    bool **edges;
} am_graph_t;

am_graph_t *am_graph_init(bool directed, int vertices);
void am_graph_destroy(am_graph_t **graph);
bool am_graph_vertex_exists(am_graph_t *graph, unsigned int vertex);
bool am_graph_edge_exists(am_graph_t *graph, unsigned int vertex_1, unsigned int vertex_2);
bool am_graph_add_edge(am_graph_t *graph, unsigned int vertex_1, unsigned int vertex_2);
bool am_graph_delete_edge(am_graph_t *graph, unsigned int vertex_1, unsigned int vertex_2);
void am_graph_print(am_graph_t *graph);

#endif //ADJACENCY_MATRIX_H

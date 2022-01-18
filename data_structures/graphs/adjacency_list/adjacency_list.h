/**
 * @author Yannick Brenning
 * @date 27.12.2021
 * @brief Implementation of graphs using adjacency list
 */

#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <stdbool.h>

typedef struct graph_t {
    bool directed;
    int vertices;
    struct llist_t *list;
} graph_t;

typedef struct llist_t {
    struct node_t *head;
} llist_t;

typedef struct node_t {
    unsigned int val;
    struct node_t *next;
} node_t;

// Initialize new graph
graph_t *graph_init(bool directed, int vertices);
// Deallocate memory of graph
void graph_destroy(graph_t **graph);
// Check if graph has vertex
bool has_vertex(graph_t *graph, unsigned int vertex);
// Check if graph has edge vertex_1 -> vertex_2
bool has_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2);
// Add edge to graph
bool graph_add_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2);
// Delete edge from graph
bool graph_delete_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2);
// Depth-first search from vertex
void graph_dfs(graph_t *graph, unsigned int vertex);
// Breadth-first search from vertex
void graph_bfs(graph_t *graph, unsigned int vertex);
// Print adjacency list onto console
void graph_print_list(graph_t *graph);

// Tests
void test_graph_init();
void test_graph_destroy();
void test_graph_add_edge();
void test_graph_delete_edge();

#endif //ADJACENCY_LIST_H

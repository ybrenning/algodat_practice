#ifndef ADJACENCY_LIST_H
#define ADJACENCY_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

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

graph_t *graph_init(bool directed, int vertices);
void graph_destroy(graph_t **graph);
bool has_vertex(graph_t *graph, unsigned int vertex);
bool has_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2);
bool graph_add_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2);
bool graph_delete_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2);
void dgraph_dfs(graph_t *graph, unsigned int vertex);
void dgraph_bfs(graph_t *graph, unsigned int vertex);
void graph_print_list(graph_t *graph);

// Tests
void test_graph_init();
void test_graph_destroy();
void test_graph_add_edge();
void test_graph_delete_edge();

#endif //ADJACENCY_LIST_H

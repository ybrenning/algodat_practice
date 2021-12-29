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
bool graph_add_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2);
bool graph_delete_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2);
void graph_print_list(graph_t *graph);

#endif //ADJACENCY_LIST_H

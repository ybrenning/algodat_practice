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
    int val;
    struct node_t *next;
} node_t;

graph_t *graph_init(bool directed, int vertices);
void graph_destroy(graph_t **graph);

#endif //ADJACENCY_LIST_H

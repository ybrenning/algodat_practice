#include "adjacency_list.h"

graph_t *graph_init(bool directed, int vertices) {
    graph_t *graph = (graph_t *) malloc(sizeof(graph_t));
    assert(graph);

    graph->directed = directed;
    graph->vertices = vertices;

    graph->list = (llist_t *) malloc(sizeof(llist_t) * vertices);

    for (int i = 0; i < vertices; i++) {
        graph->list[i].head = NULL;
    }

    return graph;
}

void graph_destroy(graph_t **graph) {
    for (int i = 0; i < (*graph)->vertices; i++) {
        node_t *curr = (*graph)->list[i].head;
        while (curr != NULL) {
            node_t *next = curr->next;
            free(curr);
            curr = next;
        }
    }

    free((*graph)->list);
    free(*graph);
    *graph = NULL;
}

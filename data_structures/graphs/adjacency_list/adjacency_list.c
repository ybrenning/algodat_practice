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

bool has_vertex(graph_t *graph, unsigned int vertex) {
    return vertex >= 0 && vertex < graph->vertices;
}

bool has_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2) {
    if (has_vertex(graph, vertex_1) && has_vertex(graph, vertex_2)) {
        node_t *curr = graph->list[vertex_1].head;
        for (int i = 0; i < vertex_2; i++) {
            curr = curr->next;
        }

        if (curr != NULL) return true;
    }

    return false;
}

bool graph_add_edge(graph_t *graph, unsigned int vertex_1, unsigned int vertex_2) {
    return false;
}

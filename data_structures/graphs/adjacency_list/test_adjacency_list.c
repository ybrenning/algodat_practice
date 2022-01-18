#include <stdlib.h>
#include <assert.h>
#include "adjacency_list.h"

void test_graph_init() {
    graph_t *graph = graph_init(true, 5);
    assert(graph->directed);
    assert(graph->vertices == 5);

    for (int i = 0; i < graph->vertices; i++) {
        assert(graph->list[i].head == NULL);
    }

    graph_destroy(&graph);
}

void test_graph_destroy() {
    graph_t *graph = graph_init(true, 5);
    graph_destroy(&graph);
    assert(!graph);
}

void test_graph_add_edge() {
    graph_t *graph = graph_init(true, 5);
    graph_add_edge(graph, 0, 1);
    assert(has_edge(graph, 0, 1));

    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 0, 2);
    graph_add_edge(graph, 0, 3);
    assert(has_edge(graph, 0, 2));
    assert(has_edge(graph, 0, 3));

    assert(!graph_add_edge(graph, 0, 6));
    assert(!has_edge(graph, 0, 6));

    graph_destroy(&graph);
}

void test_graph_delete_edge() {
    graph_t *graph = graph_init(true, 5);
    graph_add_edge(graph, 0, 1);
    graph_delete_edge(graph, 0, 1);
    assert(!has_edge(graph, 0, 1));

    graph_add_edge(graph, 0, 1);
    graph_add_edge(graph, 0, 2);
    graph_add_edge(graph, 0, 3);
    graph_add_edge(graph, 0, 4);
    assert(graph_delete_edge(graph, 0, 3));
    assert(!has_edge(graph, 0, 3));

    graph_destroy(&graph);
}

void run_all_tests() {
    test_graph_init();
    test_graph_destroy();
    test_graph_add_edge();
    test_graph_delete_edge();
}

int main() {
    run_all_tests();
    return 0;
}

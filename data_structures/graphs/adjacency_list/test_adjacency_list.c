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

void run_all_tests() {
    test_graph_init();
    test_graph_destroy();
}

int main() {
    run_all_tests();
    return 0;
}

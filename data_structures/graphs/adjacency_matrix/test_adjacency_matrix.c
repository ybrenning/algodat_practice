#include "adjacency_matrix.h"

void test_graph_init() {
    graph_t *dgraph = graph_init(true, 4);
    assert(dgraph->directed);
    assert(dgraph->vertices == 4);

    graph_t *ugraph = graph_init(false, 4);
    assert(!ugraph->directed);
    assert(ugraph->vertices == 4);

    graph_destroy(&dgraph);
    graph_destroy(&ugraph);
}

void test_graph_destroy() {
    graph_t *graph = graph_init(true, 4);
    assert(graph);

    graph_destroy(&graph);
    assert(!graph);
}

void test_graph_add_edge() {
    graph_t *dgraph = graph_init(true, 4);
    graph_add_edge(dgraph, 0, 1);
    assert(edge_exists(dgraph, 0, 1));
    assert(!graph_add_edge(dgraph, 0, 5));

    graph_t *ugraph = graph_init(false, 4);
    graph_add_edge(ugraph, 0, 1);
    assert(edge_exists(ugraph, 0, 1));
    assert(edge_exists(ugraph, 1, 0));

    graph_destroy(&dgraph);
    graph_destroy(&ugraph);
}

void test_graph_delete_edge() {
    graph_t *dgraph = graph_init(true, 4);
    assert(!graph_delete_edge(dgraph, 0, 1));

    graph_add_edge(dgraph, 0, 1);
    assert(graph_delete_edge(dgraph, 0, 1));
    assert(!edge_exists(dgraph, 0, 1));

    graph_t *ugraph = graph_init(false, 4);
    graph_add_edge(ugraph, 0, 1);
    assert(graph_delete_edge(ugraph, 0, 1));
    assert(!edge_exists(ugraph, 0, 1));
    assert(!edge_exists(ugraph, 1, 0));

    graph_destroy(&dgraph);
    graph_destroy(&ugraph);
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

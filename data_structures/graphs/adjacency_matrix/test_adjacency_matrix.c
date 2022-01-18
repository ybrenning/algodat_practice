#include <assert.h>
#include "adjacency_matrix.h"

void test_graph_init() {
    am_graph_t *dgraph = am_graph_init(true, 4);
    assert(dgraph->directed);
    assert(dgraph->vertices == 4);

    am_graph_t *ugraph = am_graph_init(false, 4);
    assert(!ugraph->directed);
    assert(ugraph->vertices == 4);

    am_graph_destroy(&dgraph);
    am_graph_destroy(&ugraph);
}

void test_graph_destroy() {
    am_graph_t *graph = am_graph_init(true, 4);
    assert(graph);

    am_graph_destroy(&graph);
    assert(!graph);
}

void test_graph_add_edge() {
    am_graph_t *dgraph = am_graph_init(true, 4);
    am_graph_add_edge(dgraph, 0, 1);
    assert(am_graph_edge_exists(dgraph, 0, 1));
    assert(!am_graph_add_edge(dgraph, 0, 5));

    am_graph_t *ugraph = am_graph_init(false, 4);
    am_graph_add_edge(ugraph, 0, 1);
    assert(am_graph_edge_exists(ugraph, 0, 1));
    assert(am_graph_edge_exists(ugraph, 1, 0));

    am_graph_destroy(&dgraph);
    am_graph_destroy(&ugraph);
}

void test_graph_delete_edge() {
    am_graph_t *dgraph = am_graph_init(true, 4);
    assert(!am_graph_delete_edge(dgraph, 0, 1));

    am_graph_add_edge(dgraph, 0, 1);
    assert(am_graph_delete_edge(dgraph, 0, 1));
    assert(!am_graph_edge_exists(dgraph, 0, 1));

    am_graph_t *ugraph = am_graph_init(false, 4);
    am_graph_add_edge(ugraph, 0, 1);
    assert(am_graph_delete_edge(ugraph, 0, 1));
    assert(!am_graph_edge_exists(ugraph, 0, 1));
    assert(!am_graph_edge_exists(ugraph, 1, 0));

    am_graph_destroy(&dgraph);
    am_graph_destroy(&ugraph);
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

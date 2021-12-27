#include "adjacency_list.h"

void test_graph_init() {
    graph_t *graph = graph_init(true, 5);
    graph_destroy(&graph);
}

void run_all_tests() {
    test_graph_init();
}

int main() {
    run_all_tests();
    return 0;
}

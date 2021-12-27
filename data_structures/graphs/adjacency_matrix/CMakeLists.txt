cmake_minimum_required(VERSION 3.20)
project(adjacency_matrix)
enable_testing()

set(SOURCE_FILES adjacency_matrix.c test_adjacency_matrix.c)

add_executable(adjacency_matrix ${SOURCE_FILES})

add_test(NAME test_adjacency_matrix COMMAND adjacency_matrix)
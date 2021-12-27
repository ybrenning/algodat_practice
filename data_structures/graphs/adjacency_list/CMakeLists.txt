cmake_minimum_required(VERSION 3.20)
project(adjacency_list)
enable_testing()

set(SOURCE_FILES adjacency_list.c test_adjacency_list.c)

add_executable(adjacency_list ${SOURCE_FILES})

add_test(NAME test_adjacency_list COMMAND adjacency_list)

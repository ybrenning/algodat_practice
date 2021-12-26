cmake_minimum_required(VERSION 3.20)
project(binary_search_trees)
enable_testing()

set(SOURCE_FILES binary_search_trees.c test_binary_search_trees.c)

add_executable(binary_search_trees ${SOURCE_FILES})

add_test(NAME test_binary_search_trees COMMAND binary_search_trees)

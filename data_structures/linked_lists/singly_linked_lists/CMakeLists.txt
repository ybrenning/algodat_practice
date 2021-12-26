cmake_minimum_required(VERSION 3.20)
project(singly_linked_lists)
enable_testing()

set(SOURCE_FILES singly_linked_lists.c test_singly_linked_lists.c)

add_executable(singly_linked_lists ${SOURCE_FILES})

add_test(NAME test_singly_linked_lists COMMAND singly_linked_lists)

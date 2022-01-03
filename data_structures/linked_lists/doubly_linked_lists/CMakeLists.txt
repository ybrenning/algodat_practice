cmake_minimum_required(VERSION 3.20)
project(doubly_linked_lists)
enable_testing()

set(SOURCE_FILES doubly_linked_lists.c test_doubly_linked_lists.c)

add_executable(doubly_linked_lists ${SOURCE_FILES})

add_test(NAME test_doubly_linked_lists COMMAND doubly_linked_lists)

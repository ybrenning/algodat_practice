cmake_minimum_required(VERSION 3.20)
project(queue_array)
enable_testing()

set(SOURCE_FILES queue_array.c test_queue_array.c)

add_executable(queue_array ${SOURCE_FILES})

add_test(NAME test_queue_array COMMAND queue_array)

cmake_minimum_required(VERSION 3.20)
project(arrays)
enable_testing()

set(SOURCE_FILES arrays.c test_arrays.c)

add_executable(arrays ${SOURCE_FILES})

add_test(NAME test_arrays COMMAND arrays)

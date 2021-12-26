cmake_minimum_required(VERSION 3.20)
project(hash_tables)
enable_testing()

set(SOURCE_FILES hash_tables.c test_hash_tables.c)

add_executable(hash_tables ${SOURCE_FILES})

add_test(NAME test_hash_tables COMMAND hash_tables)

cmake_minimum_required(VERSION 3.20)
project(priority_queues)
enable_testing()

set(SOURCE_FILES priority_queues.c test_priority_queues.c)

add_executable(priority_queues ${SOURCE_FILES})

add_test(NAME test_priority_queues COMMAND priority_queues)

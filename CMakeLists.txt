cmake_minimum_required(VERSION 3.10)
project(LinkedList)

set(CMAKE_CXX_STANDARD 17)

add_library(linked_list STATIC LinkedList.cpp)

target_include_directories(linked_list PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(tests_linked_list test.cpp)
target_link_libraries(tests_linked_list linked_list)
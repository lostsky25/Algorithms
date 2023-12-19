cmake_minimum_required(VERSION 3.16..3.24)

project(algorithms
    VERSION 0.0.1
    DESCRIPTION "Data structures & Algorithms"
    LANGUAGES C CXX)

include(cmake/UpdateSubmodules.cmake)
include(CTest)

add_subdirectory(external)

# Data Structures
add_subdirectory(DataStructures/ForwardList)
add_subdirectory(DataStructures/DoublyLinkedList)
set(
    Sources
    doubly_linked_list.cpp
)

set(
    Headers
    doubly_linked_list.hpp
)

add_library(DoublyLinkedList SHARED ${Sources} ${Headers})

if (BUILD_TESTING)
    add_executable(DoublyLinkedListTests test.cpp)
    target_link_libraries(DoublyLinkedListTests PRIVATE GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(DoublyLinkedListTests)
endif()
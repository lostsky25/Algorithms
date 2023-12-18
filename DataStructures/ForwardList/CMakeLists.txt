set(
    Sources
    forward_list.cpp
)

set(
    Headers
    forward_list.hpp
)

add_library(LinkedList SHARED ${Sources} ${Headers})

if (BUILD_TESTING)
    add_executable(tests test.cpp)
    target_link_libraries(tests PRIVATE GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(tests)
endif()
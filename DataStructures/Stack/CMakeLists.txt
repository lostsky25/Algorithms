set(
    Sources
    stack.cpp
)

set(
    Headers
    stack.hpp
)

add_library(Stack SHARED ${Sources} ${Headers})

if (BUILD_TESTING)
    add_executable(StackTests test.cpp)
    target_link_libraries(StackTests PRIVATE GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(StackTests)
endif()
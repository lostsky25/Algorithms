set(
    Sources
    stack_with_container.cpp
)

set(
    Headers
    stack_with_container.hpp
)

add_library(StackWithContainer SHARED ${Sources} ${Headers})

if (BUILD_TESTING)
    add_executable(StackWithContainerTests test.cpp)
    target_link_libraries(StackWithContainerTests PRIVATE GTest::gtest_main)

    include(GoogleTest)
    gtest_discover_tests(StackWithContainerTests)
endif()
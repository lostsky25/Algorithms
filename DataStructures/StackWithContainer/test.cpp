#include <gtest/gtest.h>

#include "stack_with_container.hpp"

TEST(StackWithContainer, empty) {
    Stack<int> st;

    ASSERT_TRUE(st.empty() == true);
}

TEST(StackWithContainer, size) {
    Stack<int> st;

    ASSERT_TRUE(st.size() == 0);
}

TEST(StackWithContainer, push) {
    Stack<int> st;
    
    for (int i = 0; i < 100; ++i) {
        st.push(i);
    }

    ASSERT_TRUE(st.size() == 100);

    int val = st.top();
    while (!st.empty()) {
        ASSERT_TRUE(st.top() == val);
        --val;
        st.pop();
    }
}

TEST(StackWithContainer, pop) {
    Stack<int> st;
    
    for (int i = 0; i < 100; ++i) {
        st.push(i);
    }
    
    for (int i = 0; i < 50; ++i) {
        st.pop();
    }

    ASSERT_TRUE(st.size() == 50);

    int val = st.top();
    while (!st.empty()) {
        ASSERT_TRUE(st.top() == val);
        --val;
        st.pop();
    }
}
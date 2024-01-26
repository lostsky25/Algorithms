#include <gtest/gtest.h>

#include "stack.hpp"

TEST(Stack, empty) {
    Stack<int> st;

    ASSERT_TRUE(st.empty() == true);
}

TEST(Stack, size) {
    Stack<int> st;

    ASSERT_TRUE(st.size() == 0);
}

TEST(Stack, push) {
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

TEST(Stack, pop) {
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

TEST(Stack, swap) {
    Stack<int> st1;
    Stack<int> st2;
    
    for (int i = 0; i < 100; ++i) {
        st1.push(i);
    }
    
    for (int i = 0; i < 50; ++i) {
        st2.push(i);
    }

    st1.swap(st2);
    
    ASSERT_TRUE(st1.size() == 50);
    ASSERT_TRUE(st2.size() == 100);
}
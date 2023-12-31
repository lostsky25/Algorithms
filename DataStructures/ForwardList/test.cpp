#include <gtest/gtest.h>

#include "forward_list.hpp"

TEST(ForwardList, PushFront) {
    ForwardList<int> fl;

    for (int i = 0; i < 100; i++) {
        fl.push_front(i + 1);
    }
    
    for (int i = 0; i < 100; i++) {
        ASSERT_TRUE(fl[i] == 100 - i);
    }
    
    ASSERT_TRUE(fl.size() == 100);
}

TEST(ForwardList, PopFront) {
    ForwardList<int> fl;

    for (int i = 0; i < 100; i++) {
        fl.push_front(i + 1);
    }

    for (int i = 0; i < 50; i++) {
        fl.pop_front();
    }
    
    for (int i = 0; i < 50; i++) {
        ASSERT_TRUE(fl[i] == 50 - i);
    }
    
    ASSERT_TRUE(fl.size() == 50);
}
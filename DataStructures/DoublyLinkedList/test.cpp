#include <gtest/gtest.h>

#include "doubly_linked_list.hpp"

TEST(DoublyLinkedList, PushFront) {
    List<int> l;

    for (int i = 0; i < 100; i++) {
        l.push_front(i + 1);
    }
    
    for (int i = 0; i < 100; i++) {
        ASSERT_TRUE(l[i] == 100 - i);
    }
    
    ASSERT_TRUE(l.size() == 100);
}

TEST(DoublyLinkedList, PopFront) {
    List<int> l;

    for (int i = 0; i < 100; i++) {
        l.push_front(i + 1);
    }

    for (int i = 0; i < 50; i++) {
        l.pop_front();
    }
    
    for (int i = 0; i < 50; i++) {
        ASSERT_TRUE(l[i] == 50 - i);
    }
    
    ASSERT_TRUE(l.size() == 50);
}

TEST(DoublyLinkedList, PushBack) {
    List<int> l;

    for (int i = 0; i < 100; i++) {
        l.push_back(i + 1);
    }

    for (int i = 0; i < 100; i++) {
        ASSERT_TRUE(l[i] == i + 1);
    }
    
    ASSERT_TRUE(l.size() == 100);
}

TEST(DoublyLinkedList, PopBack) {
    List<int> l;

    for (int i = 0; i < 100; i++) {
        l.push_back(i + 1);
    }

    for (int i = 0; i < 50; i++) {
        l.pop_back();
    }

    for (int i = 0; i < 50; i++) {
        ASSERT_TRUE(l[i] == i + 1);
    }
    
    ASSERT_TRUE(l.size() == 50);
}
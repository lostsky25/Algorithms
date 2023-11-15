#include <iostream>
#include <gtest/gtest.h>

template <class T>
struct Node {
    T data;
    Node<T>* next;

    Node(T data, Node<T>* node) {
        this->data = data;
        this->next = node;
    }
};

template <class T>
class ForwardList {
public:
    ForwardList() {
        head = nullptr;
        sz = 0;
    }

    void push_front(T data) {
        head = new Node<T>(data, head);
        // Node<T>* newNode = new Node(data, nullptr);
        // newNode->next = head;
        // head = newNode;
        ++sz;
    }

    void pop_front() {
        Node<T>* nextHead = head->next;
        delete head;
        head = nextHead;
        --sz;
    }

    T& operator [] (size_t index) {
        Node<T>* n = head;
        for (size_t i = 0; i < index; ++i) {
            n = n->next;
        }
        return n->data;
    }

    T& front() {
        if (empty()) {
            throw "front() called on empty forward_list";
        }
        return head->data;
    }

    size_t size() const {
        return sz;
    }

    bool empty() const {
        return sz == 0;
    }

    ~ForwardList() {
        while (!empty())
            pop_front();
    }

private:
    Node<T>* head;
    size_t sz;
};

TEST(PushFrontElements, Subtest_1) {
    ForwardList<int> fl;

    for (int i = 0; i < 100; i++) {
        fl.push_front(i + 1);
    }
    
    for (int i = 0; i < 100; i++) {
        ASSERT_TRUE(fl[i] == 100 - i);
    }
    
    ASSERT_TRUE(fl.size() == 100);
}

TEST(PopFrontElements, Subtest_2) {
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

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
#pragma once

#include <cstddef>

template <class T>
struct Node {
    T data;
    Node<T>* next;

    Node(T data, Node<T>* next) :
        data(data),
        next(next) {
    }
};

template <class T>
class ForwardList {
public:
    ForwardList() :
        head(nullptr),
        sz(0) {
    }

    void push_front(T data) {
        head = new Node<T>(data, head);
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
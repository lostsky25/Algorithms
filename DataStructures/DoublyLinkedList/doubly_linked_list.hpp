#pragma once
#include <cstddef>

template <class T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node() : 
        next(nullptr), 
        prev(nullptr) {
    }

    Node(T data) : 
        data(data) {
    }

    Node(T data, Node<T>* next, Node<T>* prev) : 
        data(data), 
        next(next),
        prev(prev) {
    }
};

template <class T>
class List {
public:
    List() :
        sz(0),
        head(nullptr),
        tail(nullptr) {
    }

    void push_back(T data) {
        Node<T>* tmp = new Node<T>(data);

        if (head == nullptr) {
            head = tail = tmp;
        } else {
            tail->next = tmp;
            tmp->prev = tail;

            tail = tail->next;
        }
        ++sz;
    }

    void push_front(T data) {
        Node<T>* tmp = new Node<T>(data);

        if (head == nullptr) {
            head = tail = tmp;
        } else {
            head->prev = tmp;
            tmp->next = head;

            head = head->prev;
        }
        ++sz;
    }

    void pop_front() {
        if (head == nullptr) {
            throw "List is empty";
        } else {
            Node<T>* nextHead = head->next;
            delete head;

            head = nextHead;
            head->prev = nullptr;
            --sz;
        }
    }

    void pop_back() {
        if (head == nullptr) {
            throw "List is empty";
        } else {
            Node<T>* prevTail = tail->prev;
            delete tail;

            tail = prevTail;
            tail->next = nullptr;
            --sz;
        }
    }

    size_t size() const {
        return sz;
    }

    bool empty() const {
        return sz == 0;
    }

    T& operator[] (size_t idx) {
        Node<T>* tmp = head;

        if (idx >= sz) {
            throw "Out of range";
        }

        for (size_t i = 0; i < idx; i++)
            tmp = tmp->next;

        return tmp->data;
    }

private:
    size_t sz;
    Node<T>* head;
    Node<T>* tail;
};
#include <iostream>
#include <forward_list>

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
class LinkedList {
public:
    LinkedList() {
        head = nullptr;
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

    ~LinkedList() {
        while (!empty())
            pop_front();
    }

private:
    Node<T>* head;
    size_t sz;
};

int main(){

    LinkedList<int> l;
    l.push_front(1);
    std::cout << l.front();

    // LinkedList<int> list;

    // for (int i = 0; i < 10; ++i) {
    //     list.push_front(i + 1);
    // }

    // for (int i = 0; i < list.size(); ++i) {
    //     std::cout << &list[i] << " = " << list[i] << std::endl;
    // }

    return 0;
}
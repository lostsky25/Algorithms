#include <iostream>
#include <forward_list>

template <class T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

    Node() {
        this->prev = nullptr;
        this->next = nullptr;
    }

    Node(T data, Node<T>* prev, Node<T>* next) {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

template <class T>
class List {
public:
    List() {
        sz = 0;
        head = nullptr;
        tail = nullptr;
    }

    void push_back(int data) {
        Node<T>* tmp = new Node<T>();
        tmp->data = data;
        tmp->next = nullptr;
        tmp->prev = nullptr;

        if (head == nullptr) {
            head = tmp;
            tail = tmp;
        }
        else {
            tail->next = tmp;
            tail->prev = head;

            tail = tail->next;
        }
        ++sz;
    }

    void push_front(int data) {
        Node<T>* tmp = new Node<T>();
        tmp->data = data;
        tmp->next = nullptr;
        tmp->prev = nullptr;

        if (head == nullptr) {
            head = tmp;
            tail = tmp;
        }
        else {
            tmp->next = head;
            head->prev = tmp;
            
            head = tmp;
        }
        ++sz;
    }

    void push_after_at(int index, int data) {
        //if (head == nullptr) {
        //    push_back(data);
        //    return;
        //}

        if (index < size()) {
            Node<T>* tmp = new Node<T>();
            tmp->data = data;
            tmp->next = nullptr;
            tmp->prev = nullptr;

            Node<T>* elem = head;
            while (index > 0) {
                elem = head->next;
                --index;
            }
            
            if (elem->next) {
                tmp->next = elem->next;
                elem->next->prev = tmp;

                if (elem->next == tail) {
                    tail = elem->next;
                }
            }
            else {
                tail = tmp;
            }
            elem->next = tmp;
            tmp->prev = elem;
            ++sz;
        }
        else {
            throw "out of range";
        }
    }

    void push_after_at(Node<T>* node, int data) {
        if (node != nullptr) {
            Node<T>* tmp = new Node<T>();
            tmp->data = data;

            if (node->next) {
                node->next->prev = tmp;
                tmp->next = node->next;

                if (node->next == tail) {
                    tail = node->next;
                }
            }
            else {
                tmp->prev = node;
                node->next = tmp;
                tail = tmp;
            }

            
            ++sz;
        }
        else {
            throw "out of range";
        }
    }    
    
    void push_before_at(Node<T>* node, int data) {
        if (node != nullptr) {
            Node<T>* tmp = new Node<T>();
            tmp->data = data;

            if (node->prev) {
                node->prev->next = tmp;
                tmp->prev = node->prev;

                if (node->prev == head) {
                    head = node->prev;
                }
            }
            else
            {
                tmp->next = node;
                node->prev = tmp;
                head = tmp;
            }

            
            ++sz;
        }
        else {
            throw "out of range";
        }
    }

    void push_before_at(int index, int data) {
        //if (head == nullptr) {
        //    push_back(data);
        //    return;
        //}

        if (index < size()) {
            Node<T>* tmp = new Node<T>();
            tmp->data = data;
            tmp->next = nullptr;
            tmp->prev = nullptr;

            Node<T>* elem = head;
            while (index > 0) {
                elem = head->next;
                --index;
            }

            if (elem->prev) {
                tmp->prev = elem->prev;
                elem->prev->next = tmp;

                if (elem->prev == head) {
                    head = elem->prev;
                }
            }
            else {
                head = tmp;
            }
            elem->prev = tmp;
            tmp->next = elem;
            ++sz;
        }
        else {
            throw "out of range";
        }
    }

    size_t size() const {
        return sz;
    }

    T& operator [] (size_t index) {
        Node<T>* n = head;
        for (size_t i = 0; i < index; ++i) {
            n = n->next;
        }
        return n->data;
    }
    Node<T>* head, * tail;

private:
    size_t sz;
};

int main() {

    List<int> l;
    l.push_back(0);
    l.push_after_at(l.tail, 3);
    l.push_after_at(l.tail, 2);
    l.push_after_at(l.tail, 1);



    // LinkedList<int> list;

    // for (int i = 0; i < 10; ++i) {
    //     list.push_front(i + 1);
    // }

    for (int i = 0; i < l.size(); ++i) {
        std::cout << l[i] << std::endl;
    }

    return 0;
}
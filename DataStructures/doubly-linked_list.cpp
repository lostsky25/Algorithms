#include <iostream>
#include <forward_list>

template <class T>
struct Node {
    T data;
    Node<T>* next;
    Node<T>* prev;

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

	void insert_before(Node<T>* elem, int data) {
		Node<T>* newNode = new Node<T>(data, elem->prev, elem);
		if (elem->prev) {
			elem->prev->next = newNode;
		}
		elem->prev = newNode;
		++sz;
	}

	void insert_after(Node<T>* elem, int data) {
		Node<T>* newNode = new Node<T>(data, elem, elem->next);
		if (elem->next) {
			elem->next->prev = newNode;
		}
		elem->next = newNode;
		++sz;
	}

	void push_back(T data) {
		if (empty())
			push_front(data);
		else
			insert_after(tail, data);
	}

    void push_front(T data) {
        head = new Node<T>(data, nullptr, head);
        // Node<T>* newNode = new Node(data, nullptr);
        // newNode->next = head;
        // head = newNode;
    }

	void erase(Node<T>* elem) {
		if (elem->prev) {
			elem->prev->next = elem->next;
		}

		if (elem->next) {
			elem->next->prev = elem->prev;
		}
		delete elem;
	}

    void pop_back() {
		erase(tail);
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

    ~List() {
        while (!empty())
            pop_front();
    }

private:
    Node<T>* head,* tail;
    size_t sz;
};

int main(){

    List<int> l;
    l.push_back(1);
    l.push_back(2);
    l.push_back(3);

	

    // LinkedList<int> list;

    // for (int i = 0; i < 10; ++i) {
    //     list.push_front(i + 1);
    // }

    for (int i = 0; i < l.size(); ++i) {
        std::cout << l[i] << std::endl;
    }

    return 0;
}

// #include <iostream>

// template <typename T>
// struct Node {
// 	Node* prev;
// 	Node* next;
// 	T data;

// 	Node(T data) {
// 		this->data = data;
// 		prev = next = nullptr;
// 	}

// 	Node(T data, Node<T>* prev, Node<T>* next) {
// 		this->data = data;
// 		this->prev = prev;
// 		this->next = next;
// 	}
// };

// template <typename T>
// class LinkedList
// {
// public:
// 	LinkedList() {
// 		head = tail = nullptr;
// 		sz = 0;
// 	}

// 	void insert_before(Node<T>* element, T data) {
// 		Node<T>* newNode = new Node<T>(data, element->prev, element);
		
// 		std::cout << newNode << std::endl;

// 		if (element->prev != nullptr)
// 			element->prev->next = newNode;

// 		element->prev = newNode;
// 		sz++;
// 	}

// 	void insert_after(Node<T>* element, T data) {
// 		Node<T>* newNode = new Node<T>(data, element, element->next);
// 		std::cout << newNode << std::endl;
// 		if (element->next != nullptr)
// 			element->next->prev = newNode;

// 		// if (head == nullptr) {
// 		// 	head = newNode;
// 		// 	tail = newNode;
// 		// } else {
// 		// 	tail->next = newNode;
// 		// 	tail = tail->next;
// 		// }

// 		element->next = newNode;
// 		sz++;
// 	}

// 	void push_front(T data) {
// 		insert_after(head, data);
// 	}

// 	void push_back(T data) {
// 		if (empty()) {
// 			push_front(data);
// 		}else{
// 			insert_after(tail, data);
// 		}
// 	}

// 	void erase(Node<T>* elem) {
// 		if (elem->prev) {
// 			elem->prev->next = elem->next;
// 		}
// 		if (elem->next) {
// 			elem->next->prev = elem->prev;
// 		}
// 		delete elem;
// 	}

// 	bool empty() {
// 		return head == nullptr;
// 	}

// 	~LinkedList() {

// 	}

// 	Node<T>* head, *tail;

// private:
// 	size_t sz;
// };


// int main() {
// 	LinkedList<int> list;
// 	std::cout << "1";

// 	list.push_back(1);
// 	list.push_back(2);
// 	// list.insert_before(list.head->next, 2);
// 	// list.insert_before(list.head->next->next, 3);

// 	std::cout << "Head: " << list.head << std::endl;
// 	std::cout << "Tail: " << list.tail << std::endl;

// 	return 0;
// }

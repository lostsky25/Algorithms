#include <iostream>

template <typename T>
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        left = nullptr;
        right = nullptr;
    }
};

template <typename T>
class BST {
public:
    BST() {
        root = nullptr;
    }

    void insert(T data) {
        Node<T>* parent = nullptr;
        Node<T>* node = root;

        while (node != nullptr) {
            parent = node;
            if (data < node->data) {
                node = node->left;
            } else if (data > node->data) {
                node = node->right;
            } else {
                return;
            }
        }

        Node<T>* newNode = new Node<T>(data);

        if (parent == nullptr) {
            root = newNode;
        } else if (data < parent->data) {
            parent->left = newNode;
        } else if (data > parent->data) {
            parent->right = newNode;
        }
    }

    void print(){
        treeprint(root);
    }

    void treeprint(Node<T>* tree) {
        if (tree!=NULL) {
            treeprint(tree->left); // l
            treeprint(tree->right); // r
            std::cout << tree->data << ' '; // n
    }
}

private:
    Node<T>* root;
};

int main() {
    BST<int> bst;

    for (int i = 0; i < 10; ++i) {
        bst.insert(i + 1);
    }

    bst.print();

    return 0;
}
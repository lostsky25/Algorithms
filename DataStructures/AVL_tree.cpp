
template <typename T>
struct Node {
    T key;
    unsigned char height;
    Node* left;
    Node* right;

    Node(T k) {
        key = k;
        left = right = nullptr;
        height = 1;
    }
}

template <typename T>
class AVL {
public:
    Node<T>* rotateright(Node<T>* p) {
        Node<T>* q = p->left;
        p->left = q->right;
        q->right = p;

        fixheight(p);
        fixheight(q);

        return q;
    }

    Node<T>* rotateleft(Node<T>* q) {
        Node<T>* p = q->right;
        q->right = p->left;
        p->left = q;

        fixheight(q);
        fixheight(p);

        return p;
    }

    void fixheight(Node<T>* p) {
        unsigned char hl = height(p->left);
        unsigned char hr = height(p->right);

        p->height = (hl > hr ? hl : hr) + 1;
    }

    int bfactor(Node<T>* node) {
        return height(node->right) - height(node->left);
    }

    unsigned char height(Node<T>* node) {
        if (node) {
            return node->height;
        } else {
            return 0;
        }
    }

private:
    Node<T>* root;
};

int main(int argc, char **argv)
{
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
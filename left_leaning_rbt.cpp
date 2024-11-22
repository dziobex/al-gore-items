#include <iostream>
#include <cstdlib>
#include <time.h>

inline constexpr std::nullptr_t nil = nullptr;

enum Color {
    red, black
};

template <typename T>
struct Node {
    T data;
    Node *left = nil;
    Node *right = nil;
    Node *p = nil;\


    Node(T data) : data(data) {}
};

template<typename T>
class BST {
    Node<T> *root;
public:
    BST() { root = nil; }
    ~BST() {}

    T find_min();
    T find_max();

    Node<T>* find_me(T elem);
    T tree_successor(T elem);

    void preorder_tree_walk();
    void preorder_tree_walk(Node<T>* node);

    void insert(T elem);
    void delete_node(T elem);

private:
    Node<T>* find_min(Node<T>* node);
    Node<T>* delete_node(Node<T>* node, T elem);
};

template<typename T>
T BST<T>::find_min() {
    Node<T> *min_node = find_min(root);
    return min_node ? min_node->data : T();
}

template<typename T>
Node<T>* BST<T>::find_min(Node<T>* node) {
    while (node->left != nil)
        node = node->left;
    return node;
}

template<typename T>
T BST<T>::find_max() {
    Node<T> *x = root;
    while ( x->right != nil )
        x = x->right;
    return x->data;
}

template<typename T>
void BST<T>::preorder_tree_walk() {
    preorder_tree_walk(root);
}

template<typename T>
void BST<T>::preorder_tree_walk(Node<T>* node) {
    if (node != nil) {
        std::cout << node->data << " ";
        preorder_tree_walk(node->left);
        preorder_tree_walk(node->right);
    }
}

template<typename T>
void BST<T>::insert(T elem) {
    Node<T> *new_node = new Node<T>(elem);
    Node<T> *x = this->root;
    Node<T> *y = nil;

    while (x != nil) {
        y = x;
        if (new_node->data < x->data)
            x = x->left;
        else
            x = x->right;
    }

    new_node->p = y;

    if (y == nil)
        this->root = new_node;
    else if (new_node->data < y->data)
        y->left = new_node;
    else
        y->right = new_node;
}

template<typename T>
Node<T>* BST<T>::find_me(T elem) {
    Node<T> *found = root;
    while ( found != nil && found->data != elem ) {
        if ( elem < found->data )
            found = found->left;
        else
            found = found->right;
    }
    return found;
}

template<typename T>
T BST<T>::tree_successor(T elem) {
    Node<T>* node = find_me(elem);

    if (node == nil) // element isn't present
        return T();

    if (node->right != nil) // only the left way has the successor
        return find_min(node->right)->data;

    Node<T>* p = node->p;
    while (p != nil && node == p->right) {
        node = p;
        p = p->p;
    }
    return p ? p->data : T();
}

template<typename T>
void BST<T>::delete_node(T elem) {
    root = delete_node(root, elem);
}

template<typename T>
Node<T>* BST<T>::delete_node(Node<T>* node, T elem) {
    if (node == nil) return nil;

    if (elem < node->data)
        node->left = delete_node(node->left, elem);
    else if (elem > node->data)
        node->right = delete_node(node->right, elem);
    else {
        if (node->left == nil) {
            Node<T>* temp = node->right;
            if (temp != nil)
                temp->p = node->p;
            delete node;
            return temp;
        } else if (node->right == nil) {
            Node<T>* temp = node->left;
            if (temp != nil)
                temp->p = node->p;
            delete node;
            return temp;
        } else {
            Node<T>* min_node = find_min(node->right);
            node->data = min_node->data;
            node->right = delete_node(node->right, min_node->data);
        }
    }
    return node;
}

int main() {
    srand(time(NULL));
    BST<int> bst;

    std::cout << "Random numbers: ";
    for (int i = 0; i < 10; ++i) {
        int n = rand() % 30;
        std::cout << n << (i == 9 ? "\n\n" : ", ");
        bst.insert(n);
    }

    bst.preorder_tree_walk();
    std::cout << "\n\nMin value: " << bst.find_min() << "\nMax value: " << bst.find_max() << "\n";

    int test_val = 13;
    std::cout << "Successor of " << test_val << ": " << bst.tree_successor(test_val) << "\n\n";

    bst.delete_node(test_val);
    
    bst.preorder_tree_walk();

    return 0;
}
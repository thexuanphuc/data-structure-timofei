#include <iostream>

enum Color { RED, BLACK };

struct Node {
    int data;
    Color color;
    Node* parent;
    Node* left;
    Node* right;
};

class RedBlackTree {
private:
    Node* root;

    // Helper function to perform a left rotation
    void leftRotate(Node* x) {
        Node* y = x->right;
        x->right = y->left;
        if (y->left != nullptr)
            y->left->parent = x;
        y->parent = x->parent;
        if (x->parent == nullptr)
            root = y;
        else if (x == x->parent->left)
            x->parent->left = y;
        else
            x->parent->right = y;
        y->left = x;
        x->parent = y;
    }

    // Helper function to perform a right rotation
    void rightRotate(Node* y) {
        Node* x = y->left;
        y->left = x->right;
        if (x->right != nullptr)
            x->right->parent = y;
        x->parent = y->parent;
        if (y->parent == nullptr)
            root = x;
        else if (y == y->parent->left)
            y->parent->left = x;
        else
            y->parent->right = x;
        x->right = y;
        y->parent = x;
    }

    // Helper function to fix violations after insertion
    void fixInsertion(Node* z) {
        while (z != root && z->parent->color == RED) {
            if (z->parent == z->parent->parent->left) {
                Node* y = z->parent->parent->right;
                if (y != nullptr && y->color == RED) {
                    z->parent->color = BLACK;
                    y->color = BLACK;
                    z->parent->parent->color = RED;
                    z = z->parent->parent;
                } else {
                    if (z == z->parent->right) {
                        z = z->parent;
                        leftRotate(z);
                    }
                    z->parent->color = BLACK;
                    z->parent->parent->color = RED;
                    rightRotate(z->parent->parent);
                }
            } else {
                // Same as the above with "right" and "left" exchanged
                // ...
            }
        }
        root->color = BLACK;
    }

public:
    RedBlackTree() : root(nullptr) {}

    // Function to insert a value into the Red-Black Tree
    void insert(int data) {
        // Create a new node with the given data
        Node* newNode = new Node{data, RED, nullptr, nullptr, nullptr};
        
        // BST-style insertion
        Node* y = nullptr;
        Node* x = root;
        while (x != nullptr) {
            y = x;
            if (data < x->data)
                x = x->left;
            else
                x = x->right;
        }
        newNode->parent = y;
        if (y == nullptr)
            root = newNode;
        else if (data < y->data)
            y->left = newNode;
        else
            y->right = newNode;

        // Fix Red-Black Tree properties
        fixInsertion(newNode);
    }
};

int main() {
    RedBlackTree tree;
    
    // Insert elements into the Red-Black Tree
    tree.insert(10);
    tree.insert(20);
    tree.insert(30);
    tree.insert(15);
    tree.insert(25);
    
    // You can add more insertions as needed
    
    return 0;
}

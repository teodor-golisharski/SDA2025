#include <iostream>

struct Node {
    int key;
    Node* left;
    Node* right;
    Node(int k) : key(k), left(nullptr), right(nullptr) {}
};

class BST {
private:
    Node* root = nullptr;

    Node* insert(Node* current, int key) {
        if (current == nullptr) {
            return new Node(key);
        }
        if (key < current->key)
            current->left = insert(current->left, key);
        else if (key > current->key)
            current->right = insert(current->right, key);
        return current;
    }

    void inorder(Node* current) {
        if (current == nullptr) return;
        inorder(current->left);
        std::cout << current->key << " ";
        inorder(current->right);
    }

    void freeTree(Node* node) {
        if (node == nullptr) return;
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    }

public:
    void insert(int key) {
        root = insert(root, key);
    }

    void print() {
        inorder(root);
        std::cout << "\n";
    }

    Node* minValueNode(Node* node) {
        Node* current = node;

        while (current && current->left != nullptr)
            current = current->left;

        return current;
    }


    Node* deleteNode(struct Node* current, int key) {
        if (current == NULL) return current;

        if (key < current->key)
            current->left = deleteNode(current->left, key);
        else if (key > current->key)
            current->right = deleteNode(current->right, key);
        else {
            if (current->left == NULL) {
                Node* temp = current->right;
                free(current);
                return temp;
            }
            else if (current->right == NULL) {
                Node* temp = current->left;
                free(current);
                return temp;
                struct Node* temp = minValueNode(current->right);

                // Copy the inorder successor's content to this node
                current->key = temp->key;

                // Delete the inorder successor
                current->right = deleteNode(current->right, temp->key);
            }
            return current;
        }
    }

    ~BST() {
        freeTree(root);
    }
};

int main() {
    BST bst;

    bst.insert(5);
    bst.insert(1);
    bst.insert(5); 
    bst.insert(8);
    bst.insert(15);
    bst.insert(17);
    bst.insert(15); 

    bst.print();
}

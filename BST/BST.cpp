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

	// Print the tree nodes in ascending order by value
	void inorder(Node* current) {
		// if empty -> return
		if (current == nullptr) return;
		// Recursively select all left elements
		inorder(current->left);
		// Print the current element
		std::cout << current->key << " ";
		// Recursively select all right elements
		inorder(current->right);
	}

	// Free all nodes in the tree
	void freeTree(Node* node) {
		if (node == nullptr) return;
		freeTree(node->left);
		freeTree(node->right);
		delete node;
	}

	// Find the node with the minimum key value from the given node
	Node* minValueNode(Node* node) {
		Node* current = node;

		while (current && current->left != nullptr)
			current = current->left;

		return current;
	}

	// Delete a node with a given key
	Node* deleteNode(struct Node* current, int key) {
		// STEP 1: Get to the node with the given key
		if (current == NULL) return current;

		if (key < current->key)
			current->left = deleteNode(current->left, key);
		else if (key > current->key)
			current->right = deleteNode(current->right, key);
		else {
			// STEP 2: Node with only one child or no child

			if (current->left == nullptr) {
				Node* temp = current->right;
				delete current;
				return temp;
			}
			else if (current->right == nullptr) {
				Node* temp = current->left;
				delete current;
				return temp;
			}

			// STEP 3: Node with two children: Get the inorder successor (smallest in the right subtree)
			Node* temp = minValueNode(current->right); // smallest in the right subtree
			current->key = temp->key; // Copy the inorder successor's content to this node
			current->right = deleteNode(current->right, temp->key); // Delete the inorder successor
		}
		return current;
	}

public:
	// insert a new node with a given key
	void insert(int key) {
		root = insert(root, key);
	}

	// print the whole tree in ascending order
	void print() {
		inorder(root);
		std::cout << "\n";
	}

	// Remove a node with a given key
	void remove(int key) {
		root = deleteNode(root, key);
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

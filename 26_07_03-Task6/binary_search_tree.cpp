#include <iostream>
using namespace std;

// A Binary Search Tree (BST) maintains order:
// Left child < Current node < Right child
class Tree {
public:
    int value;
    Tree* left  = nullptr;
    Tree* right = nullptr;

    // Constructor to initialize a node with a given value
    Tree(int v) {
        value = v;
    }

    // Recursively inserts a new value into the correct position
    void insert(int v) { 
        if (v < value) {
            // Traverse down the left branch
            if (left == nullptr) left = new Tree(v);
            else left->insert(v); // Pass insertion responsibility to left child
        } 
        else if (v > value) {
            // Traverse down the right branch
            if (right == nullptr) right = new Tree(v);
            else right->insert(v); // Pass insertion responsibility to right child
        }
    }

    // Recursively searches for a value in the tree
    bool search(int v) {
        if (v == value) return true;
        if (v < value)  return left  != nullptr && left->search(v);
        else            return right != nullptr && right->search(v);
    }

    // In-Order Traversal: Left -> Root -> Right
    // Produces values in ascending (sorted) order
    void displayInOrder() {
        if (left)  left->displayInOrder();
        cout << value << " ";
        if (right) right->displayInOrder();
    }

    // Pre-Order Traversal: Root -> Left -> Right
    // Useful for copying or capturing the tree's structural hierarchy
    void displayPreOrder() {
        cout << value << " ";
        if (left)  left->displayPreOrder();
        if (right) right->displayPreOrder();
    }
};

int main() {
    // Input dataset: 10 acts as the root node to keep the tree balanced
    int values[] = {10, 5, 15, 2, 7, 12, 18};
    int totalElements = sizeof(values) / sizeof(values[0]);

    // Create the root node with the first element
    Tree* root = new Tree(values[0]);

    // Insert remaining elements into the BST
    for (int i = 1; i < totalElements; i++) {
        root->insert(values[i]);
    }

    cout << "In-order (Sorted): ";
    root->displayInOrder();
    cout << "\n";

    cout << "Pre-order (Root-First): ";
    root->displayPreOrder();
    cout << "\n\n";

    // Lookup testing
    cout << "--- Search Verification ---" << endl;
    cout << "Searching for 7:  " << (root->search(7)  ? "Found" : "Not Found") << endl;
    cout << "Searching for 99: " << (root->search(99) ? "Found" : "Not Found") << endl;

    return 0;
}
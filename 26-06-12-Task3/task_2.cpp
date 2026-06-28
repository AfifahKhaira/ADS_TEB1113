#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node() {
        next = NULL;
    }

    // Display the linked list
    void displayList() {
        Node* current = this;

        while (current != NULL) {
            cout << current->name << endl;
            current = current->next;
        }
    }

    // Insert at the end
    void insertion(string newName) {
        Node* newNode = new Node();
        newNode->name = newName;

        Node* current = this;

        while (current->next != NULL) {
            current = current->next;
        }

        current->next = newNode;
    }

    // Delete by name
    void deletion(string deleteName) {
        Node* current = this;
        Node* previous = NULL;

        while (current != NULL && current->name != deleteName) {
            previous = current;
            current = current->next;
        }

        if (current == NULL) {
            cout << deleteName << " not found!" << endl;
            return;
        }

        // Cannot delete the head using this function
        if (previous == NULL) {
            cout << "Cannot delete the first node using this function." << endl;
            return;
        }

        previous->next = current->next;
        delete current;
    }
};

int main() {

    Node* node1 = new Node();
    Node* node2 = new Node();
    Node* node3 = new Node();
    Node* node4 = new Node();

    node1->name = "Aiman";
    node2->name = "Ahmad";
    node3->name = "Anjana";
    node4->name = "Jessy";

    node1->next = node2;
    node2->next = node3;
    node3->next = node4;

    cout << "Original List:\n";
    node1->displayList();

    cout << "\nAfter Insertion:\n";
    node1->insertion("Ali");
    node1->displayList();

    cout << "\nAfter Deletion (Ahmad):\n";
    node1->deletion("Ahmad");
    node1->displayList();

    return 0;
}
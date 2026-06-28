#include <iostream>
#include <string>

using namespace std;

struct Node{
    string name;
    Node* next;
};

int main() {

    Node node1, node2, node3, node4;
    
    // Assign names
    node1.name = "Aimar";
    node2.name = "Ahmad";
    node3.name = "Anjana";
    node4.name = "Jessy";
    
    // Link the nodes
    
    node1.next = &node2;
    node2.next = &node3;
    node3.next = &node4; 
    node4.next = NULL;
    
     // Traverse the linked list
    Node* current = &node1;

    while (current != NULL) {
        cout << current->name << endl;
        current = current->next;
    }

    return 0;
}
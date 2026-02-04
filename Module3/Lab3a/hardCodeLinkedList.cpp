#include <iostream>
#include <string>

using namespace std;

struct Node {
    string data;
    Node* nextNode;
};

void printLinkedList(Node* argNode);

int main() {

    // Create first Node pointer
        Node* head = new Node();

    // Create temporary PTR to preserve head pointer
        Node* tempPtr = head;

    // Setting head pointer's data member to 'Hello'
        tempPtr->data = "Hello";
    // Setting head pointer's nextNode member to point to the next node
        tempPtr->nextNode = new Node();
    
    // Moving temporary pointer to next Node
        tempPtr = tempPtr->nextNode;
    // Setting next node's data member to 'Linked'
        tempPtr->data = "Linked";
    // Setting temp pointer's nextNode to point to new NextNode
        tempPtr->nextNode = new Node();

    // Moving temp pointer to next Node
        tempPtr = tempPtr->nextNode;
    // Setting last node's data member to 'Lists'
        tempPtr->data = "Lists";
    // Setting this pointer's nextNode member to point to null
        tempPtr->nextNode = nullptr;

    printLinkedList(head);

    return 0;
}

void printLinkedList(Node* argNode) {
    Node* tempPtr = argNode;

    while (tempPtr != nullptr) {
        cout << tempPtr->data << endl;
        tempPtr = tempPtr->nextNode;
    }
}

#include <iostream>

using namespace std;

class DoublyLinkedList {
    private:
        Node* headPtr;

    public:

        Node* lastNode(void);
        void pushBack(string argData);
        void popBack(void);
        void pushFront(string argData);
        void insertAfter(Node* argPtr, string argStr);
        void deallocateAll(void);
        Node* searchFor(string argData);
        int size(void);
};

class Node {
    public:
        Node* previousNode;
        int data;
        Node* nextNode;
};

int main() {

    Node* headPtr = new Node();
    headPtr->previousNode = nullptr;

    Node* tempPtr = headPtr;

    for (int i = 0; i < 10; ++i) {
        
        if (i == 9) {

            tempPtr->data = i;
            tempPtr->nextNode = nullptr;

        } else {

            tempPtr->data = i;

            tempPtr->nextNode = new Node();
            tempPtr->nextNode->previousNode = tempPtr;

            tempPtr = tempPtr->nextNode;

        }
    }

    return 0;
}

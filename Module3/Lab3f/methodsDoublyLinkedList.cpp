#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        Node* prev;
        string data;
        Node* next;

        Node() : prev(nullptr), data(""), next(nullptr) {}
        Node(string argData) : prev(nullptr), data(argData), next(nullptr) {}
};

class LinkedList {
    private:
        Node* headPtr;
        Node* tailPtr;
        int size = 0;

    public:
        LinkedList();

        Node* lastNode();
        void pushBack(string argData);
        void popBack();
        void pushFront(string argData);
        void insertAfter(Node* argPtr, string argStr);
        void deallocateAll();
        Node* searchFor(string argData);
        int getSize();
        void displayFwd();
        void displayBwd();
};

int main() {

    LinkedList myLinkedList;

    cout << "\n----------- PUSH BACK 10 NODES -----------\n";
        for (int i = 0; i < 10; ++i) {
            myLinkedList.pushBack("world");
        }
        myLinkedList.displayFwd();
        

    cout << "\n----------- CHECK SIZE -----------\n";
        cout << myLinkedList.getSize() << endl;


    cout << "\n----------- ADD 5 NODES TO FRONT -----------\n";
        for (int i = 0; i < 5; ++i) {
            myLinkedList.pushFront("hello");
        }
        myLinkedList.displayFwd();


    cout << "\n----------- CHECK SIZE -----------\n";
        cout << myLinkedList.getSize() << endl;


    cout << "\n----------- PUSH BACK NODE -----------\n";
        myLinkedList.pushBack("last node");
        cout << "Pushed Back: last node" << endl;


    cout << "\n----------- CHECK LAST NODE -----------\n";
        cout << myLinkedList.lastNode()->data << endl;


    cout << "\n----------- REMOVE LAST NODE -----------\n";
        myLinkedList.popBack();


    cout << "\n----------- CHECK LAST NODE -----------\n";
        cout << myLinkedList.lastNode()->data << endl;


    cout << "\n----------- INSERT AFTER LAST NODE -----------\n";
        myLinkedList.insertAfter(myLinkedList.lastNode(), "Inserted after");


    cout << "\n----------- CHECK LAST NODE -----------\n";
        cout << "Last Node: " << myLinkedList.lastNode()->data << endl;


    cout << "\n----------- SEARCH FOR 'Inserted after' -----------\n";
        Node* found = myLinkedList.searchFor("Inserted after");
        found ? (cout << "Found: " << found->data << endl) : cout << "Not Found\n"; 

    cout << "\n----------- PRINT FORWARD LINKED LIST -----------\n";
        myLinkedList.displayFwd();

    cout << "\n----------- PRINT BACKWARD LINKED LIST -----------\n";
        myLinkedList.displayBwd();

    cout << "\n----------- DEALLOCATE ALL -----------\n";
        myLinkedList.deallocateAll();
        cout << "Size: " << myLinkedList.getSize() << " : Should see -2 because the two sentinels were also removed" << endl;

    return 0;
}

LinkedList::LinkedList() {
    // sentinel nodes - helps avoid edge cases like starting w/ no nodes
    headPtr = new Node(); 
    tailPtr = new Node();

    // linking nodes together
    headPtr->next = tailPtr;
    tailPtr->prev = headPtr;
}

Node* LinkedList::lastNode() {
    // tailPtr is a sentinel so prev is the actual tailPtr
    return tailPtr->prev;
}

void LinkedList::pushBack(string argData) {
    Node* lastNode = tailPtr->prev;

    lastNode->next = new Node(argData);
    
    lastNode->next->prev = lastNode;
    lastNode->next->next = tailPtr;
    
    tailPtr->prev = lastNode->next;
    size++;
}

void LinkedList::popBack() {
    Node* toDelete = tailPtr->prev;
    toDelete->prev->next = tailPtr;
    tailPtr->prev = toDelete->prev;

    delete toDelete;
    toDelete = nullptr;
    size--;
}

void LinkedList::pushFront(string argData) {
    Node* firstNode = headPtr->next;

    firstNode->prev = new Node(argData);

    firstNode->prev->next = firstNode;
    firstNode->prev->prev = headPtr;

    headPtr->next = firstNode->prev;
    size++;
}

void LinkedList::insertAfter(Node* argPtr, string argStr) {
    Node* currPtr = headPtr->next;

    while (currPtr != argPtr && currPtr != tailPtr) {
        currPtr = currPtr->next;
    }

    if (currPtr == argPtr) {
        Node* nextPtr = currPtr->next;
        
        currPtr->next = new Node(argStr);

        currPtr->next->prev = currPtr;
        currPtr->next->next = nextPtr;

        nextPtr->prev = currPtr->next;

        size++;
    }

    return;
    
}

void LinkedList::deallocateAll() {
    Node* currPtr = headPtr;

    while (headPtr) {
        Node* toDelete = currPtr;
        currPtr = currPtr->next;

        delete toDelete;
        toDelete = nullptr;

        size--;
    }
}

Node* LinkedList::searchFor(string argData) {
    Node* currPtr = headPtr->next;

    while (currPtr != tailPtr && currPtr->data != argData) {
        currPtr = currPtr->next;
    }

    if (currPtr->data == argData) return currPtr;

    return nullptr;
}

int LinkedList::getSize() {
    return size;
}

void LinkedList::displayFwd() {
    Node* currPtr = headPtr->next;

    while (currPtr->next != tailPtr) {
        cout << currPtr->data << endl;
        currPtr = currPtr->next;
    }

    cout << currPtr->data << endl;
}

void LinkedList::displayBwd() {
    Node* currPtr = tailPtr->prev;

    while (currPtr->prev != headPtr) {
        cout << currPtr->data << endl;
        currPtr = currPtr->prev;
    }

    cout << currPtr->data << endl;
}
#include <iostream>
#include <string>

using namespace std;

struct Node {
    Node* prevNode;
    string data;
    Node* nextNode;
};

Node* push_back(Node* currNodePtr);
int nodeCounter(Node* headPtr);
void printFwdList(Node* beginningNodePtr);
void printRvseList(Node* endNodePtr);

int main() {

    char anotherNode = 'n';
    Node* lastNode = nullptr;

    Node* headNode = new Node();
    Node* tempPtr = headNode;

    tempPtr->prevNode = nullptr;

    do {

        string userStr;

        cout << "\nEnter a string: ";
        getline(cin, userStr);

        tempPtr->data = userStr;

        cout << "Add another string? (y/n): ";
        cin >> anotherNode;

        if (tolower(anotherNode) == 'y') 
            tempPtr = push_back(tempPtr);
            
        else {
            lastNode = tempPtr;
            lastNode->nextNode = nullptr;
        }

        cin.ignore();

    } while(tolower(anotherNode) == 'y');

    printFwdList(headNode);
    printRvseList(lastNode);

    cout << "Number of nodes: " << nodeCounter(headNode) << endl;

    Node* deleteThis = nullptr;
    Node* tempRmPtr = headNode;

    while (tempRmPtr != nullptr) {
        deleteThis = tempRmPtr;

        tempRmPtr = tempRmPtr->nextNode;

        delete deleteThis;
        deleteThis = nullptr;
    }

    return 0;
}

Node* push_back(Node* currNodePtr) {
    currNodePtr->nextNode = new Node();
    currNodePtr->nextNode->prevNode = currNodePtr;

    currNodePtr = currNodePtr->nextNode;

    return currNodePtr;
}

int nodeCounter(Node* headPtr) {
    int count = 0;

    Node* temp = headPtr;

    while (temp != nullptr) {
        count++;
        temp = temp->nextNode;
    }

    return count;
}

void printFwdList(Node* beginningNodePtr) {

    Node* tempNodePtr = beginningNodePtr;

    cout << "******************" << endl;
    if (tempNodePtr == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        while (tempNodePtr != nullptr) {
            cout << tempNodePtr->data << endl;
            tempNodePtr = tempNodePtr->nextNode;
        };

    }
    cout << "******************" << endl;

}


void printRvseList(Node* endNodePtr) {

    Node* tempNodePtr = endNodePtr;

    cout << "******************" << endl;
    if (tempNodePtr == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        while (tempNodePtr != nullptr) {
            cout << tempNodePtr->data << endl;
            tempNodePtr = tempNodePtr->prevNode;
        }

    }
    cout << "******************" << endl;
}

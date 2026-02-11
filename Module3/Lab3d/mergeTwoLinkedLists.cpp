#include <iostream>
#include <vector>

using namespace std;

struct Node {
    int data;
    Node* nextNode;
};

Node* mergeLists(Node* head1, Node* head2);
void printFwdList(Node* beginningNodePtr);
void deletePointer(Node* headPtr);

int main() {

    // LINKED LIST 1 ----------------------------

    Node* headPtr1 = new Node();
    Node* tempPtr1 = headPtr1;

    for (int i = 0; i < 10; ++i) {

        if (i == 9) {
            tempPtr1->data = i;
            tempPtr1->nextNode = nullptr;
        } else {
            tempPtr1->data = i;

            tempPtr1->nextNode = new Node();

            tempPtr1 = tempPtr1->nextNode;
        }
    }

    // LINKED LIST 2 ----------------------------

    Node* headPtr2 = new Node();
    Node* tempPtr2 = headPtr2;

    for (int i = 10; i <= 20; ++i) {

        if (i == 20) {
            tempPtr2->data = i;
            tempPtr2->nextNode = nullptr;
        } else {
            tempPtr2->data = i;

            tempPtr2->nextNode = new Node();

            tempPtr2 = tempPtr2->nextNode;
        }
    }

    // MERGING BOTH LINKED LISTS ----------------------------

    Node* mergedLinkedList = mergeLists(headPtr1, headPtr2);
    printFwdList(mergedLinkedList);

    deletePointer(mergedLinkedList);

    return 0;
}



Node* mergeLists(Node* head1, Node* head2) {

    Node* tempPtr = head1;

    while (tempPtr->nextNode != nullptr) {
        tempPtr = tempPtr->nextNode;
    }

    tempPtr->nextNode = head2;

    return head1;

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

void deletePointer(Node* headPtr) {
    Node* deletePtr = nullptr;
    Node* tempDelPtr = headPtr;
    
    while (tempDelPtr != nullptr) {
        deletePtr = tempDelPtr;
        tempDelPtr = tempDelPtr->nextNode;

        delete deletePtr;
        deletePtr = nullptr;
    }
}

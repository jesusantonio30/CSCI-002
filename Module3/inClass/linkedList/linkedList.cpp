#include <iostream>
#include <string>

using namespace std;

struct Node {
    string obj;
    Node* nextObj;
};

void printLinkedList(Node* head);

int main() {

    // LINKED LIST ----------------------------------------
        // Node* headPtr = new Node();

        // headPtr->obj = "ab";
        // headPtr->nextObj = new Node();

        // headPtr->nextObj->obj = "cd";
        // headPtr->nextObj->nextObj = new Node();

        // headPtr->nextObj->nextObj->obj = "ef";
        // headPtr->nextObj->nextObj->nextObj = new Node();

        // headPtr->nextObj->nextObj->nextObj->obj = "gh";
        // headPtr->nextObj->nextObj->nextObj->nextObj = nullptr;

        // printLinkedList(headPtr);

    // LINKED LIST ----------------------------------------

    char userResponse = 'n';
    string userName;
    Node* headPtr = new Node();
    Node* tempPtr = headPtr;

    do {

        cout << "Enter a name: ";
        getline(cin, userName);

        tempPtr->obj = userName;
        tempPtr->nextObj = new Node();

        tempPtr = tempPtr->nextObj;
        

        cout << "Add another node? (y/n): ";
        cin >> userResponse;

        cin.ignore();

    } while(tolower(userResponse) == 'y');

    tempPtr->nextObj = nullptr;

    tempPtr->obj = "ab";
    tempPtr->nextObj = new Node();

    tempPtr = tempPtr->nextObj;

    tempPtr->obj = "cd";
    tempPtr->nextObj = new Node();

    tempPtr = tempPtr->nextObj;

    tempPtr->obj = "ef";
    tempPtr->nextObj = new Node();

    tempPtr = tempPtr->nextObj;

    tempPtr->obj = "gh";
    tempPtr->nextObj = nullptr;

    printLinkedList(headPtr);



    return 0;
}

void printLinkedList(Node* head) {

    Node* temp = head;

    while(head->nextObj != nullptr) {
        cout << temp->obj << endl;
        temp = temp->nextObj;
    }

    cout << temp->obj << endl;
}

#include <iostream>


using namespace std;

template<class T>
class Node {
public:
    T obj;
    Node* next;
    Node* prev;
};

template<class T>
void printForward(Node<T>* head);

template<class T>
void printReverse(Node<T>* head);

template<typename T>
int nodeCount(Node<T>* head);

template<typename T>
void deleteSecNode(Node<T>* head);

int main() {

    //  Head and Tail Pointer
    Node<int>* headPtr = nullptr;
    Node<int>* tailPtr = nullptr;

    // Hardcode five Nodes
    Node<int>* node1 = new Node<int>();
    Node<int>* node2 = new Node<int>();
    Node<int>* node3 = new Node<int>();
    Node<int>* node4 = new Node<int>();
    Node<int>* node5 = new Node<int>();

    // Assign each node a value
    node1->obj = 10;
    node2->obj = 20;
    node3->obj = 30;
    node4->obj = 40;
    node5->obj = 50;

    // Assign Head and Tail pointers
    headPtr = node1;
    tailPtr = node5;

    // Link Nodes
    headPtr->prev = nullptr;
    headPtr->next = node2;

    node2->prev = headPtr;
    node2->next = node3;

    node3->prev = node2;
    node3->next = node4;

    node4->prev = node3;
    node4->next = tailPtr;

    tailPtr->prev = node4;
    tailPtr->next = nullptr;

    // Print forward
    cout << "Forward: \n";
    printForward(headPtr);

    // Print reverse
    cout << "\nReverse: \n";
    printReverse(headPtr);

    // Get Linked List size
    cout << "\nList Size: \n" << nodeCount(headPtr) << endl;

    // Delete second Node
    deleteSecNode(headPtr);

    cout << "\n----- After Second Node Deletion ----- \n";

    // Print Forward and Reverse
    cout << "\nForward: \n";
    printForward(headPtr);

    cout << "\nReverse: \n";
    printReverse(headPtr);

    // Get Linked List size
    cout << "\nList Size: \n" << nodeCount(headPtr) << endl;


    return 0;
}

template<class T>
void printForward(Node<T>* head) {
    Node<T>* cur = head;
    if (cur == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        do {
            cout << cur->obj << endl;
            cur = cur->next;
        } while (cur != nullptr);
    }

}

template<typename T>
void printReverse(Node<T>* head) {
    Node<T>* cur = head;
    if (cur == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        //iterate to end;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cout << cur->obj << endl;
        while (cur->prev != nullptr) {
            cur = cur->prev;
            cout << cur->obj << endl;
        }
    }
}

template<typename T>
int nodeCount(Node<T>* head) {
    Node<T>* curr = head;
    int size = 0;

    while (curr) {
        size++;
        curr = curr->next;
    }

    return size;
}

template<typename T>
void deleteSecNode(Node<T>* head) {

    if (!head || !head->next) return;

    Node<T>* secondNode = head->next;
    Node<T>* newSecond = secondNode->next;

    head->next = newSecond;
    newSecond->prev = head;

    delete secondNode;
}
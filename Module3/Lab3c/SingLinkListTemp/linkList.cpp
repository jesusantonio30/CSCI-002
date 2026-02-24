#include <iostream>


using namespace std;

template<class T>
class Node {
    public:
        Node* next;
        T data;

        Node() : next(nullptr), data{} {}
        Node(T arg) : next(nullptr), data(arg) {}
};

template<class T>
class SingleLinkedList {
    private:
        Node<T>* headPtr;
        Node<T>* tailPtr;

    public:
        SingleLinkedList(T argData);
        ~SingleLinkedList();
        void push_back(Node<T>* argNewNode);
        int nodeCounter();
        void printFwdList();
};

int main() {

    SingleLinkedList<int> list1(10);

    cout << "\n=== Test 2: push_back ===" << endl;
    list1.push_back(new Node<int>(20));
    list1.push_back(new Node<int>(30));
    list1.push_back(new Node<int>(40));
    list1.printFwdList();
    cout << "Node count: " << list1.nodeCounter() << endl;

    SingleLinkedList<string> list2("apple");
    list2.push_back(new Node<string>("banana"));
    list2.push_back(new Node<string>("cherry"));
    list2.printFwdList();
    cout << "Node count: " << list2.nodeCounter() << endl;

    return 0;
}

template<class T>
SingleLinkedList<T>::SingleLinkedList(T argData) {
    headPtr = new Node<T>();
    tailPtr = new Node<T>();
    Node<T>* firstNode = new Node<T>(argData);

    headPtr->next = firstNode;
    firstNode->next = tailPtr;
}

template<class T>
SingleLinkedList<T>::~SingleLinkedList() {
    Node<T>* currPtr = headPtr;

    while (currPtr) {
        Node<T>* toDelete = currPtr;
        currPtr = currPtr->next;

        delete toDelete;
        toDelete = nullptr;
    }
}

template<class T>
void SingleLinkedList<T>::push_back(Node<T>* argNewNode) {
    Node<T>* currPtr = headPtr;

    while (currPtr && currPtr->next != tailPtr) {
        currPtr = currPtr->next;
    }

    currPtr->next = argNewNode;
    argNewNode->next = tailPtr;
}

template<class T>
int SingleLinkedList<T>::nodeCounter() {
    int nodeSize = 0;
    Node<T>* currPtr = headPtr->next;

    while (currPtr && currPtr != tailPtr) {
        currPtr = currPtr->next;
        nodeSize++;
    }

    return nodeSize;
}

template<class T>
void SingleLinkedList<T>::printFwdList() {
    Node<T>* currPtr = headPtr->next;

    while (currPtr && currPtr != tailPtr) {
        cout << currPtr->data << endl;
        currPtr = currPtr->next;
    }
}


#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

template<class T>
class Node {
    public:
        Node* prev;
        T data;
        Node* next;

        Node() : prev(nullptr), data(), next(nullptr) {}
        Node(T argData): prev(nullptr), data(argData), next(nullptr) {}
};

template<class T>
class DubLinkedList {
    private:
        Node<T>* headPtr;
        Node<T>* tailPtr;
        int size = 0;

    public:
        DubLinkedList();
        ~DubLinkedList();

        void pushFront(T argData);
        void pushBack(T argData);
        void popFront();
        void popBack();
        int insertAfter(Node<T>* argNode, T argData);
        void deleteNode(Node<T>* argNode);
        int getSize();
        void display();
        Node<T>* begin();
        Node<T>* end();
};

class Circle {
    private:
        string color;
        float radius;

    public:
        Circle() : radius(0.0), color("") {}
        Circle(float argRad, string argColor) : radius(argRad), color(argColor) {}
        void display();
};

int main() {

    srand(time(0));

    DubLinkedList<Circle> myList;
    vector<string> colors = {"Green", "Yellow", "Blue", "Orange", "Purple", "Navy"};

    for (int i = 0; i < 10; ++i) {
        string randColor = colors[rand() % colors.size()];
        float randRad = 1.0 * rand() / RAND_MAX;
        myList.pushBack(Circle(randRad, randColor));
    }

    myList.display();

    return 0;
}

template<class T>
DubLinkedList<T>::DubLinkedList() {
    headPtr = new Node<T>();
    tailPtr = new Node<T>();

    headPtr->next = tailPtr;
    tailPtr->prev = headPtr;
}

template<class T>
DubLinkedList<T>::~DubLinkedList() {
    Node<T>* currPtr = headPtr;

    while (currPtr) {
        Node<T>* toDelete = currPtr;

        currPtr = currPtr->next;

        delete toDelete;
        toDelete = nullptr;
    }
}

template<class T>
void DubLinkedList<T>::pushFront(T argData) {
    Node<T>* oldFirstNode = headPtr->next;
    Node<T>* newFirstNode = new Node<T>(argData);

    headPtr->next = newFirstNode;
    newFirstNode->prev = headPtr;

    newFirstNode->next = oldFirstNode;
    oldFirstNode->prev = newFirstNode;
    size++;
}

template<class T>
void DubLinkedList<T>::pushBack(T argData) {
    Node<T>* oldLastNode = tailPtr->prev;
    Node<T>* newLastNode = new Node<T>(argData);

    tailPtr->prev = newLastNode;
    newLastNode->next = tailPtr;

    newLastNode->prev = oldLastNode;
    oldLastNode->next = newLastNode;
    size++;
}

template<class T>
void DubLinkedList<T>::popFront() {
    Node<T>* toDelete = headPtr->next;
    Node<T>* newFirstNode = toDelete->next;

    headPtr->next = newFirstNode;
    newFirstNode->prev = headPtr;

    delete toDelete;
    toDelete = nullptr;
    size--;
}

template<class T>
void DubLinkedList<T>::popBack() {
    Node<T>* toDelete = tailPtr->prev;
    Node<T>* newLastNode = toDelete->prev;

    tailPtr->prev = newLastNode;
    newLastNode->next = tailPtr;

    delete toDelete;
    toDelete = nullptr;
    size--;
}

template<class T>
int DubLinkedList<T>::insertAfter(Node<T>* argNode, T argData) {

    if (!argNode) return 0;

    Node<T>* oldNextNode = argNode->next;
    Node<T>* newNextNode = new Node<T>(argData);

    argNode->next = newNextNode;
    newNextNode->prev = argNode;

    newNextNode->next = oldNextNode;
    oldNextNode->prev = newNextNode;
    size++;

    return 1;
}

template<class T>
void DubLinkedList<T>::deleteNode(Node<T>* argNode) {

    if (!argNode) return;

    Node<T>* toDelete = argNode;
    Node<T>* prevNode = argNode->prev;
    Node<T>* nextNode = argNode->next;

    prevNode->next = nextNode;
    nextNode->prev = prevNode;

    delete toDelete;
    toDelete = nullptr;
    size--;
}

template<class T>
int DubLinkedList<T>::getSize() {
    return size;
}

template<class T>
void DubLinkedList<T>::display() {
    Node<T>* currPtr = headPtr->next;

    cout << "-----------------LIST-----------------\n";

    while (currPtr && currPtr != tailPtr) {
        currPtr->data.display();
        currPtr = currPtr->next;
    }
    cout << "--------------------------------------\n";
}

template<class T>
Node<T>* DubLinkedList<T>::begin() {
    return headPtr->next;
}

template<class T>
Node<T>* DubLinkedList<T>::end() {
    return tailPtr;
}

void Circle::display() {
    cout << "Color: " << color << endl;
    cout << "Radius: " << radius << endl;
}




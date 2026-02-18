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

int main() {

    srand(time(0));

    DubLinkedList<string> myList;
    vector<string> names = {"Jesus", "Maria", "Fatima", "Gustavo", "Candi", "Joel"};

    for (int i = 0; i < 10; ++i) {
        myList.pushBack(names[rand() % names.size()]);
    }

    myList.display();

    cout << "\nGET SIZE EXAMPLE ---------------------\n";
        cout << "\tList Size: " << myList.getSize() << endl;

    cout << "\nPUSH FRONT EXAMPLE ---------------------\n";
        myList.pushFront("Dylan");
        cout << "\tPush Front 'Dylan'" << endl;
        cout << "\nUpdated List: \n";
        myList.display();

    cout << "\nPUSH BACK EXAMPLE ---------------------\n";
        myList.pushBack("Jay");
        cout << "\tPush Front 'Jay'" << endl;
        cout << "\nUpdated List: \n";
        myList.display();

    cout << "\nPOP FRONT EXAMPLE ---------------------\n";
        myList.popFront();
        cout << "\tPop Front()" << endl;
        cout << "\nUpdated List: \n";
        myList.display();

    cout << "\nPOP BACK EXAMPLE ---------------------\n";
        myList.popBack();
        cout << "\tPop Back()" << endl;
        cout << "\nUpdated List: \n";
        myList.display();

    cout << "\nINSERT AFTER EXAMPLE ---------------------\n";

        int counter = 3;
        cout << "\tInsert 'Antonio' After " <<  counter << "rd Node: " << endl;
        Node<string>* it = myList.begin();

        while (counter > 1) {
            counter--;
            it = it->next;
        }

        myList.insertAfter(it, "Antonio");
        cout << "\nUpdated List: \n";
        myList.display();

    cout << "\nDELETE NODE EXAMPLE ---------------------\n";
        myList.deleteNode(it->next);
        cout << "\tDelete Node containing 'Antonio'" << endl;
        cout << "\nUpdated List: \n";
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
    Node<T>* currPtr = headPtr->next;

    while (currPtr && currPtr != argNode) {
        currPtr = currPtr->next;
    }

    if (currPtr == argNode) {
        Node<T>* thisNode = currPtr;
        Node<T>* oldNextNode = thisNode->next;
        Node<T>* newNextNode = new Node<T>(argData);

        thisNode->next = newNextNode;
        newNextNode->prev = thisNode;

        newNextNode->next = oldNextNode;
        oldNextNode->prev = newNextNode;
        size++;

        return 1;
    }

    return 0;
}

template<class T>
void DubLinkedList<T>::deleteNode(Node<T>* argNode) {
    Node<T>* currPtr = headPtr->next;

    while (currPtr != argNode && currPtr) {
        currPtr = currPtr->next;
    }

    if (currPtr == argNode) {
        Node<T>* toDelete = currPtr;
        Node<T>* prevNode = currPtr->prev;
        Node<T>* nextNode = currPtr->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;

        delete toDelete;
        toDelete = nullptr;
        size--;
    }
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
        cout << currPtr->data << endl;
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




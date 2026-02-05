#include <iostream> 
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// Class that defines the node object
class Node {
private:
    char item;
    Node* nextPtr;

public:
    //constructors
    Node();
    Node(char);
    Node(char, Node*);

    //Accessor Methods
    void setItem(char);
    char getItem();
    void setNextPtr(Node*);
    Node* getNextPtr();

};

//regular c-type function for printing the Linked List
void printStringList(Node* beginningNodePtr);

int main(void) {

    srand(time(0));

    Node* head = new Node(char(97 + rand() % 26));
    Node* tempPtr = head;

    for (int i = 0; i < 99; ++i) {
        tempPtr->setNextPtr(new Node(char(97 + rand() % 26)));
        tempPtr = tempPtr->getNextPtr();
    }

    printStringList(head);

    while (tempPtr != nullptr) {

            Node* deleteThis = tempPtr;
            tempPtr = tempPtr->getNextPtr();

            delete deleteThis;
            deleteThis = nullptr;

    }

    return (0);
}

void printStringList(Node* beginningNodePtr) {

    Node* tempNodePtr = beginningNodePtr;

    cout << "******************" << endl;
    if (tempNodePtr == nullptr) {
        cout << "List Empty" << endl;
    }
    else {
        while (tempNodePtr != nullptr) {

            cout << tempNodePtr->getItem() << endl;
            tempNodePtr = tempNodePtr->getNextPtr();

        };

    }
    cout << "******************" << endl;

}


//Node Implementation
Node::Node()
{
    setItem(' '); //default to space string
    setNextPtr(nullptr); //default to null pointer
}

Node::Node(char arg)
{
    setItem(arg);
    setNextPtr(nullptr);
}

Node::Node(char arg, Node* argPtr)
{
    setItem(arg);
    setNextPtr(argPtr);
}

void Node::setItem(char arg)
{
    item = arg;
}

char Node::getItem()
{
    return item;
}

void Node::setNextPtr(Node* argPtr)
{
    nextPtr = argPtr;
}

Node* Node::getNextPtr()
{
    return nextPtr;
}

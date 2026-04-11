#include <iostream>
#include <vector>

using namespace std;

struct Person {
    string name;
    int age;

    Person(string arg1, int arg2) {
        name = arg1;
        age = arg2;
    }
};

class TreeNode {
    public:
        Person* person;
        TreeNode* leftBranch;
        TreeNode* rightBranch;

        TreeNode() : person(nullptr), leftBranch(nullptr), rightBranch(nullptr) {}
        TreeNode(Person* argPers) : person(argPers), leftBranch(nullptr), rightBranch(nullptr) {}

        void inOrder();
        TreeNode* insert(TreeNode* root, Person* argPers);
        TreeNode* dealloTree(TreeNode* root);
        void report();
};

int main() {

    Person* james = new Person("James", 23);
    Person* harry = new Person("Harry", 28);
    Person* natalie = new Person("Natalie", 29);
    Person* horton = new Person("Horton", 25);
    Person* larry = new Person("Larry", 44);
    Person* roman = new Person("Roman", 28);

    TreeNode* root = new TreeNode(james);

    TreeNode* rootChild1 = new TreeNode(harry);
    TreeNode* rootChild2 = new TreeNode(natalie);

    TreeNode* leafNode1 = new TreeNode(horton);
    TreeNode* leafNode2 = new TreeNode(larry);
    TreeNode* leafNode3 = new TreeNode(roman);

    root->leftBranch = rootChild1;
    root->rightBranch = rootChild2;

    rootChild1->rightBranch = leafNode1;

    rootChild2->leftBranch = leafNode2;
    rootChild2->rightBranch = leafNode3;

    cout << "\n***** Initial Tree *****\n";
    cout << "\n---inOrder()---\n";
    root->inOrder();
    cout << "\n---report()---\n";
    root->report();

    // ADD ANOTHER PERSON

    char addPerson = 'n';
    vector<Person*> addedPeople;

    cout << "\nAdd a Person? (y/n): ";
    cin >> addPerson;

    while (tolower(addPerson) == 'y') {
    
        string name = "";
        int age = 0;
        cout << "Enter Name: ";
        cin >> name;
        cout << "\nEnter Age: ";
        cin >> age;



        cout << "\n***** After Adding Person *****\n";
        Person* addedPerson = new Person(name, age);
        root->insert(root, addedPerson);
        addedPeople.push_back(addedPerson);

        cout << "\n---inOrder()---\n";
        root->inOrder();
        cout << "\n---report()---\n";
        root->report();

        cout << "\nAdd another Person? (y/n): ";
        cin >> addPerson;
    }

    delete james;
    delete harry;
    delete natalie;
    delete horton;
    delete larry;
    delete roman;
    for (Person* person : addedPeople) {
        delete person;
    }

    root = root->dealloTree(root);

    return 0;
}

void TreeNode::inOrder() {
    if (leftBranch) leftBranch->inOrder();
    cout << person->name << endl;
    if (rightBranch) rightBranch->inOrder();
}

TreeNode* TreeNode::insert(TreeNode* root, Person* argPers) {

    if (!root) 
        return new TreeNode(argPers);

    if (argPers->name < root->person->name) 
        root->leftBranch = insert(root->leftBranch, argPers);
    else {
        root->rightBranch = insert(root->rightBranch, argPers);
    }

    return root;
}

TreeNode* TreeNode::dealloTree(TreeNode* root) {
    if (!root) return root;

    dealloTree(root->leftBranch);
    dealloTree(root->rightBranch);

    delete root;
    return nullptr;
}

void TreeNode::report() {
    cout << person->name << endl;
    if (rightBranch) rightBranch->report();
    if (leftBranch) leftBranch->report();

}



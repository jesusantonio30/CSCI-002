#include <iostream>
#include <vector>

using namespace std;

template<class T>
class TreeNode {
    public:
        T data;
        TreeNode* leftTN;
        TreeNode* rightTN;

        TreeNode(T dataArg) : data(dataArg), leftTN(nullptr), rightTN(nullptr) {}

        TreeNode<T>* searchTree(TreeNode* root, T val);
        TreeNode<T>* deleteNode(TreeNode* root, T val);
        TreeNode<T>* findMin(TreeNode* root);
        TreeNode<T>* insertNode(TreeNode* root, T val);
        TreeNode<T>* dealloTree(TreeNode* root);
        void printTree(TreeNode* root);

};

int main() {

    TreeNode<string>* myTree = nullptr;
    string userStr = "y";
    string toDelete = " ";

    cout << "1. Enter a string to create a Binary Tree.\n";
    cout << "2. Continue entering strings to grow BT.\n";
    cout << "3. Enter a ' ' to stop.\n\n";

    do {

        cout << "Enter a string: ";
        getline(cin, userStr);

        if (userStr != " " && myTree)
            myTree = myTree->insertNode(myTree, userStr);
        else if (userStr != " " && !myTree) {
            myTree = new TreeNode(userStr);
        }

    } while (userStr != " ");

    if (myTree) {

    // Print In Order
        cout << "Tree => ";
        myTree->printTree(myTree);
    
    // Delete a Tree Node
        cout << "\n\n1. Enter a string to delete from Binary Tree.\n";
        cout << "2. Continue entering strings to delete from BT.\n";
        cout << "3. Enter a ' ' to stop.\n\n";

        do {

            cout << "Enter a string to delete: ";
            getline(cin, toDelete);

            if (toDelete != " " && myTree)
                myTree = myTree->deleteNode(myTree, toDelete);
            else if (!myTree) {
                cout << "Tree is empty!\n";
                toDelete = " ";
            }

        } while (toDelete != " ");

        if (myTree) {
            cout << "Tree => ";
            myTree->printTree(myTree);

        // Deallocate Tree 
            myTree = myTree->dealloTree(myTree);
        }
        
    }

    return 0;
}

template<class T>
TreeNode<T>* TreeNode<T>::searchTree(TreeNode* root, T val) {
    if (!root) return nullptr;

    if (val < root->data) 
        return searchTree(root->leftTN, val);
    else if (val > root->data)
        return searchTree(root->rightTN, val);
    else 
        return root;
}

template<class T>
TreeNode<T>* TreeNode<T>::deleteNode(TreeNode* root, T val) {
    
    if (!root) return root;

    if (val < root->data) {
        root->leftTN = deleteNode(root->leftTN, val);
    } else if (val > root->data) {
        root->rightTN = deleteNode(root->rightTN, val);
    } else {

        if (!root->rightTN) {
            TreeNode* temp = root->leftTN;
            delete root;
            return temp;
        }

        else if (!root->leftTN) {
            TreeNode* temp = root->rightTN;
            delete root;
            return temp;
        }

        else {
            TreeNode* min = findMin(root->rightTN);
            root->data = min->data;
            root->rightTN = deleteNode(root->rightTN, min->data);
        }
    }

    return root;
    
}

template<class T>
TreeNode<T>* TreeNode<T>::findMin(TreeNode* root) {
    TreeNode* curr = root;

    while (curr && curr->leftTN) {
        curr = curr->leftTN;
    }

    return curr;
}

template<class T>
TreeNode<T>* TreeNode<T>::insertNode(TreeNode* root, T val) {
    if (!root) return new TreeNode(val);

    if (val < root->data) {
        root->leftTN = insertNode(root->leftTN, val);
    } else {
        root->rightTN = insertNode(root->rightTN, val);
    }

    return root;
}

template<class T>
TreeNode<T>* TreeNode<T>::dealloTree(TreeNode* root) {
    if (!root) return root;

    dealloTree(root->leftTN);
    dealloTree(root->rightTN);

    delete root;
    return nullptr;
}

template<class T>
void TreeNode<T>::printTree(TreeNode* root) {
    if (!root) return;

    printTree(root->leftTN);
    cout << root->data << " ";
    printTree(root->rightTN);
}

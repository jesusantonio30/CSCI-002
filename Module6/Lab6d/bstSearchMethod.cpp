#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class TreeNode {
    public:
        int data;
        TreeNode* leftTN;
        TreeNode* rightTN;

        TreeNode(int dataArg) : data(dataArg), leftTN(nullptr), rightTN(nullptr) {}

        TreeNode* searchTree(TreeNode* root, int val);
};

TreeNode* insertToTree(TreeNode* root, int val);

int main() {
    srand(time(0));

    vector<int> myVec;

    for (int i = 0; i < 15; i++) {
        myVec.push_back(rand() % 100);
    }

    TreeNode* myTree = new TreeNode(myVec[0]);

    for (int i = 1; i < myVec.size(); i++) {
        insertToTree(myTree, myVec[i]);
    }

    // TESTS

    int numInTree = myVec[rand() % myVec.size()];
    int numNotInTree = 100 + myVec[rand() % myVec.size()];

    TreeNode* result = myTree->searchTree(myTree, numInTree);

    cout << "    ------ GOOD TO KNOW ------\n";
    cout << "Tree values range from 0 to 99.\n\n";

    if (result)
        cout << "Value " << numInTree << " found in Tree: " << result << " -> " << result->data << endl;
    else 
        cout << "Value " << numInTree << " not found in Tree.\n";

    
    result = myTree->searchTree(myTree, numNotInTree);

    if (result)
        cout << "Value " << numNotInTree << " found in Tree: " << result << " -> " << result->data << endl;
    else 
        cout << "Value " << numNotInTree << " not found in Tree.\n";



    return 0;
}


TreeNode* insertToTree(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);

    if (val < root->data) 
        root->leftTN = insertToTree(root->leftTN, val);
    else 
        root->rightTN = insertToTree(root->rightTN, val);

    return root;
}

TreeNode* TreeNode::searchTree(TreeNode* root, int val) {
    if (!root) return nullptr;

    if (val < root->data) 
        return searchTree(root->leftTN, val);
    else if (val > root->data)
        return searchTree(root->rightTN, val);
    else 
        return root;
}


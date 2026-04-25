#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BinaryTree {
private:
    TreeNode* root;

    TreeNode* insert(TreeNode* node, int val) {
        if (!node) return new TreeNode(val);
        if (val < node->data)
            node->left = insert(node->left, val);
        else if (val > node->data)
            node->right = insert(node->right, val);
        return node;
    }

    TreeNode* search(TreeNode* node, int val) {
        if (!node) return nullptr;
        if (val < node->data)  return search(node->left, val);
        if (val > node->data)  return search(node->right, val);
        return node;
    }

    void destroy(TreeNode* node) {
        if (!node) return;
        destroy(node->left);
        destroy(node->right);
        delete node;
    }

public:
    BinaryTree() : root(nullptr) {}
    ~BinaryTree() { destroy(root); }

    void insert(int val)          { root = insert(root, val); }
    TreeNode* search(int val)     { return search(root, val); }
};

int main() {
    srand(time(0));

    vector<int> myVec;
    for (int i = 0; i < 15; i++)
        myVec.push_back(rand() % 100);

    BinaryTree myTree;
    for (int val : myVec)
        myTree.insert(val);

    // Test: value known to be in the tree
    int numInTree = myVec[rand() % myVec.size()];
    int numNotInTree = 100 + myVec[rand() % myVec.size()];
    TreeNode* result = myTree.search(numInTree);
    if (result)
        cout << "Value " << numNotInTree << " found in Tree: " << result << " -> " << result->data << endl;
    else 
        cout << "Value " << numNotInTree << " not found in Tree.\n";

    // Test: value known to be outside the tree
    numNotInTree = 100;
    result = myTree.search(numNotInTree);
    if (result)
        cout << "Value " << numNotInTree << " found in Tree: " << result << " -> " << result->data << endl;
    else 
        cout << "Value " << numNotInTree << " not found in Tree.\n";

    return 0;
}
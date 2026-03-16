#include <iostream>

using namespace std;

class TreeNode {
    public:
        int val;
        TreeNode* leftBranch;
        TreeNode* rightBranch;

        TreeNode() : val(0), leftBranch(nullptr), rightBranch(nullptr) {}
        TreeNode(int argVal) : val(argVal), leftBranch(nullptr), rightBranch(nullptr) {}
};

int main() {

    TreeNode* root = new TreeNode(8);

    TreeNode* rootChild1 = new TreeNode(3);
    TreeNode* rootChild2 = new TreeNode(10);

    // I am aware that this is a leaf node as well since both pointers are null
    TreeNode* rootGrandChild1 = new TreeNode(1);

    TreeNode* rootGrandChild2 = new TreeNode(6);
    TreeNode* rootGrandChild3 = new TreeNode(14);

    TreeNode* leafNode1 = new TreeNode(4);
    TreeNode* leafNode2 = new TreeNode(7);
    TreeNode* leafNode3 = new TreeNode(13);

    root->leftBranch = rootChild1;
    root->rightBranch = rootChild2;

    rootChild1->leftBranch = rootGrandChild1;
    rootChild1->rightBranch = rootGrandChild2;

    rootChild2->rightBranch = rootGrandChild3;

    rootGrandChild2->leftBranch = leafNode1;
    rootGrandChild2->rightBranch = leafNode2;

    rootGrandChild3->leftBranch = leafNode3;

    delete root;
    delete rootChild1;
    delete rootChild2;
    delete rootGrandChild1;
    delete rootGrandChild2;
    delete rootGrandChild3;
    delete leafNode1;
    delete leafNode2;
    delete leafNode3;

    return 0;
}




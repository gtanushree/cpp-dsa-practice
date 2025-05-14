// Code for maximum depth in Binary Tree
// Time: O(n), Space: O(n)

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val = value;
        left = right = nullptr;
    }
};

class Solution{
    public:
    int maxDepth(TreeNode* root){           // Recursive function
        if(root == NULL) return 0;
        int lh = maxDepth(root->left);
        int rh = maxDepth(root->right);

        return 1 + max(lh, rh);
    }
};

int main(){
    // Create sample binary tree
    //          1
    //         / \ 
    //        2   3
    //           / \ 
    //          4   6
    //         /
    //        5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(6);
    root->right->left->left = new TreeNode(5);

    Solution s;

    int depth = s.maxDepth(root);
    cout << "Maximum depth of the binary tree is: " << depth << endl;

    return 0;
}
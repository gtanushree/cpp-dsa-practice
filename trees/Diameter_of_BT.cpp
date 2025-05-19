// Diameter of a binary Tree = longest path between two nodes
// Path does not need to pass via root
// Code for diameter of Binary Tree
// Time: O(n), Space: O(n)

#include <iostream>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int value){
        val = value;
        left=right=nullptr;
    }
};

class Solution{
    public:
    int diameterOfBinaryTree(TreeNode* root){
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
    private:
    int height(TreeNode* node, int& diameter){
        if(!node) return 0;
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh+rh);
        return 1 + max(lh, rh);
    }
};

int main(){
    // Example of Binary Tree:
    //          1
    //         / \ 
    //        2   3
    //           / \ 
    //          4   5 
    //         /     \ 
    //        6       7
    //       /         \ 
    //      8           9

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->left->left = new TreeNode(6);
    root->right->left->left->left = new TreeNode(8);
    root->right->right = new TreeNode(5);
    root->right->right->right = new TreeNode(7);
    root->right->right->right->right = new TreeNode(9);
    
    Solution s;

    int result = s.diameterOfBinaryTree(root);
    cout << "Diameter of the Binary Tree is: " << result << endl;

    return 0;
}
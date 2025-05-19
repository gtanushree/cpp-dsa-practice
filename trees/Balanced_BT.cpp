// Code to check if a given binary tree is balanced
// Time: O(n), Space: O(n)

#include <iostream>
#include <stdlib.h>

using namespace std;

struct TreeNode
{
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
    int check(TreeNode* root){
        if (root == NULL) return 0;

        int lh = check(root->left);
        int rh = check(root->right);

        if (lh == -1 || rh == -1) return -1;
        if (abs(lh-rh) > 1) return -1;

        return max(lh, rh) + 1;
    }
};

int main(){
    // Binary Tree:
    //              1
    //             / \ 
    //            2   3
    //           / \   \ 
    //          4   5   6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution s;

    int depth = s.check(root);

    if (depth < 0){
        cout<<"The given Binary Tree is not balanced."<<endl;
    }
    else{
        cout<<"The given binary tree is balanced and it's height is: "<< depth<< endl;
    }

    return 0;
}
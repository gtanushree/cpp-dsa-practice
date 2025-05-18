#include <iostream>
#include <climits>

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
    int maxPathSum(TreeNode* root){
        int maxi = INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }
    private:
    int maxPathDown(TreeNode* node, int& maxi){
        if(node==NULL) return 0;
        int left = max(0, maxPathDown(node->left, maxi));
        int right = max(0, maxPathDown(node->right, maxi));
        maxi = max(maxi, left+right+node->val);
        return max(left, right) + node->val;
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

    int result = s.maxPathSum(root);
    cout << "The maximun path sum of the binary tree is: " << result << endl;

    return 0;
}
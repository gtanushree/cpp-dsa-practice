// Code to check if two trees are identical or not
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
    bool isSameTree(TreeNode* p, TreeNode* q){
        if (p==NULL || q==NULL) return (p==q);

        return(p->val==q->val)
        && isSameTree(p->left, q->left)
        && isSameTree(p->right, q->right);
    }
};

int main(){
    // Example of Binary Trees
    //              1                               1
    //             / \                             / \
    //            2   3                           2   3
    //               / \                             / \
    //              4   5                           4   5

    TreeNode* root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->right->left = new TreeNode(4);
    root1->right->right = new TreeNode(5);

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution s;

    bool result = s.isSameTree(root1, root);

    if(result){
        cout<<"The Binary Trees are Identical."<<endl;
    }
    else{
        cout<<"The Binary Trees are Non-Identical."<<endl;
    }
}
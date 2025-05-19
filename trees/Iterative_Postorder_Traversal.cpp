// Code for iterative postorder traversal of binary tree using two stacks.
// Time: O(n), Space: O(n)

#include <iostream>
#include <vector>
#include <stack>

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value){
        val=value;
        left=right=nullptr;
    }
};

class Solution{
    public:
    vector<int> PostorderTraversal (TreeNode*root){
        vector<int>postorder;
        if(root==NULL) return postorder;
        stack<TreeNode*> st1, st2;
        st1.push(root);
        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left!=NULL){
                st1.push(root->left);
            }
            if(root->right!=NULL){
                st1.push(root->right);
            }
        }
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};

int main(){
    // Create sample binary tree:
    //              1
    //             / \ 
    //            2   3
    //           / \   \ 
    //          4   5   6
    //                 /
    //                7
    //                 \ 
    //                  8

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->right->right->left = new TreeNode(7);
    root->right->right->left->right = new TreeNode(8);

    Solution s;
    vector<int>result = s.PostorderTraversal(root);
    cout<<"Postorder Traversal: "<<endl;
    for(int val: result){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}
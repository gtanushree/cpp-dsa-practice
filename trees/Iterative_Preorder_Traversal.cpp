// Code for iterative preorder traversal of binary tree.
// Time: O(n), Space: O(n)

#include <iostream>
#include <vector>
#include <stack>

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

class Solution {
    public:
    vector<int> PreorderTraversal(TreeNode* root){
        vector<int> preorder;
        if (root == NULL) return preorder;

        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()){
            root = st.top();
            st.pop();
            preorder.push_back(root->val);
            if (root->right != NULL){
                st.push(root->right);
            }
            if (root->left != NULL){
                st.push(root->left);
            }
        }
        return preorder;
    }
};

int main(){
    // Create sample binary tree:
    //              1
    //             / \
    //            2   7
    //           / \   
    //          3   6
    //         / \ 
    //        4   5

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(6);
    root->left->left->left = new TreeNode(4);
    root->left->left->right = new TreeNode(5);

    Solution s;
    vector<int>result = s.PreorderTraversal(root);
    cout << "Preorder Traversal: " << endl;
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;    

    return 0;
}
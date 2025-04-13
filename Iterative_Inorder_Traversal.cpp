// Code for iterative inorder traversal in binary tree
// Time: O(n), Space: O(n)

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode (int value){
        val = value;
        left = right = nullptr;
    }
};

class Solution{
    public:
    vector<int> InorderTraversal (TreeNode* root){
        stack<TreeNode*> st;
        TreeNode* node = root;
        vector<int> inorder;
        while(true){
            if(node!=NULL){
                st.push(node);
                node = node->left;
            }
            else{
                if(st.empty()==true){
                    break;
                }
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};

int main(){
    // Create sample binary tree:
    //              1
    //             / \
    //            2   3
    //           / \ 
    //          4   5
    //             / \
    //            6   7

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->left->right->left = new TreeNode(6);
    root->left->right->right = new TreeNode(7);

    Solution s;
    vector<int>result = s.InorderTraversal(root);
    cout<<"Inorder Traversal: "<<endl;
    for(int val: result){
        cout<<val<<" ";
    }
    cout<<endl;

    return 0;
}

// Code for iterative postorder traversal of binary tree using one stack.
// Time: O(2n), Space: O(n)

# include <iostream>
# include <vector>
# include <stack>

using namespace std;

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
    vector<int> PostorderTraversal(TreeNode* root){
        vector<int> postorder;
        if (root==NULL) return postorder;

        stack<TreeNode*> st;
        TreeNode* current = root;
        TreeNode* lastVisited = nullptr;

        while ( current!=nullptr || !st.empty()){
            if (current!=nullptr){
                st.push(current);
                current=current->left;
            }
            else{
                TreeNode* peekNode = st.top();

                if (peekNode->right != nullptr && lastVisited != peekNode->right)
                {
                    current=peekNode->right;
                }
                else{
                    postorder.push_back(peekNode->val);
                    lastVisited = peekNode;
                    st.pop();
                }   
            }
        }
    }
};

int main(){
    // Create sample binary tree:
    //              1
    //             / \  
    //            2   7
    //           /   / \ 
    //          3   8   9
    //           \       \ 
    //            4       10
    //             \ 
    //              5
    //               \ 
    //                6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(7);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->left->right->right = new TreeNode(5);
    root->left->right->right->right = new TreeNode(6);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(9);
    root->right->right->left = new TreeNode(10);

    Solution s;
    vector<int> result = s.PostorderTraversal(root);

    cout << "Postorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
// Code for Zig-Zag or Spiral Traversal of a Binary Tree
// Time: O(n), Space: O(n)

#include <iostream>
#include <queue>
#include <vector>

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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> result;     // declaring the vector result
        if (root == NULL) return result;

        queue<TreeNode*> nodesQueue;    // declaring the queue as nodesQueue
        nodesQueue.push(root);          // pushing the value of root node into the queue data structure
        
        bool leftToRight = true;        // initially declaring the flag

        while (!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int> row(size);

            for(int i=0; i<size; i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                // find position to fill node's value
                int index = (leftToRight) ? i : (size - i - 1); // key step

                row[index] = node->val;
                if (node->left){
                    nodesQueue.push(node->left);
                }
                if (node->right){
                    nodesQueue.push(node->right);
                }
            }

            // after this level
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};

int main(){
    // Example of a binary tree
    //          1
    //         / \ 
    //        2   3
    //       /   / \ 
    //      4   5   6
    
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->right->left = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution s;

    vector<vector<int>> traversal = s.zigzagLevelOrder(root);

    cout << "The Zig-Zag level-order traversal of the binary tree is:\n";
    for (const auto& level : traversal) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
    return 0;
}
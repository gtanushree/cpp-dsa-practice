// Code for Vertical Order Traversal of a Binary Tree
// Time: O(n log n), Space: O(n)

#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>

using namespace std;

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int value){
        val = value;
        left=right=nullptr;
    }
};

class Solution{
    public:
    vector<vector<int>> verticalTraversal(TreeNode* root){
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0, 0}});
        while(!todo.empty()){
            auto p = todo.front();
            todo.pop();
            TreeNode *node = p.first;
            int x=p.second.first, y=p.second.second;
            nodes[x][y].insert(node->val);
            if(node->left){
                todo.push({node->left, {x-1, y+1}});
            }
            if(node->right){
                todo.push({node->right, {x+1, y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p:nodes){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

int main(){
    // Example of Binary Tree:
    //          1
    //         / \ 
    //        2   3
    //       / \ / \ 
    //      4 10 9 10
    //      \ 
    //       5
    //        \ 
    //         6

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);

    Solution s;
    vector<vector<int>> traversal = s.verticalTraversal(root);

    cout << "Vertical Order Traversal:\n";
    for (auto& col : traversal) {
        for (int val : col) {
            cout << val << " ";
        }
        cout << endl;
    }

    return 0;
}
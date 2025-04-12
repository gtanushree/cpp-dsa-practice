// Code for Recursive DFS
// Time: O(n), Space: Worst-case space: O(N) | Average/balanced-case: O(log N)

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value){
        data = value;
        left = right = nullptr;
    }
};

//Inorder Traversal
void inorder(Node* root){
    if (root != nullptr){
        inorder(root->left);
        cout<<root->data<<" ";
        inorder(root->right);
    }
};

//Preorder Traversal
void preorder(Node* root){
    if (root != nullptr){
        cout<<root->data<<" ";
        preorder(root->left);
        preorder(root->right);
    }
};

//Postorder Traversal
void postorder(Node* root){
    if (root != nullptr){
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<" ";
    }
};

int main(){
    // Tree:
    //          1
    //         / \
    //        2   3
    //       / \
    //      4   5

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    cout << "Inorder Traversal: ";
    inorder(root);

    cout << "\nPreorder Traversal: ";
    preorder(root);

    cout << "\nPostorder Traversal: ";
    postorder(root);
}
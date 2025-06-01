// Code for Deleting Node Without Head Pointer given only a pointer to a node (not head), delete it.

#include <iostream>

using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int value) {
        val = value;
        next = nullptr;
    }
};

void deleteNode(Node* node) {
    if (node == nullptr || node->next == nullptr) {
        cout << "Can't delete the node (null or tail node)." << endl;
        return;
    }

    Node* temp = node->next;
    node->val = temp->val;
    node->next = temp->next;
    delete temp;
}

void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Create linked list: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original List: ";
    printList(head);

    Node* nodeToDelete = head->next->next; 
    deleteNode(nodeToDelete);

    cout << "After Deleting Node 3: ";
    printList(head);

    return 0;
}

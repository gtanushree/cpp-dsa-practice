// Code for Swapping Nodes in Pairs
// Given a singly linked list, swap every two adjacent nodes and return its head.

#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int value){
        val = value;
        next = nullptr;
    }
};

void printList(Node* head){
    while(head){
        cout<<head->val<<" ";
        head = head->next;
    }
    cout<<endl;
}

Node* swapPairs(Node* head) {
    if (!head || !head->next) return head;

    Node* dummy = new Node(0);  
    dummy->next = head;
    Node* prev = dummy;

    while (head && head->next) {
        Node* first = head;
        Node* second = head->next;

        prev->next = second;
        first->next = second->next;
        second->next = first;

        prev = first;
        head = first->next;
    }

    return dummy->next;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);

    cout << "Original List: ";
    printList(head);

    head = swapPairs(head);

    cout << "Swapped in Pairs: ";
    printList(head);

    return 0;
}
// Code to apply Merge Sort on an unsorted Linked List
// Time: O(n log n), Space: O(n log n)

#include <iostream>

using namespace std;

struct Node{
    int val;
    Node *next, *prev;
    Node(int x): val(x), next(nullptr), prev(nullptr) {}
};

// function to split the list into two halves
Node* split(Node *head){
    Node* fast = head; // fast will move 2 nodes at a time.
    Node* slow = head; // slow will move 1 node at a time.

    // Tortoise and Hare approach: When fast reaches the end, slow will be at the middle of the list.
    while(fast->next && fast->next->next){
        fast = fast->next->next;
        slow = slow->next;
    }

    Node *second = slow->next; // store the second hald starting from slow->next.
    slow->next = nullptr; // disconnects slow from second to break list into two halves.
    if (second) second->prev = nullptr; // So that the second half has no backward connection to the first.

    return second; // returns the head of the second half.
}

// Function to merge two sorted doubly linked lists
Node* merge(Node *first, Node *second){
    if(!first) return second;
    if(!second) return first;

    if(first->val < second->val){
        first->next = merge(first->next, second);
        if(first->next) first->next->prev = first;
        first->prev = nullptr;
        return first;
    }else{
        second->next = merge(first, second->next);
        if(second->next) second->next->prev = second;
        second->prev = nullptr;
        return second;
    }
}

Node* mergeSort(Node *head){
    if(!head || !head->next) return head;

    Node *second = split(head);

    head = mergeSort(head);
    second = mergeSort(second);

    return merge(head, second);
}

void push(Node*& head, int data) {
    Node* newNode = new Node(data);
    if (!head) {
        head = newNode;
        return;
    }

    Node* temp = head;
    while (temp->next) temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void printList(Node *head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main() {
    Node* head = nullptr;

    push(head, 4);
    push(head, 2);
    push(head, 5);
    push(head, 1);
    push(head, 3);

    cout << "Original DLL: ";
    printList(head);

    head = mergeSort(head);

    cout << "Sorted DLL: ";
    printList(head);

    return 0;
}

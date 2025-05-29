#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int value){
        val=value;
        next=nullptr;
    }
};

Node* reverse(Node* head){
    Node* prev = nullptr;
    Node* current = head;
    while(current){
        Node* next = current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    return prev;
};

void reorderList(Node* head) {
    if (!head || !head->next) return;

    // Step 1: Find middle using slow and fast pointers
    Node* slow = head;
    Node* fast = head;
    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // Step 2: Reverse second half
    Node* second = reverse(slow->next);
    slow->next = nullptr;

    // Step 3: Merge two halves
    Node* first = head;
    while (second) {
        Node* temp1 = first->next;
        Node* temp2 = second->next;

        first->next = second;
        second->next = temp1;

        first = temp1;
        second = temp2;
    }
}

void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // List: 1 -> 2 -> 3 -> 4 -> 5
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    cout << "Original list: ";
    printList(head);

    reorderList(head);

    cout << "Reordered list: ";
    printList(head);

    return 0;
}
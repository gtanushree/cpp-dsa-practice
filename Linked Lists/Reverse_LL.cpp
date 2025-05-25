// Code to reverse a Singly Linked List
// Time: O(n), Space: O(n)

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

class LinkedList{
    Node* head;

    public:
    LinkedList(){
        head = nullptr;
    }

    Node* reverseList(Node* head){
        Node* prev = nullptr;
        Node* current = head;
        Node* next = nullptr;

        while(current!=nullptr){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        return prev;
    }

    void printList(Node* head) {
        while (head != nullptr) {
        cout << head->val << " ";
        head = head->next;
        }
        cout << endl;
    }
};

int main(){
    // Example of a Singly Linked List
    // 1 -> 2 -> 3 -> 4 -> 5 -> 6

    LinkedList list;

    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout<<"Original list: ";
    list.printList(head);

    head = list.reverseList(head);
    cout<<"Reverse list: ";
    list.printList(head);

    return 0;
}
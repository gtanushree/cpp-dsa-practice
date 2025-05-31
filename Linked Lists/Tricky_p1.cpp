// Code to Segregate Even and Odd nodes such that all even nodes come before odd.

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

Node* segregateOddEven(Node* head){
    if(!head || !head->next) return head;

    Node* OddStart = nullptr;
    Node* OddEnd = nullptr;
    Node* EvenStart = nullptr;
    Node* EvenEnd = nullptr;

    Node* current = head;

    while(current){
        int data = current->val;
        if(data%2 == 0){
            if(!EvenStart) EvenStart = EvenEnd = current;
            else{
                EvenEnd->next=current;
                EvenEnd=EvenEnd->next;
            }
        }
        else{
            if(!OddStart) OddStart = OddEnd = current;
            else{
                OddEnd->next=current;
                OddEnd=OddEnd->next;
            }
        }
        current=current->next;
    }

    if(!EvenStart || !OddStart) return head;
    EvenEnd->next=OddStart;
    OddEnd->next=nullptr;

    return EvenStart;
};

void printList(Node* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    cout<<"Original List: ";
    printList(head);

    head = segregateOddEven(head);
    
    cout<<"After Segregation(Even before Odd): ";
    printList(head);

    return 0;
}
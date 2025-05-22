#include <iostream>

using namespace std;

struct Node{
    int val;
    Node* next;
    Node(int value){
        val = value;
        next=nullptr;
    }
};

class LinkedList{
    Node* head;
    public:
    LinkedList(){
        head = nullptr;
    }

    void insertAtBeginning(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    // Insert at end
    void insertAtEnd(int val){
        Node* newNode = new Node(val);
        if(head == nullptr){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next!=nullptr){
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Insert at a given position 
    void insertAtPosition(int val, int position){
        if (position < 1){
            cout << "Invalid position\n";
            return;
        }
        if (position==1){
            insertAtBeginning(val);
            return;
        }
        Node* newNode = new Node(val);
        Node* temp = head;

        for(int i=1; i < position-1 && temp!=nullptr; i++){
            temp = temp->next;
        }

        if(temp==nullptr){
            cout<<"Position out of range.\n";
            delete newNode;
            return;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    void display(){
        Node* temp = head;
        while(temp!=0){
            cout<<temp->val<<"->";
            temp = temp->next;
        }
        cout<<"NULL\n";
    }
};

int main() {
    LinkedList list;
    list.insertAtBeginning(10);
    list.insertAtEnd(30);
    list.insertAtPosition(20, 2);
    list.insertAtPosition(5, 1);
    list.insertAtPosition(40, 10); // Out of range

    cout << "Linked List: ";
    list.display();

    return 0;
}
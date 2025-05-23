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
        head=nullptr;
    }

    // Insert at end (for testing deletions)
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    // Delete from beginning
    void deleteFromBeginning(){
        if(head==nullptr){
            cout<<"List is empty.\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    // Delete from end
    void deleteFromEnd(){
        if(head==nullptr){
            cout<<"List is empty.\n";
            return;
        }

        if (head->next == nullptr) {
            delete head;
            head = nullptr;
            return;
        }

        Node* temp = head;
        while(temp->next->next!=nullptr){
            temp=temp->next;
        }
        delete temp->next;
        temp->next=nullptr;
    }

    // Delete from a given position
    void deleteFromPosition(int position){
        if(position<1 || head==nullptr){
            cout<<"Invalid position or empty list.\n";
            return;
        }

        if(position==1){
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        for(int i=1; i<position-1 && temp!=nullptr; i++){
            temp = temp->next;
        }

        if (temp == nullptr || temp->next == nullptr) {
            cout << "Position out of range.\n";
            return;
        }

        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
    }

    // Display function
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    LinkedList list;
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.insertAtEnd(30);
    list.insertAtEnd(40);

    cout << "Original List: ";
    list.display();

    list.deleteFromBeginning();
    cout << "After deleting from beginning: ";
    list.display();

    list.deleteFromEnd();
    cout << "After deleting from end: ";
    list.display();

    list.deleteFromPosition(2);
    cout << "After deleting from position 2: ";
    list.display();

    list.deleteFromPosition(5); // Out of range
    return 0;
}
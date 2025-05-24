// Code for Merge Sort of a Singly Linked List
// Time: O(n log n), Space: O(n log n)

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

class LinkedList{
    Node* head;

    Node* merge(Node* left, Node* right) {
        if (!left) return right;
        if (!right) return left;

        Node* result = nullptr;
        if (left->val <= right->val) {
            result = left;
            result->next = merge(left->next, right);
        } else {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }

    Node* getMiddle(Node* head) {
        if (!head || !head->next) return head;

        Node* slow = head;
        Node* fast = head->next;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    Node* mergeSort(Node* head) {
        if (!head || !head->next) return head;

        Node* middle = getMiddle(head);
        Node* secondHalf = middle->next;
        middle->next = nullptr;

        Node* left = mergeSort(head);
        Node* right = mergeSort(secondHalf);

        return merge(left, right);
    }

    public:
    LinkedList(){
        head=nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }

        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    void sort() {
        head = mergeSort(head);
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main(){
    // Example of a Singly Linked list
    // 9 -> 4 -> 3 -> 5 -> 11 -> 2

    LinkedList list;
    
    list.insertAtEnd(50);
    list.insertAtEnd(20);
    list.insertAtEnd(40);
    list.insertAtEnd(10);
    list.insertAtEnd(30);

    cout << "Original List: ";
    list.display();

    list.sort();

    cout << "Sorted List: ";
    list.display();

    return 0;
}

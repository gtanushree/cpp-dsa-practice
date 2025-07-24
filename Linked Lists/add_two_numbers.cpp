// Leetcode problem 2: You are given two non-empty linked lists representing two non-negative 
// integers. The digits are stored in reverse order, and each of their nodes contains a 
// single digit. Add the two numbers and return the sum as a linked list.
// Time: O(max(n, m)), Space: O(max(n, m))

#include <iostream>

using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int value){
        val = value;
        next = nullptr;
    }
};

class Solution{
    public:
    ListNode* addTwoNumbers(ListNode *l1, ListNode *l2){
        ListNode *dummy = new ListNode(0);
        ListNode *current = dummy;
        int carry = 0;

        while (l1 != nullptr || l2 != nullptr || carry != 0) {
            int val1 = (l1 != nullptr) ? l1->val : 0;
            int val2 = (l2 != nullptr) ? l2->val : 0;

            int sum = val1 + val2 + carry;
            carry = sum / 10;

            current->next = new ListNode(sum % 10);
            current = current->next;

            if (l1 != nullptr) l1 = l1->next;
            if (l2 != nullptr) l2 = l2->next;
        }

        return dummy->next;
    }

    void printLinkedList(ListNode* head) {
        while (head) {
            cout << head->val;
            if (head->next) cout << " -> ";
            head = head->next;
        }
        cout << endl;
    }
};

int main(){
    ListNode *l1 = new ListNode(0);
    l1 -> next = new ListNode(4);
    l1 -> next -> next = new ListNode(3);

    ListNode *l2 = new ListNode(5);
    l2 -> next = new ListNode(6);
    l2 -> next -> next = new ListNode(4);

    Solution s;

    ListNode *result = s.addTwoNumbers(l1, l2);
    s.printLinkedList(result);
}
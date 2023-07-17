#include <iostream>
#include <vector>
#include <stack>
using namespace std;
/**
 * Definition for singly-linked list.
 */ struct ListNode {
int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<ListNode*> stk1;
        stack<ListNode*> stk2;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        while (p1) {
            stk1.push(p1);
            p1 = p1->next;
        }

        while (p2) {
            stk2.push(p2);
            p2 = p2->next;
        }
        
        ListNode* p = NULL;
        int carry = 0;
        while (!stk1.empty() && !stk2.empty()) {
            ListNode* temp = new ListNode;
            p1 = stk1.top();
            stk1.pop();
            p2 = stk2.top();
            stk2.pop();
            int sum = p1->val + p2->val+carry;
            temp->val =  sum%10;
            carry = sum / 10;
            temp->next = p;
            p = temp;
        }

        while (!stk1.empty()) {
            ListNode* temp = new ListNode;
            p1 = stk1.top();
            stk1.pop();
            int sum = p1->val+ carry;
            temp->val = sum % 10;
            carry = sum / 10;
            temp->next = p;
            p = temp;
        }

        while (!stk2.empty()) {
            ListNode* temp = new ListNode;
            p2 = stk2.top();
            stk2.pop();
            int sum = p2->val + carry;
            temp->val = sum % 10;
            carry = sum / 10;
            temp->next = p;
            p = temp;
        }

        if (carry) {
            ListNode* temp = new ListNode;
            temp->val = 1;
            temp->next = p;
            p = temp;
        }
        return p;
    }
};

int main() {
    Solution s;
    ListNode* l1 = new ListNode;
    l1->val = 0;
    
    
    ListNode* l2 = new ListNode;
    l2->val = 7;
    ListNode* temp2 = new ListNode;
    l2->next = temp2;
    temp2->val = 6;
    ListNode* l3 = s.addTwoNumbers(l1, l2);
    l3;
    return 0;
}
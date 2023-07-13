#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode;
        result->val = 0;
        result->next = NULL;
        ListNode* p = result;
        while (l1 && l2) {
            ListNode* newNode = new ListNode;
            p->val = l1->val + l2->val + p->val;
            newNode->next = NULL;
            if (p->val > 9) {
                newNode->val = 1;
                p->val -= 10;
            }
            else {
                newNode->val = 0;
            }
            p->next = newNode;
            p = newNode;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1) {
            ListNode* newNode = new ListNode;
            p->val = l1->val + p->val;
            newNode->next = NULL;
            if (p->val > 9) {
                newNode->val = 1;
                p->val -= 10;
            }
            else {
                newNode->val = 0;
            }
            p->next = newNode;
            p = newNode;
            l1 = l1->next;
        }
        while (l2) {
            ListNode* newNode = new ListNode;
            p->val = l2->val + p->val;
            newNode->next = NULL;
            if (p->val > 9) {
                newNode->val = 1;
                p->val -= 10;
            }
            else {
                newNode->val = 0;
            }
            p->next = newNode;
            p = newNode;
            l2 = l2->next;
        }
        ListNode* temp = result;
        while (temp->next->next) {
            temp = temp->next;
        }
        if (temp->next->val == 1) return result;
        temp->next = NULL;
        delete p;
        return result;
    }
};

int main() {

    return 0;
}

/*
Best Solution
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode();
        ListNode* temp=dummy;
        int carry=0;
        while(l1!=NULL || l2!=NULL || carry){
            int sum=0;
            if(l1!=NULL){
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                sum+=l2->val;
                l2=l2->next;
            }
            sum+=carry;
            carry=sum/10;
            ListNode* newnode=new ListNode(sum%10);
            temp->next=newnode;
            temp=temp->next;
        }
        return dummy->next;
    }
};
*/
#include <iostream>

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* p = head;
        int i = 0, j = 0;
        int n = maximum(head);
        int l = n / 2;
        int* array = new int[l];
        array = { 0 };
        for (i = 0; i < n / 2; i++) {
            array[i] = p->val;
            p = p->next;
        }

        int temp = 0;
        int max = 0;

        for (j = i; j < n; j++) {
            temp = array[n - j - 1] + p->val;
            max = temp > max ? temp : max;
            p = p->next;
        }
        delete[] array;
        return max;
    }

    int maximum(ListNode* head) {
        ListNode* p = head;
        int max = 0;
        while (p) {
            max++;
            p = p->next;
        }
        return max;
    }

};

/*
Stack version

class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        stack<int>s;
        while(temp){
            s.push(temp->val);
            temp=temp->next;
        }
       int mx=0;
       while(s.size()){
           mx=max(mx,s.top()+head->val);
           head=head->next;
           s.pop();
       }
       return mx;
    }
};

*/
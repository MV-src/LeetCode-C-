#include <iostream>

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
 
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        k--;
        int i, j, size = max(head);
        i = j = 0;

        ListNode* t1, * t2, * ts, *n1, *n2;
        n1 = n2 = t1 = t2 = head;
        ts = NULL;
        if (size == 1) return head;
        for (int i = 0; i < k; i++) {
           
            t1 = n1;
            n1 = n1->next;
        }
        for (int i = 0; i < size - k -1; i++) {
            
            t2 = n2;
            n2 = n2->next;
        }
        if (n2->next == n1 && size == 2) {
            n2->next = n1->next;
            n1->next = head;
            head = n1;
        }else if (n1->next == n2 && k == 0){
            n1->next = n2->next;
            n2->next = head;
            head = n2;
        }else if (n1 == t2) {
            ts = n1->next;
            n1->next = n2->next;
            n2->next = t1->next;
            t1->next = ts;
        } 
        else if (n2 == head) {
            ts = n2->next;
            n2->next = n1->next;
            n1->next = ts;
            t1->next = head;
            head = n1;
        }
        else if (n2 == t1) {
            ts = n2->next;
            n2->next = n1->next;
            n1->next = t2->next;
            t2->next = ts;
        }
        else if (k > 0) {
            ts = n1->next;
            n1->next = n2->next;
            n2->next = ts;
            ts = t1->next;
            t1->next = t2->next;
            t2->next = ts;
        }
        else {
            ts = n1->next;
            n1->next = n2->next;
            n2->next = ts;
            t2->next = head;
            head = n2;
        }
        return head;
    }

    int max(ListNode* head) {
        int max = 0;
        ListNode* p = head;
        while (p) {
            max++;
            p = p->next;
        }
        return max;
    }
};


//codice con risposta veloce e corretta
/*class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* left_ptr = head, * right_ptr = head;
        for (int i = 0; i < k - 1; i++) {
            right_ptr = right_ptr->next;
        }

        ListNode* end_ptr = right_ptr;
        while (right_ptr->next) {
            left_ptr = left_ptr->next;
            right_ptr = right_ptr->next;
        }

        swap(end_ptr->val, left_ptr->val);

        return head;
    }
};*/
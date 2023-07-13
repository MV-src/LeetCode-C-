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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL) return head;
        ListNode* t1, * p, * ts;
        t1 = head;
        p = head->next;
        t1->next = p->next;
        p->next = t1;
        head = p;
        ListNode* temp = head->next;
        ts = t1;
        t1 = p;
        p = ts;
        if (p->next == NULL) return head;
        p = p->next->next;
        t1 = t1->next->next;
        while (p) {
            t1->next = p->next;
            p->next = t1;
            temp->next = p;
            ts = t1;
            t1 = p;
            p = ts;
            if (p->next == NULL) break;
            temp = temp->next->next;
            t1 = t1->next->next;
            p = p->next->next;
        }
        return head;
    }
};

/*
Easier version
ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head; //If there are less than 2 nodes in the given nodes, then no need to do anything just return the list as it is.

        ListNode* dummyNode = new ListNode();

        ListNode* prevNode=dummyNode;
        ListNode* currNode=head;

        while(currNode && currNode->next){
            prevNode->next = currNode->next;
            currNode->next = prevNode->next->next;
            prevNode->next->next = currNode;

            prevNode = currNode;
            currNode = currNode->next;
        }

        return dummyNode->next;
    }
*/
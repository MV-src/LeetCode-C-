#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
    
};

/*class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* p = head;
        vector<ListNode*> res;
        while (p) {
            p = p->next;
            size++;
        }

        int diff = size / k;
        int remainder = size % k;
        p = head;
        while (p) {
            ListNode* tempHead = new ListNode(p->val);
            ListNode* temp = tempHead;
            p = p->next;
            for (int i = 1; i < diff; i++) {
                if (p) {
                    ListNode* x = new ListNode(p->val);
                    temp->next = x;
                    temp = temp->next;
                    p = p->next;
                }
            }
            if (remainder != 0 && diff != 0) {
                ListNode* x = new ListNode(p->val);
                temp->next = x;
                temp = temp->next;
                remainder--;
                p = p->next;
            }
            res.push_back(tempHead);
            k--;
        }
        for (int i = 0; i < k; i++) res.push_back({});
        return res;
    }
};*/

class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int size = 0;
        ListNode* p = head;
        vector<ListNode*> res;
        while (p) {
            p = p->next;
            size++;
        }

        int diff = size / k;
        int remainder = size % k;
        p = head;
        while (p) {
            res.push_back(p);
            for (int i = 1; i < diff; i++) p = p->next;
            if (remainder != 0 && diff != 0) {
                p = p->next;
                remainder--;
            }
            ListNode* temp = p->next;
            p->next = NULL;
            p = temp;
        }
        for (int i = 0; i < k-size; i++) res.push_back({});
        return res;
    }
};
int main() {

	return 0;
}
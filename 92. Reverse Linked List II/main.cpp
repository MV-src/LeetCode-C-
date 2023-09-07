#include <iostream>
#include <vector>
#include <stack>
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* p = head;
        stack<int> st;
        ListNode* q = NULL;
        int i = 1;
        while (p) {
            if (i == left) {
                q = p;
            }
            if (i>=left && i<=right) st.push(p->val);
            if (i == right) {
                break;
            }
            p = p->next;
            i++;
        }
        while (!st.empty()) {
            q->val = st.top();
            st.pop();
            q = q->next;
        }
        return head;
    }
};

int main() {

	return 0;
}
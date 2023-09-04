#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
    
};

class Solution {
public:
    bool hasCycle(ListNode* head) {
        ListNode* p = head;
        ListNode* q = head;
        while (p && q) {
            p = p->next;
            q = q->next;
            if (!q) return false;
            q = q->next;
            if (p == q) return true;
        }
        return false;
    }
};


/*Best Solution
class Solution {
public:
    bool hasCycle(ListNode *head) {

        // making two pointers fast and slow and assignning them to head
        ListNode *fast = head;
        ListNode *slow = head;

        // till fast and fast-> next not reaches NULL
        // we will increment fast by 2 step and slow by 1 step
        while(fast != NULL && fast ->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;


            // At the point if fast and slow are at same address
            // this means linked list has a cycle in it.
            if(fast == slow)
                return true;
        }

        // if traversal reaches to NULL this means no cycle.
        return false;
    }
};
*/

int main() {

	return 0;
}
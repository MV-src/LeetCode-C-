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


class Solution{
public:

	ListNode* partition(ListNode* head, int x) {
		ListNode* p1, * p2, * p3, * p4;
		p2 = head;
		p1 = NULL;
		while (p2) {
			if (p2->val >= x) break;
			p1 = p2;
			p2 = p2->next;
		}
		p4 = p2;
		p3 = p1;

		while (p4) {
			if (p4->val < x) {
				p3->next = p4->next;
				p4->next = p2;
				if (p1 == NULL) {
					head = p4;
					p1 = p4;
				}
				else {
					p1->next = p4;
					p1 = p1->next;
				}
				p4 = p3->next;
			}
			else {
				p3 = p4;
				if (!p4)break;
				p4 = p4->next;
			}

		}

		return head;
	}
};

int main() {
	Solution s;
	ListNode* head = new ListNode(1,new ListNode(4, new ListNode(3, new ListNode(0,new ListNode(2,new ListNode(5, new ListNode(2)))))));
	
	s.partition(head,3);
	return 0;
}
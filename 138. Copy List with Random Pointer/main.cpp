#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return NULL;
        int size = 0;
        Node* p = head;
        while (p) {
            p = p->next;
            size++;
        }
        p = head;
        Node* copyHead = new Node(p->val);
        Node* copyP = copyHead;
        p = p->next;
        while(p) {
            Node* temp = new Node(p->val);
            copyP->next = temp;
            copyP = temp;
            p = p->next;
        }
        copyP = copyHead;
        p = head;
        while (copyP) {
            if (!p->random) {
                copyP = copyP->next;
                p = p->next;
                continue;
            }
            Node* fnd = p->random;
            int dist = 0;
            while (fnd) {
                fnd = fnd->next;
                dist++;
            }
            fnd = copyHead;
            for (int i = 0; i < size - dist; i++) fnd = fnd->next;
            copyP->random = fnd;
            copyP = copyP->next;
            p = p->next;
        }
        return copyHead;
    }
};


/*Best Solution
class Solution {
public:
    Node* copyRandomList(Node* head) {
        map<Node*, Node*> m;
        int i=0;
        Node* ptr = head;
        while (ptr) {
            m[ptr] =new Node(ptr->val);
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr) {
            m[ptr]->next = m[ptr->next];
            m[ptr]->random = m[ptr->random];
            ptr = ptr->next;
        }
        return m[head];
    }
};

*/

int main() {

	return 0;
}
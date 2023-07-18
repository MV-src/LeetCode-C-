#include <iostream>
#include <queue>
#include <unordered_map>
using namespace std;

/*bool cmp(pair<int, pair<int, int>>& a,
    pair<int, pair<int, int>>& b)
{
    return a.second.second < b.second.second;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ h2;
    }
};

class LRUCache {
    map<int, pair<int,int>,pair_hash> dp;
    int capacity;
    int count;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        count = 0;
    }

    int get(int key) {
        if (dp.find(key) != dp.end()) {
            dp[key].second++;
            return dp[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (dp.find(key) != dp.end()) {
            dp[key] = make_pair(value,dp[key].second++);
        }
        if (count == capacity) {
            sort(dp.begin(), dp.end(), cmp);
            dp.erase(dp.begin());
            count--;
        }
        dp.insert(make_pair(key, make_pair(value,0)));
        count++;
    }


};*/

class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* prev;
        Node* next;

        Node(int key, int val) {
            this->key = key;
            this->val = val;
        }
    };

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    int cap;
    unordered_map<int, Node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* newnode) {
        Node* temp = head->next;

        newnode->next = temp;
        newnode->prev = head;

        head->next = newnode;
        temp->prev = newnode;
    }

    void deleteNode(Node* delnode) {
        Node* prevv = delnode->prev;
        Node* nextt = delnode->next;

        prevv->next = nextt;
        nextt->prev = prevv;
    }

    int get(int key) {
        if (m.find(key) != m.end()) {
            Node* resNode = m[key];
            int ans = resNode->val;

            m.erase(key);
            deleteNode(resNode);
            addNode(resNode);

            m[key] = head->next;
            return ans;
        }
        return -1;
    }

    void put(int key, int value) {
        if (m.find(key) != m.end()) {
            Node* curr = m[key];
            m.erase(key);
            deleteNode(curr);
        }

        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deleteNode(tail->prev);
        }

        addNode(new Node(key, value));
        m[key] = head->next;
    }
};



int main() {
	return 0;
}
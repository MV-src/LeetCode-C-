#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <set>
using namespace std;


struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:


    void distanceBFS(TreeNode* p, stack<TreeNode*> stk, vector<int>& v,int k) {
        queue<pair<TreeNode*, int>> q;
        set<TreeNode*> s;
        q.push(make_pair(p, 0));
        s.insert(p);
        int j = 0;
        while (!stk.empty() && k > j) {
            j++;
            q.push(make_pair(stk.top(),j));
            s.insert(stk.top());
            stk.pop();
        }
        while (!q.empty()) {
            auto a = q.front();
            q.pop();
            if (a.first == NULL) continue;
            if (a.second == k) {
                v.push_back(a.first->val);
                continue;
            }
            s.insert(a.first);
            if (!a.first->left && !a.first->right) continue;
            if (a.first->left && s.find(a.first->left) == s.end()) {
                q.push(make_pair(a.first->left,a.second+1));
            }
            if (a.first->right && s.find(a.first->right) == s.end()) {
                q.push(make_pair(a.first->right, a.second + 1));
            }
        }
    }

    void searchDFS(TreeNode* p, int target, stack<TreeNode*>& stk) {
        static bool flag = 0;
        if (flag)return;
        if (target == p->val) {
            flag = 1;
            return;
        }
        stk.emplace(p);
        if (!p->left && !p->right) {
            stk.pop();
            return;
        }
        if (p->left) {
            searchDFS(p->left, target, stk);
        }
        if (flag)return;
        if (p->right) {
           searchDFS(p->right, target, stk);
        } 
        stk.pop();
    }

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> result;
        stack<TreeNode*> stk;
        searchDFS(root, target->val, stk);
        distanceBFS(target, stk, result,k);
        return result;
    }
};

int main() {
    TreeNode* root = new TreeNode(0);
    root->left = new TreeNode(1);
    root->right = new TreeNode(3);
    //root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    //root->right->left = new TreeNode(0);
    //root->right->right = new TreeNode(8);
    //root->left->right->left = new TreeNode(7);
    //root->left->right->right = new TreeNode(4);

    Solution s;
    s.distanceK(root, root->left, 2);


    
	return 0;
}
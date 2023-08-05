#include <iostream>
#include <vector>
#include <set>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution2 {
public:

    vector<TreeNode*>fun(TreeNode* x, int n, int j, set<int> vst) {
        TreeNode* temp = x;
        vector<TreeNode*> res;
        for (int i = 1; i < n + 1; i++) {
            if (vst.find(i) != vst.end()) continue;
            vector<TreeNode*> temp;
            for (auto x : temp) {
                TreeNode* p = new TreeNode;
                if (i > x->val) {
                    p->left = x;
                }
                else {
                    p->right = x;
                }
                res.push_back(p);
            }
            
        }

    }

    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> res;
        for (int i = 1; i < n + 1; i++) {
            set<int> vst;
            vst.insert(i);
            TreeNode* x = new TreeNode(i);
            fun(x, n, i, vst);
            res.push_back(x);
        }
        return res;
    }
};


class Solution {
public:
    vector<TreeNode*> allPossibleBST(int start, int end, map<pair<int, int>, vector<TreeNode*>>& memo) {
        vector<TreeNode*> res;
        if (start > end) {
            res.push_back(nullptr);
            return res;
        }
        if (memo.find(make_pair(start, end)) != memo.end()) {
            return memo[make_pair(start, end)];
        }
        // Iterate through all values from start to end to construct left and right subtrees recursively.
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> leftSubTrees = allPossibleBST(start, i - 1, memo);
            vector<TreeNode*> rightSubTrees = allPossibleBST(i + 1, end, memo);

            // Loop through all left and right subtrees and connect them to the ith root.
            for (auto left : leftSubTrees) {
                for (auto right : rightSubTrees) {
                    TreeNode* root = new TreeNode(i, left, right);
                    res.push_back(root);
                }
            }
        }
        return memo[make_pair(start, end)] = res;
    }

    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> memo;
        return allPossibleBST(1, n, memo);
    }
};

int main() {
    Solution s;
    vector<TreeNode*> res = s.generateTrees(2);
    return 0;
}
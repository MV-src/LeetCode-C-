#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int dfs(TreeNode* p) {
        if (p->left == NULL && p->right == NULL) return 0;
        int n1 = p->left == NULL ? INT32_MAX : dfs(p->left) + 1;
        int n2 = p->right == NULL ? INT32_MAX : dfs(p->right) + 1;
        int result = min(n1, n2);
        return result;
    }

    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int result = dfs(root) + 1;
        return result;
    }
};

int main() {

	return 0;
}
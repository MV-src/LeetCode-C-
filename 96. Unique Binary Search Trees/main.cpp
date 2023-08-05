#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int solve(int st, int end, unordered_map<string, int>& dp) {
        string key = to_string(st) + " " + to_string(end);
        if (st >= end) return 1;
        if (dp.find(key) != dp.end()) return dp[key];
        int ans = 0;
        for (int i = st; i <= end; i++) {
            ans += solve(st, i - 1,dp) * solve(i + 1, end,dp);
        }
        return dp[key] =ans;
    }
public:
    int numTrees(int n) {
        unordered_map<string, int> dp;
        return solve(1, n, dp);
    }
};
int main() {
    Solution s;
    cout<<s.numTrees(19);
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int fun(vector<vector<int>>& pairs, int i, int size, unordered_map<int, int>& dp) {
        if (dp.find(i) != dp.end()) return dp[i];
        int res = 0;
        for (int j = i + 1; j < size; j++) {
            if (pairs[i][1] < pairs[j][0]) res = max(res, fun(pairs, j, size, dp) + 1);
        }
        return dp[i] = res;
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        unordered_map<int, int> dp;
        int res = 0;

        for (int i = 0; i < pairs.size(); i++) {
            res = max(res, fun(pairs, i, pairs.size(), dp) + 1);
        }

        return res;
    }
};

class Solution2 {
public:
    int longestPairChain(int i, vector<vector<int>>& pairs, int& n, vector<int>& memo) {
        if (memo[i] != 0) {
            return memo[i];
        }
        memo[i] = 1;
        for (int j = i + 1; j < n; j++) {
            if (pairs[i][1] < pairs[j][0]) {
                memo[i] = max(memo[i], 1 + longestPairChain(j, pairs, n, memo));
            }
        }
        return memo[i];
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(), pairs.end());
        vector<int> memo(n);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, longestPairChain(i, pairs, n, memo));
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> v = { {3,4},{1,2},{2,3} };
    Solution s;
    cout<<s.findLongestChain(v);
	return 0;
}

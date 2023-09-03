#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:

    int fun(int i, int j, int m, int n, unordered_map<string,int>& dp) {
        if (i >= m || j >= n) return 0;
        if (i == m - 1 && j == n - 1) return 1;
        string key = to_string(i) + " " + to_string(j);
        if (dp.find(key) != dp.end()) return dp[key];
        int res = 0;
        res += fun(i + 1, j, m, n, dp) + fun(i,j+1,m,n,dp);
        return dp[key] = res;
    }

    int uniquePaths(int m, int n) {
        unordered_map<string, int> dp;
        return fun(0, 0, m, n, dp);
    }
};

/*
Best Solution

class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        return dp[m - 1][n - 1];
    }
};
*/

int main() {

	return 0;
}
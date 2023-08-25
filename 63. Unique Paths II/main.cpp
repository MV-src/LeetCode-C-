#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int fun(vector<vector<int>>& grid,int i, int j, int m, int n, unordered_map<string, int>& dp) {
        if (i >= m || j >= n || grid[i][j] == 1) return 0;
        if (i == m-1 && j == n-1) return 1;
        string key = to_string(i) + " " + to_string(j);
        if (dp.find(key) != dp.end()) return dp[key];
        int res = 0;
        res += fun(grid, i + 1, j, m, n, dp) + fun(grid, i, j + 1, m, n, dp);
        return dp[key] = res;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        unordered_map<string, int> dp;
        return fun(obstacleGrid, 0, 0, obstacleGrid.size(), obstacleGrid[0].size(), dp);
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = { {0,0,0},{0,1,0},{0,0,0} };
    cout<<s.uniquePathsWithObstacles(v);
	return 0;
}
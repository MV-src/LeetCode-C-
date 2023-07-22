#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    double fun(int n, int k, int row, int column, vector<pair<int, int>>& directions, unordered_map<string, double>& dp) {
        if (row >= n || row < 0 || column >= n || column < 0) return 0;
        if (k == 0) {
            return 1;
        }
        string key = to_string(row) + " " + to_string(column)+" " + to_string(k);
        if (dp.find(key) != dp.end()) return dp[key];
        double res = 0;
        for (int i = 0; i < 8; i++) {
            auto dir = directions[i];
            res += fun(n,k-1,row+dir.first,column+dir.second, directions,dp)/8.0;
        }
        dp[key] = res;
        return res;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<pair<int, int>> directions = {{ -1,2 }, { 1,2 }, { 2,1 }, { 2,-1 }, { 1,-2 }, { -1,-2 }, { -2,-1 }, { -2,1 }};
        unordered_map<string, double> dp;
        return fun(n,k,row,column,directions,dp);
    }
};

int main() {
    Solution s;
    cout<<s.knightProbability(8, 30, 6, 4);
    return 0;
}
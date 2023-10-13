#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int fun(vector<int>& cost, int i, unordered_map<int, int>& dp) {
        if (i >= cost.size()) return 0;
        if (dp.find(i) != dp.end()) return dp[i];
        int res = 0;
        res = cost[i] + min(fun(cost, i + 1, dp), fun(cost, i + 2, dp));
        return dp[i] = res;
    }

    int minCostClimbingStairs(vector<int>& cost) {
        unordered_map<int, int> dp;
        return min(fun(cost, 0, dp), fun(cost,1,dp));
    }
};

int main() {

	return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:

    int fun(vector<int>& num, int target, unordered_map<int,int>& dp) {
        if (target == 0) return 1;
        if (target < 0) return 0;
        if (dp.find(target) != dp.end()) return dp[target];
        int res = 0;
        for (auto& x : num) {
            res += fun(num, target - x,dp);
        }
        return dp[target] = res;
    }

    int combinationSum4(vector<int>& nums, int target) {
        unordered_map<int, int> dp;
        return fun(nums, target,dp);
    }
};


int main() {

    Solution s;
    vector<int> v = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
    s.combinationSum4(v, 100);
	return 0;
}
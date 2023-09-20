#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*class Solution {
public:

    int fun(vector<int>& nums, int x, int i, int j, unordered_map<string,int>& dp) {
        if (x == 0) return (nums.size() - 1 - j) + i;
        
        if (x < 0 || i > j) return INT32_MAX;
        string key = to_string(x) + " " + to_string(i) + " " + to_string(j);
        if (dp.find(key) != dp.end()) return dp[key];
        int res = min(fun(nums, x - nums[j], i, j - 1, dp), fun(nums, x - nums[i], i + 1, j, dp));
        return dp[key] = res;
    }

    int minOperations(vector<int>& nums, int x) {
        unordered_map<string,int> dp;
        int ans = fun(nums, x,0,nums.size()-1, dp);
        if (ans == INT32_MAX) return -1;
        return ans;
    }
};*/

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int totalSum = 0;
        for (int num : nums)
            totalSum += num;
        int maxLength = -1, currSum = 0;
        for (int l = 0, r = 0; r < nums.size(); r++) {
            currSum += nums[r];
            while (l <= r && currSum > totalSum - x)
                currSum -= nums[l++];
            if (currSum == totalSum - x)
                maxLength = max(maxLength, r - l + 1);
        }
        return maxLength == -1 ? -1 : nums.size() - maxLength;
    }
};

int main() {
    Solution s;
    vector<int> v = { 1,1,4,2,3 };
    cout<<s.minOperations(v, 5);
	return 0;
}
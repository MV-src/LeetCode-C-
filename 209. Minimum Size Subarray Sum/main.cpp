#include <iostream>
#include <vector>

using namespace std;

/*class Solution {
public:

    int fun(int& target, vector<int>& nums, int i, int size,int count,int pass,vector<int> &dp) {
        
        if (i >= size) return INT32_MAX;
        if (dp[i] == 1) return INT32_MAX;
        int result = INT32_MAX;
        if (count == target) return pass;
        if (count > target) return INT32_MAX;
        for (int j = i+1; j < size; j++) {
            
            int temp = min(fun(target, nums, j, size, nums[i], 1,dp), fun(target, nums, j, size, count + nums[i], pass + 1,dp));
            
            result = min(result, temp);
        }
        return result;
    }

    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size,0);
        int res = fun(target, nums, 0, size,0,0,dp);
        if (res == INT32_MAX) return 0;
        return res;
    }
};*/




/*
Best Solution

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sumOfCurrentWindow = 0;
        int res = INT_MAX;

        for(right = 0; right < nums.size(); right++) {
            sumOfCurrentWindow += nums[right];

            while (sumOfCurrentWindow >= target) {
                res = min(res, right - left + 1);
                sumOfCurrentWindow -= nums[left];
                left++;
            }
        }

        return res == INT_MAX ? 0 : res;
    }
};

*/

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int res = INT32_MAX;
        int i = 0;
        int j = 0;
        int count = 0;
        
        while (i <= j && j<size) {
            while (count < target && j<size) {
                count += nums[j];
                j++;
            }
            if (count >= target) res = min(j-i, res);
            while (count >= target) {
                count -= nums[i];
                i++;
                if (count >= target) res = min(j - i, res);
            }
        }
        if (res == INT32_MAX) return 0;
        return res;
    }

};

int main() {
    Solution s;
    vector<int> v = { 1,2,3,4,5 };
    cout<<s.minSubArrayLen(11, v);
	return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*class Solution {
public:
    vector<vector<int>> fun(vector<int> nums) {
        vector<vector<int>> res;
        if (nums.size() == 2) {
            res.push_back(nums);
            swap(nums[0], nums[1]);
            res.push_back(nums);
            return res;
        }
        vector<int> temp = nums;
        vector<vector<int>> t;
        for (int j = 0; j < nums.size(); j++) {
            swap(temp[0], temp[j]);
            int n = temp[0];
            temp.erase(temp.begin());
            t = fun(temp);
            for (auto& x : t) x.push_back(n);
            for (auto x : t) res.push_back(x);
            temp = nums;
        }
        return res;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        int size = nums.size();
        if (size == 1) return { nums };
        return fun(nums);
    }
};*/

/*Besto Solution*/
class Solution {
public:
    vector<vector<int>> arr;
    void backtrack(vector<int>& nums, int n, int index) {
        if (index == n - 1) {
            arr.push_back(nums);
            return;
        }
        for (int i = index; i < n; i++) {
            swap(nums[index], nums[i]);
            backtrack(nums, n, index + 1);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        backtrack(nums, n, 0);
        return arr;
    }
};

int main() {
    vector<int> nums = { 1,2,3 };
    Solution s;
    vector<vector<int>> r = s.permute(nums);
    for (auto x : r) {
        for (auto y : x) {
            cout << y<<" ";
        }
        cout << endl;
    }
	return 0;
}
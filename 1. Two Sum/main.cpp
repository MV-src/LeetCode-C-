#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int size = nums.size();
        int i = 0;
        vector<int> result;
        unordered_map<int, bool> hashmap;
        for (auto n : nums) {
            hashmap[n] = true;
        }

        int n1 = 0;
        int n2 = 0;
        int minimum = INT64_MIN;

        
        for (i = 0; i < size; i++) {
            if (nums[i] < minimum) {
                minimum = nums[i];
            }
        }


        for (i = minimum; i < target; i++) {
            if (hashmap[target-i] != target && hashmap[target-i] == true && hashmap[i] == true) {
                break;
            }
        }
        
        for (int j = 0; j < size; j++) {
            if (target - i == nums[j] || i == nums[j]) {
                result.emplace_back(j);
            }
        }
        return result;
    }
};


int main() {

	return 0;
}

/*
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> mp;

        for(int i = 0; i < nums.size(); i++){
            if(mp.find(target - nums[i]) == mp.end())
                mp[nums[i]] = i;
            else
                return {mp[target - nums[i]], i};
        }

        return {-1, -1};
    }
};
*/
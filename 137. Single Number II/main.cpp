#include <iostream>
#include <unordered_map>
using namespace std;

class Solution2 {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> hm;
        int result = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (hm.find(nums[i]) == hm.end()) {
                hm.insert(make_pair(nums[i],true));
                result += nums[i] * 2;
            }
            else {
                result -= nums[i];
            }
        }
        return result/2;
    }
};

/*
Bit manipulation
*/class Solution {
 public:
  int singleNumber(vector<int>& nums) {
    int ans = 0;

    for (int i = 0; i < 32; ++i) {
      int sum = 0;
      for (const int num : nums)
        sum += num >> i & 1;
      sum %= 3;
      ans |= sum << i;
    }

    return ans;
  }
};


class Solution3 {
public:
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;

        for (const int num : nums) {
            ones ^= (num & ~twos);
            twos ^= (num & ~ones);
        }

        return ones;
    }
};

/**/


int main() {

    Solution s;
    vector<int> nums = { 1,4,1,1 };
    cout<<s.singleNumber(nums);
    return 0;
}
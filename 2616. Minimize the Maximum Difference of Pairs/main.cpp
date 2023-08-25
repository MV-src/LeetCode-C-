#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int searchBS(vector<int>nums, int mid) {
        int index, count;
        index = count = 0;
        while (index < nums.size() - 1) {
            if (nums[index + 1] - nums[index] <= mid) {
                count++;
                index++;
            }
            index++;
        }
        return count;
    }

    int minimizeMax(vector<int>& nums, int p) {
        int size = nums.size();
        sort(nums.begin(), nums.end());
        int high = nums[nums.size() - 1]-nums[0];
        int low = 0;
        while (low < high) {
            int mid = (low + high) / 2;
            if (searchBS(nums, mid) >= p) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

int main() {
    Solution s;
    vector<int> nums = { 10,1,2,7,1,3 };
    cout<<s.minimizeMax(nums, 2);
    return 0;
}
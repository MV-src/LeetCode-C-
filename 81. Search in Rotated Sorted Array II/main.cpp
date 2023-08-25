#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int low = 0;
        int high = nums.size() - 1;
        bool res = false;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (nums[mid] == target || nums[low] == target || nums[high] == target) {
                res = true;
                break;
            }
            if ((nums[low] == nums[mid]) && (nums[high] == nums[mid]))
            {
                low++;
                high--;
            }
            else if (nums[mid] < nums[low] && nums[mid] < nums[high]) {
                if (nums[mid] < target && nums[high] >= target) {
                    low = mid + 1;
                }
                else {
                    high = mid - 1;
                }
            }
            else if (nums[low] <= nums[mid] && nums[mid] > nums[high]) {
                if (nums[mid] > target && nums[low] <= target) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
            else {
                if (nums[mid] > target) {
                    high = mid - 1;
                }
                else {
                    low = mid + 1;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> nums = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 13, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
    cout << s.search(nums, 13);
	return 0;
}
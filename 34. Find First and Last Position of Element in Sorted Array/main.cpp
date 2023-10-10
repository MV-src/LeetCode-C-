#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int bSearch(vector<int>& nums, int target) {
        int high = nums.size()-1;
        int low = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid-1;
            }
        }
        return -1;
    }

    int startSearch(vector<int>& nums, int val, int target) {
        int high = val;
        int low = 0;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid == 0 && nums[mid] == target) return mid;
            if (mid-1 >= 0 && nums[mid] == target && nums[mid-1] != nums[mid]) return mid;
            if (nums[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid-1;
            }
        }
        return -1;
    }

    int endSearch(vector<int>& nums, int val, int target) {
        int high = nums.size()-1;
        int low = val;
        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid == nums.size()-1 && nums[mid] == target) return mid;
            if (mid + 1 < nums.size() && nums[mid] == target && nums[mid + 1] != nums[mid]) return mid;
            if (nums[mid] <= target) {
                low = mid+1;
            }
            else {
                high = mid - 1;
            }
        }
        return -1;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int pos = bSearch(nums, target);
        if (pos == -1) return { -1,-1 };
        int start = 0;
        int end = 0;
        start = startSearch(nums, pos, target);
        end = endSearch(nums, pos, target);
        return { start, end };
    }
};

int main() {
    Solution s;
    vector<int> v = { 1,1,1 };
    s.searchRange(v,1);
	return 0;
}
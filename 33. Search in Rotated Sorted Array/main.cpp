#include <iostream>
#include <vector>
using namespace std;

/*class Solution {
public:
    
    int indexBST(vector<int> nums) {
        int low = 0;
        int high = nums.size() - 1;
        if (nums[low] <= nums[high]) {
            return nums[low];
        }

        while (low <= high) {
            int mid = (low + high) / 2;
            if (mid - 1 >= 0 && nums[mid] < nums[mid - 1]) {
                return mid;
            }
            if (nums[mid] > nums[high]) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {
        int size = nums.size() - 1;
        if (size <= 0) {
            if (target == nums[0]) return 0;
            return -1;
        }
        int startIndex = indexBST(nums);
        int res = 0;
        int low = 0, high = nums.size();
        int mid = 0;
        vector<int> resVec;
        for (int i = startIndex; i != startIndex-1; i++) {
            if (i > size) i = 0;
            resVec.push_back(nums[i]);
        }
        resVec.push_back(nums[startIndex-1]);
        while (low < high) {
            mid = (low + high) / 2;
            if (resVec[mid] == target) {
                mid += startIndex;
                if (mid > size) mid -= size + 1;
                return mid;
            }
            if (resVec[mid] < target) {
                low = mid + 1;
            }
            else {
                high = mid;
            }
        }
        
        return -1;
    }
};*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start = 0;
        int end = nums.size() - 1;
        int ans = -1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) {
                ans = mid;
                break;
            }
            else if (nums[start] > nums[mid] && nums[mid] < nums[end]) {
                // left half is not sorted but right half is sorted
                // check for element in the right half else move to the right half
                if (nums[mid] < target && nums[end] >= target) {
                    // move to the right side
                    start = mid + 1;
                }
                else {
                    // move to the left side
                    end = mid - 1;
                }
            }
            else if (nums[start] <= nums[mid] && nums[mid] > nums[end]) {
                // left half is sorted but right half is not sorted
                // check for element in left half else move to the right half
                if (nums[mid] > target && nums[start] <= target) {
                    // move to the left side
                    end = mid - 1;
                }
                else {
                    // move to the right side
                    start = mid + 1;
                }
            }
            else {
                // do a normal binary search
                if (nums[mid] > target) {
                    end = mid - 1;
                }
                else {
                    start = mid + 1;
                }
            }
        }

        return ans;
    }
};

int main() {
    Solution s;
    vector<int> nums = { 1,2 };
    cout<<s.search(nums, 2);
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int result = 0;
        int size = nums.size();
        for (int i = 0; i < size; i++) {
            result += nums[i];
        }
        if (result == size) return size - 1;
        result = 0;
        int j1, j2;
        int count = 0;
        for (int i = 0; i < size; i++) {
            if (nums[i] == 0) {
                if (i - 1 >= 0 && nums[i - 1] == 1) {
                    j1 = i - 1;
                    while (j1 >= 0 && nums[j1] == 1) {
                        count++;
                        j1--;
                    }
                }
                if (i + 1 < size && nums[i + 1] == 1) {
                    j2 = i + 1;
                    while (j2 < size && nums[j2] == 1) {
                        count++;
                        j2++;
                    }
                    i = j2 - 1;
                }
                result = max(result, count);
                count = 0;
            }
        }
        return result;
    }
};

/*
Best Solution

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(); // The size of the input array

        int left = 0; // The left pointer of the sliding window
        int zeros = 0; // Number of zeroes encountered
        int ans = 0; // Maximum length of the subarray

        for (int right = 0; right < n; right++) {
            if (nums[right] == 0) {
                zeros++; // Increment the count of zeroes
            }

            // Adjust the window to maintain at most one zero in the subarray
            while (zeros > 1) {
                if (nums[left] == 0) {
                    zeros--; // Decrement the count of zeroes
                }
                left++; // Move the left pointer to the right
            }

            // Calculate the length of the current subarray and update the maximum length
            ans = max(ans, right - left + 1 - zeros);
        }

        // If the entire array is the subarray, return the size minus one; otherwise, return the maximum length
        return (ans == n) ? ans - 1 : ans;
    }
};
*/


int main() {
    Solution s;
    vector<int> v = { 1,1,0,1 };
    cout<<s.longestSubarray(v);
	return 0;
}
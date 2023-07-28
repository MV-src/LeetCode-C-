#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    int fun(vector<int>& nums, int size,int left, int right, int k) {
        if (left == right) {
            return nums[left];
        }
        int res = 0;

        res = max(nums[left]-fun(nums, size, left + 1, right,0), nums[right]-fun(nums, size, left, right - 1,1));
        return res;
    }

    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        int x = fun(nums, size, 0, size - 1, 0);
        if ( x>= 0) return true;
        else return false;
    }
};

int main() {

    Solution s;
    vector<int> v = { 1,5,2 };
    cout << s.PredictTheWinner(v);
	return 0;
}
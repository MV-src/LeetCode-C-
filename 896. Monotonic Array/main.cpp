#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int i = 1;
        while (i < nums.size()-1 && nums[i - 1] == nums[i] ) i++;
        
        if (i < nums.size() && nums[i-1] > nums[i]) {
            for (; i < nums.size(); i++) {
                if (nums[i-1] < nums[i]) return false;
            }
        }
        if(i < nums.size() && nums[i-1]<nums[i]){
            for (; i < nums.size(); i++) {
                if (nums[i-1] > nums[i]) return false;
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    vector<int> v = { 2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,1,3 };
    cout<<s.isMonotonic(v);
	return 0;
}
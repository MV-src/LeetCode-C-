#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = 0;
        int fast = 0;
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];

        } while (slow != fast);
        
        slow = 0;
        
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

class Solution2 {
public:
    int findDuplicate(vector<int> nums) {
        int duplicate = 0;
        for (int bit = 0; bit < 31; bit++) {
            int expected = 0, actual = 0;
            for (int n = 1; n < nums.size(); n++)
            {
                expected += (n >> bit) & 1;
            }
            for (int n : nums) {
                actual += (n >> bit) & 1;
            }
            if (actual > expected) duplicate |= (1 << bit);
        }
        return duplicate;
    }
};

int main() {
    Solution2 s;
    vector<int> v = { 5,3,1,2,3,4 };
    cout<<s.findDuplicate(v);
	return 0;
}
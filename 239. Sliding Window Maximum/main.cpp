#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < nums.size(); i++) {
            dq.push_back(nums[i]);
            if (dq.size() > k) {
                dq.pop_front();
            }
            if (dq.front() > dq.back()) {
                while (dq.size() != 1) {
                    int x = dq.front();
                    dq.pop_front();
                    if (x > dq.front()) {
                        dq.push_front(x);
                        break;
                    }
                }
            }
            else {
                while (dq.front() < dq.back()) {
                    dq.pop_front();
                }
            }
            
            
            if (i>=k-1) res.push_back(dq.front());
        }
        return res;
    }
};*/

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> dq;
        vector<int> res;
        for (int i = 0; i < k; i++) {
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        res.push_back(nums[dq.front()]);

        for (int i = k; i < nums.size(); i++) {
            if (dq.front() == i - k) {
                dq.pop_front();
            }
            while (!dq.empty() && nums[i] >= nums[dq.back()]) {
                dq.pop_back();
            }

            dq.push_back(i);
            res.push_back(nums[dq.front()]);
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<int> v = { 1,3,1,2,0,5};
    s.maxSlidingWindow(v, 3);
	return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        deque<int> dq;
        vector<int> res;
        for (auto& x : nums) (x % 2) == 0 ? dq.push_front(x) : dq.push_back(x);

        while (!dq.empty()) {
            res.push_back(dq.front());
            dq.pop_front();
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> v = { 3,1,2,4 };
    s.sortArrayByParity(v);
    return 0;

}
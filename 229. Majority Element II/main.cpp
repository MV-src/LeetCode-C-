#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int, int> um;
        int t = nums.size() / 3;
        vector<int> res;
        for (auto& x : nums) um[x]++;
        for (auto& x : um) {
            if (x.second > t) {
                res.push_back(x.first);
            }
        }
        return res;
    }
};

int main() {

	return 0;
}
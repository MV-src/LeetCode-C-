#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        vector<int> res = nums;
        for (auto x : nums) res.push_back(x);
        return res;
    }
};

int main() {
	return 0;
}
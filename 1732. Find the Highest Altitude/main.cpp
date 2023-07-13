#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int result = 0;
        int temp = 0;
        for (auto n : gain) {
            temp += n;
            result = temp > result ? temp : result;
        }
        return result;
    }
};

int main() {
    Solution s;
    vector<int> v = { 44,32,-9,52,23,-50,50,33,-84,47,-14,84,36,-62,37,81,-36,-85,-39,67,-63,64,-47,95,91,-40,65,67,92,-28,97,100,81 };
    s.largestAltitude(v);
	return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		vector<vector<int>> res;
		int j = 0;
		unordered_map<int, vector<int>> dp;
		int maximum = -1;
		for (int i = 0; i<groupSizes.size(); i++) {
			dp[groupSizes[i]].push_back(i);
			maximum = max(groupSizes[i], maximum);
		}

		int k = 0;
		for (int i = 1; i <= maximum; i++) {
			if (dp.find(i) == dp.end()) continue;
			int count = 0;
			auto& x = dp[i];
			res.push_back({});
			for (int j = 0; j < x.size(); j++) {
				if (count == i) {
					res.push_back({});
					count = 0;
					k++;
				}
				res[k].push_back(x[j]);
				count++;
			}
			k++;
		}
		return res;
	}
};

int main() {
	Solution s;
	vector<int> v = { 2,1,3,3,3,2 };
	s.groupThePeople(v);
	return 0;
}
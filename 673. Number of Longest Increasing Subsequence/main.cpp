#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<vector<pair<int,int>>> dp(nums.size());
        dp[0].push_back(make_pair(nums[0], 1));
        int ans = 1;
        bool check = 0;
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = dp[i - 1];
            check = 0;
            sort(dp[i-1].begin(), dp[i-1].end());
            for (int j = 0; j<dp[i-1].size();j++) {
                if (dp[i-1][j].first < nums[i]) {
                    dp[i].push_back(make_pair(nums[i], dp[i - 1][j].second + 1));
                    check = 1;
                }
            }
            if (!check) dp[i].push_back(make_pair(nums[i], 1));
        }
        sort(dp[nums.size() - 1].begin(), dp[nums.size() - 1].end(), [](pair<int, int> x, pair<int, int> y) {
            return x.second > y.second;
        });

        int num = dp[nums.size() - 1][0].second;
        int i = 1;
        while (i < dp[nums.size() - 1].size() && num == dp[nums.size() - 1][i].second) {
            ans++;
            i++;
        }
        return ans;
    }
};*/


class Solution {
public:
    int findNumberOfLIS(std::vector<int>& nums) {
        int n = nums.size();
        vector<int> length(n, 1);
        vector<int> count(n, 1);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    if (length[j] + 1 > length[i]) {
                        length[i] = length[j] + 1;
                        count[i] = 0;
                    }
                    if (length[j] + 1 == length[i]) {
                        count[i] += count[j];
                    }
                }
            }
        }

        int maxLength = *max_element(length.begin(), length.end());
        int result = 0;

        for (int i = 0; i < n; i++) {
            if (length[i] == maxLength) {
                result += count[i];
            }
        }

        return result;
    }
};

int main() {
    vector<int> v = { 1,3,5,4,7 };
    Solution s;
    cout <<s.findNumberOfLIS(v);

	return 0;
}
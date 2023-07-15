#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    int binarySearch(int i, vector<vector<int>>& events, int value) {
        int low = i;
        int high = events.size() - 1;
        int result = -1;
        while (high >= low) {
            int mid = (high + low) / 2;
            if (events[mid][0] > value) {
                result = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return result;
    }

    int dfs(int i, vector<vector<int>>& events, int k, vector<vector<int>>& dp, int size) {
        if (i >= size) return 0;
        if (k == 0) return 0;
        if (i == -1) return 0;
        if (dp[i][k] != -1) return dp[i][k];
        int nextIndex = binarySearch(i + 1, events, events[i][1]);
        int res = max(dfs(i + 1, events, k, dp, size), events[i][2] + dfs(nextIndex, events, k - 1, dp, size));
        return dp[i][k] = res;
    }

    int maxValue(vector<vector<int>>& events, int k) {
        int size = events.size();
        sort(events.begin(), events.end());
        vector<vector<int>> dp(size + 5, vector<int>(k + 1, -1));
        return dfs(0, events, k, dp, size);
    }
};

int main() {
    vector<vector<int>> v = { { 1,2,4 }, { 3,4,3 }, { 2,3,1 } };
    Solution s;
    s.maxValue(v, 2);
	return 0;
}
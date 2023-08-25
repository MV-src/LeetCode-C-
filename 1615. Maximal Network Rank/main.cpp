#include <iostream>
#include <vector>
#include <set>
using namespace std;

/*class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> dp(n,0);
        unordered_map<int, vector<int>> relations;
        for (auto x : roads) {
             dp[x[0]]++;
             dp[x[1]]++;
             relations[x[0]].push_back(x[1]);
             relations[x[1]].push_back(x[0]);
        }
        int n1 = *max_element(dp.begin(), dp.end());
        
        vector<pair<int, int>> connections;
        for (int i = 0; i < n; i++) {
            if (dp[i] >= n1 - 1) connections.push_back({ i,dp[i] });
        }
        int res = 0;
        for (int i = 0; i<connections.size();i++) {
            for (int j = i + 1; j < connections.size(); j++) {
                int sum = connections[i].second + connections[j].second;
                if (find(relations[connections[i].first].begin(), relations[connections[i].first].end(), connections[j].first) != relations[connections[i].first].end()) {
                    sum--;
                }
                res = max(res, sum);
            }
        }
        return res;
    }
};*/

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> degree(n, 0);
        set<pair<int, int>> road_set;

        for (auto& road : roads) {
            degree[road[0]]++;
            degree[road[1]]++;
            road_set.insert({ road[0], road[1] });
            road_set.insert({ road[1], road[0] });
        }

        int max_rank = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int rank = degree[i] + degree[j];
                if (road_set.find({ i, j }) != road_set.end()) {
                    rank--;
                }
                max_rank = max(max_rank, rank);
            }
        }

        return max_rank;
    }
};

int main() {
    Solution s;
    vector<vector<int>> vec = { {0, 1},{0, 3},{1, 2},{1, 3},{2, 3},{2, 4} };
    s.maximalNetworkRank(5,vec);
	return 0;
}
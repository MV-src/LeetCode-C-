#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:

    int searchSafety(vector<vector<int>>& graph, vector<int> currentNode, int nodeNum, vector<vector<int>>& dp, set<int> visited) {
        visited.insert(nodeNum);
        int size = currentNode.size();
        for (int i = 0; i < size; i++) {
            if (visited.find(currentNode[i]) != visited.end()) return 0;
            for (int j = 0; j < size; j++) {
                if (dp[nodeNum][j] == 1) {
                    continue;
                }
                else if (dp[nodeNum][j] == 0) {
                    return 0;
                }
                else {
                    dp[nodeNum][i] = searchSafety(graph, graph[currentNode[i]], currentNode[i], dp, visited);
                }
            }
            
        }
        int count = 0;
        for (auto n : dp[nodeNum]) {
            count += n;
        }
        if (size == count) {
            return 1;
        }
        return 0;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> res;
        vector<vector<int>> dp = graph;
        set<int> visited;
        int size = graph.size();
        for (int i = 0; i < size; i++) {
            int sizeJ = dp[i].size();
            for (int j = 0; j < sizeJ; j++) {
                dp[i][j] = -1;
            }

        }

        for (int i = 0; i < size; i++) {
            if (searchSafety(graph,graph[i],i,dp,visited)) {
                res.push_back(i);
            }
        }

        return res;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = { {1,2},{2,3},{5},{0},{5},{},{} };
    vector<int> r = s.eventualSafeNodes(v);
    r;
	return 0;
}
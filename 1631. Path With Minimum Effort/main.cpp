#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

/*class Solution {
public:

    int minimumEffortPath(vector<vector<int>>& heights) {
        vector<pair<int, int>> directions = { {1,0},{0,1},{-1,0},{0,-1} };
        queue<pair<vector<int>,set<pair<int,int>>>> q;
        set<pair<int, int>> s;
        s.insert({ 0,0 });
        q.push({ {0,0,0},s });
        int res = INT32_MAX;
        while (!q.empty()) {
            auto x = q.front();
            q.pop();
            if (x.first[0] == heights.size() - 1 && x.first[1] == heights.size() - 1) {
                res = min(x.first[2], res);
                continue;
            }
            for (int i = 0; i < directions.size(); i++) {
                set<pair<int, int>> temp = x.second;
                int newI = x.first[0] + directions[i].first;
                int newJ = x.first[1] + directions[i].second;
                
                if (temp.find({ newI,newJ }) != temp.end()) continue;
                if (newI < 0 || newI >= heights.size() || newJ < 0 || newJ >= heights.size()) continue;
                int tempRes = max(x.first[2], abs(heights[newI][newJ] - heights[x.first[0]][x.first[1]]));
                temp.insert({ newI,newJ });
                q.push({{newI,newJ,tempRes}, temp});
            }
        }
        return res;
    }
};*/


class Solution {
private:
    int effort[105][105];    // Store effort for each cell
    int dx[4] = { 0, 1, -1, 0 };  // Changes in x coordinate for each direction
    int dy[4] = { 1, 0, 0, -1 };  // Changes in y coordinate for each direction

public:
    // Dijkstra's Algorithm to find minimum effort
    int dijkstra(vector<vector<int>>& heights) {
        int rows = heights.size();
        int cols = heights[0].size();

        // Priority queue to store {effort, {x, y}}
        std::priority_queue<std::pair<int, std::pair<int, int>>> pq;
        pq.push({ 0, {0, 0} });  // Start from the top-left cell
        effort[0][0] = 0;  // Initial effort at the starting cell

        while (!pq.empty()) {
            auto current = pq.top().second;
            int cost = -pq.top().first;  // Effort for the current cell
            pq.pop();

            int x = current.first;
            int y = current.second;

            // Skip if we've already found a better effort for this cell
            if (cost > effort[x][y])
                continue;

            // Stop if we've reached the bottom-right cell
            if (x == rows - 1 && y == cols - 1)
                return cost;

            // Explore each direction (up, down, left, right)
            for (int i = 0; i < 4; i++) {
                int new_x = x + dx[i];
                int new_y = y + dy[i];

                // Check if the new coordinates are within bounds
                if (new_x < 0 || new_x >= rows || new_y < 0 || new_y >= cols)
                    continue;

                // Calculate new effort for the neighboring cell
                int new_effort = std::max(effort[x][y], std::abs(heights[x][y] - heights[new_x][new_y]));

                // Update effort if a lower effort is found for the neighboring cell
                if (new_effort < effort[new_x][new_y]) {
                    effort[new_x][new_y] = new_effort;
                    pq.push({ -new_effort, {new_x, new_y} });
                }
            }
        }
        return effort[rows - 1][cols - 1]; // Minimum effort for the path to the bottom-right cell
    }

    // Function to find the minimum effort path
    int minimumEffortPath(vector<vector<int>>& heights) {
        // Initialize effort for each cell to maximum value
        for (int i = 0; i < heights.size(); i++) {
            for (int j = 0; j < heights[i].size(); j++) {
                effort[i][j] = INT_MAX;
            }
        }
        return dijkstra(heights);  // Find minimum effort using dijkstra
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = { {1,2,2},{3,8,2},{5,3,5} };
    cout<<s.minimumEffortPath(v);
	return 0;
}
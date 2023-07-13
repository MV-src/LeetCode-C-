#include <iostream>
#include <vector>
#include <queue>
#include <cctype>
using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int nKeys = 0;
        int m = grid.size();
        int n = grid[0].size();
        int result = INT32_MAX;
        priority_queue<pair<int,pair<string,pair<int, int>>>> starts;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (isalpha(grid[i][j]) && islower(grid[i][j])) {
                    nKeys++;
                }
                else if(grid[i][j] == '@') {
                    starts.push(make_pair(0, make_pair("", make_pair(i, j))));
                }
            }
        }
        vector<vector<int>> cDirections = { {1,0},{0,-1},{0,1},{-1,0}};
        
        while (!starts.empty()) {
            auto start = starts.top();
            if (start.second.first.size() == nKeys) {
                result = min(start.first,result);
            }
            starts.pop();
            queue<vector<int>> queue;
            vector<string> tempgrid = grid;
            queue.push({start.second.second.first,start.second.second.second,0});
            tempgrid[start.second.second.first][start.second.second.second] = '#';
            while (!queue.empty()) {
                auto curr = queue.front();
                queue.pop();
                int r = curr[0];
                int c = curr[1];
                int result = curr[2];
                for (int i = 0; i < 4; i++) {
                    int row = r + cDirections[i][0];
                    int col = c + cDirections[i][1];
                    if (row >= 0 and row < m and col >= 0 and col < n) {
                        if (tempgrid[row][col] == '.' || tempgrid[row][col] == '@') {
                            tempgrid[row][col] = '#';
                            queue.push({ row,col,result + 1 });
                        }
                        else if (islower(tempgrid[row][col]) and start.second.first.find(tempgrid[row][col]) == string::npos) {
                            starts.push(make_pair(start.first+result + 1, make_pair(start.second.first + tempgrid[row][col], make_pair(row, col))));
                            queue.push({ row,col,result + 1 });
                            tempgrid[row][col] = '#';
                        }
                        else if (isupper(tempgrid[row][col])) {
                            if (start.second.first.find(tolower(tempgrid[row][col])) != string::npos) {
                                tempgrid[row][col] = '#';
                                queue.push({ row,col,result + 1 });
                            }
                        }
                    }
                }
            }
        }
        if (result == INT32_MAX) return -1;
        return result;
    }
};




int main() {
    Solution s;
    vector<string> grid = { "@..aA","..B#.","....b" };
    cout<<s.shortestPathAllKeys(grid);
	return 0;
}
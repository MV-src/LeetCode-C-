#include <iostream>
#include <queue>
#include <vector>
#include <set>
using namespace std;

/*
void DFS(int G[][7], int start, int n) {
	static int visited[7] = { 0 };
	if (visited[start] == 0) {
		std::cout << start;
		visited[start] = 1;
		for (int j = 1; j < n; j++) {
			if (G[start][j] == 1 && visited[j] == 0) {
				DFS(G, j, n);
			}
		}
	}
}
*/
/*void BFS(int G[][7], int start, int n) {
	int i = start;
	int visited[7] = { 0 };

	std::cout << i;
	visited[i] = 1;
	enqueue(i);
	while (!isEmpty()) {
		i = dequeue();
		for (int j = 1; j < n; j++) {
			if (G[i][j] == 1 && visited[j] == 0) {
				std::cout << j;
				visited[j] = 1;
				enqueue(j);
			}
		}
	}
}*/



class Solution {
public:

	bool BFS(vector<vector<int>>& cells, int row, int col, int day) {
		vector<vector<int>> directions = { {-1,0},{0,1},{1,0},{0,-1} };
		queue<pair<int,int>> pq;
		vector<vector<int>> grid(row, vector<int>(col, 0));
		
		for (int i = 0; i < day; i++) {
			grid[cells[i][0] - 1][cells[i][1] - 1] = 1;
		}

		for (int i = 0; i < col; i++) {
			if (grid[0][i] == 0) {
				pq.push(make_pair(0, i));
				grid[0][i] = -1;
			}
		}
		bool result = false;
		while (!pq.empty()) {
			auto& a = pq.front();
			pq.pop();
			int r = a.first;
			int c = a.second;
			if (r == row - 1) return true;
			for (int i = 0; i < directions.size();i++) {
				int tempRow = r + directions[i][0];
				int tempCol = c + directions[i][1];
				if (tempRow >= 0 && tempRow < row && tempCol >= 0 && tempCol < col && grid[tempRow][tempCol] == 0) {
					grid[tempRow][tempCol] = -1;
					pq.push(make_pair(tempRow, tempCol));
				}
			}
		}
		return false;
	}



	int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
		int result = 0;
		bool check = false;
		vector<vector<int>> grid(row,vector<int>(col,0));
		int l = 1;
		int r = row*col;
		
		while(l<r) {
			int mid = l+(r - l) / 2;
			if (BFS(cells, row, col, mid)) {
				l = mid;
				result = mid;
			}
			else {
				r = mid;
			}
		}
		return result;
	}
};

int main() {
	Solution s;
	vector<vector<int>> cells = { {1,1} ,{1,2},{2,1},{2,2} };
	cout<<s.latestDayToCross(2, 2, cells);
	return 0;
}
/*
Best Solution

class Solution {
public:
	bool isPossible(int m, int n, int t, vector<vector<int>>& cells) {
		vector<vector<int>> grid(m + 1, vector<int>(n + 1, 0));
		vector<pair<int, int>> directions {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

		for (int i = 0; i < t; i++) {
			grid[cells[i][0]][cells[i][1]] = 1;
		}

		priority_queue<pair<int, int>> q;

		for (int i = 1; i <= n; i++) {
			if (grid[1][i] == 0) {
				q.push({1, i});
				grid[1][i] = 1;
			}
		}
		while (!q.empty()) {
			pair<int, int> p = q.top();
			q.pop();
			int r = p.first, c = p.second;
			for (auto d : directions) {
				int nr = r + d.first, nc = c + d.second;
				if (nr > 0 && nc > 0 && nr <= m && nc <= n && grid[nr][nc] == 0) {
					grid[nr][nc] = 1;
					if (nr == m) {
						return true;
					}
					q.push({nr, nc});
				}
			}
		}
		return false;
	}

	int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
		int left = 0, right = row * col, latestPossibleDay = 0;
		while (left < right - 1) {
			int mid = left + (right - left) / 2;
			if (isPossible(row, col, mid, cells)) {
				left = mid;
				latestPossibleDay = mid;
			} else {
				right = mid;
			}
		}
		return latestPossibleDay;
	}
};
*/
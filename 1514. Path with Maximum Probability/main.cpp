#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <set>
using namespace std;

/*
void BFS(int G[][7], int start, int n) {
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
}

*/

class Solution2 {
public:
	double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {

		// Adjacency list
		vector<vector<pair<int, double>>> adj(n);
		for (int i = 0; i < edges.size(); i++) {
			int u = edges[i][0];
			int v = edges[i][1];
			adj[u].push_back({ v, succProb[i] });
			adj[v].push_back({ u, succProb[i] });
		}

		// ans will be in dist[end]
		vector<double> dist(n, 0.0);
		dist[start] = 1.0;

		queue<int> q;
		q.push(start);

		while (!q.empty()) {
			int curr = q.front();
			q.pop();

			for (auto x : adj[curr]) {
				int node = x.first;
				double prob = x.second;
				double newProb = dist[curr] * prob;

				if (newProb > dist[node]) {
					dist[node] = newProb;
					q.push(node);
				}
			}
		}

		return dist[end];
	}
};


class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
		queue<int> q;
		q.push(end);
		unordered_map<int,int> res;
		res.emplace(end, 1);
		double result = 0;
		while (!q.empty()) {
			int i;
			i = q.front();
			q.pop();
			int result = 0;
			for (int j = 0; j < edges.size(); j++) {
				set<int> visit;
				int n1;
				n1 = edges[j][0] == i?edges[j][1] : -1;
				n1= edges[j][1] == i? edges[j][0] : -1;
				if (n1 != -1 && visit.find(n1) == visit.end()) {
					visit.insert(n1);
					res.emplace(n1, (double)succProb[j] * res[i]);
					q.push(j);
				}
				else {

				}
			}
		}
		return result;
    }
};

int main() {
	Solution2 s;
	vector<vector<int>> edges = { {0,1} ,{1,2},{0,2} };
	vector<double> succProb = { 0.5,0.5,0.2 };
	cout<<s.maxProbability(3, edges, succProb, 0, 2);
	return 0;
}
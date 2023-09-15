#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    class UnionFind {
    public:
        vector<int> parent;
        vector<int> size;
        int maxSize;

        UnionFind(int n) {
            parent.resize(n);
            size.resize(n, 1);
            maxSize = 1;
            for (int i = 0; i < n; i++) {
                parent[i] = i;
            }
        }

        int find(int x) {
            // Finds the root of x
            if (x != parent[x]) {
                parent[x] = find(parent[x]);
            }
            return parent[x];
        }

        bool unite(int x, int y) {
            // Connects x and y
            int rootX = find(x);
            int rootY = find(y);
            if (rootX != rootY) {
                if (size[rootX] < size[rootY]) {
                    swap(rootX, rootY);
                }
                parent[rootY] = rootX;
                size[rootX] += size[rootY];
                maxSize = max(maxSize, size[rootX]);
                return true;
            }
            return false;
        }
    };

    int minCostConnectPoints(vector<vector<int>>& points) {
        vector<vector<int>> edges;
        for (int i = 0; i < points.size(); i++) {
            for (int j = i + 1; j < points.size(); j++) {
                edges.push_back({ i, j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]) });
            }
        }
        sort(edges.begin(), edges.end(), [](auto& a, auto& b) {
            return a[2] < b[2];
            });
        
        int res = 0;
        UnionFind ufStd(points.size());
        for (const auto& edge : edges) {
            if (ufStd.unite(edge[0], edge[1])) {
                res += edge[2];
            }
        }
       
        return res;
    }
};



int main() {
    Solution s;
    vector<vector<int>> v = { {0,0},{1,1},{1,0},{-1,1}};
    cout<<s.minCostConnectPoints(v);

	return 0;
}
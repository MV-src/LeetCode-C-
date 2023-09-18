#include <iostream>
#include <vector>
#include <queue>
#include <numeric>
using namespace std;

class Solution {
public:
    int bs(vector<int>& mat) {
        int low = 0;
        int high = mat.size();
        while (low < high) {
            int mid = (low + high) / 2;
            if (mat[mid] == 0) {
                high = mid;
            }
            else if (mat[mid] == 1) {
                low = mid + 1;
            }
        }
        return low-1;
    }

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>> pq;
        vector<int> res;

        for (int i = 0; i<mat.size();i++) {
            int n = bs(mat[i]) + 1;
            if (pq.size() < k) pq.push({ n,i });
            else if (pq.size() == k && pq.top().first > n) {
                pq.pop();
                pq.push({n,i});
            }
        }

        while (!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

/*Another Solution*/
class Solution2 {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rowStrengths;
        for (int i = 0; i < mat.size(); ++i) {
            int strength = accumulate(mat[i].begin(), mat[i].end(), 0);
            rowStrengths.push_back({ strength, i });
        }

        sort(rowStrengths.begin(), rowStrengths.end());

        vector<int> result;
        for (int i = 0; i < k; ++i) {
            result.push_back(rowStrengths[i].second);
        }

        return result;
    }
};

int main() {
    vector<vector<int>> v = { {1,1,0,0,0}, {1,1,1,1,0},{1,0,0,0,0}, {1,1,0,0,0}, {1,1,1,1,1} };
    Solution s;
    s.kWeakestRows(v, 3);
    return 0;
}
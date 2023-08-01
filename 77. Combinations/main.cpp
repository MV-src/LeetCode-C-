#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:

    vector<vector<int>> fun(int n, int k, int i, unordered_map<string, vector<vector<int>>>& dp) {
        if (k == 0) return { {} };
        string key = to_string(k) + " " + to_string(i);
        if (dp.find(key) != dp.end()) return dp[key];
        vector<vector<int>> res;
        for (int j = i + 1; j < n - k + 2; j++) {
            vector<vector<int>> temp = fun(n, k - 1, j, dp);
            for (auto& x : temp) x.push_back(j);
            for (auto x : temp) res.push_back(x);
        }
        return dp[key] = res;
    }

    vector<vector<int>> combine(int n, int k) {
        unordered_map<string, vector<vector<int>>> dp;
        return fun(n, k, 0, dp);
    }
};


class BestSolution {
public:

    vector<vector<int>> fun(int n, int k, int i, unordered_map<string, vector<vector<int>>>& dp) {
        if (k == 0) return { {} };
        string key = to_string(k) + " " + to_string(i);
        if (dp.find(key) != dp.end()) return dp[key];
        vector<vector<int>> res;
        for (int j = i+1; j < n-k+2; j++) {
            vector<vector<int>> temp = fun(n, k - 1, j, dp);
            for (auto& x : temp) x.push_back(j);
            for(auto x: temp) res.push_back(x);
        }
        return dp[key] = res;
    }

    vector<vector<int>> combine(int n, int k) {
        unordered_map<string, vector<vector<int>>> dp;
       return fun(n,k,0,dp);
    }
};

int main() {
    BestSolution s;
    vector<vector<int>> v = s.combine(4, 2);
    for (auto x : v) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << endl;
    }
	return 0;
}
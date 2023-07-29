#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:

    double fun(int A, int B, vector<pair<int,int>>&options, unordered_map<string, double>& dp) {
        string key = to_string(A) + " " + to_string(B);
        if (dp.find(key) != dp.end()) return dp[key];
        if (A <= 0 && B <= 0) return dp[key] = 0.5;
        if (A <= 0) return dp[key] = 1;
        if (B <= 0) return dp[key] = 0;
        double prob = 0;
        for (int i = 0; i < 4; i++) {
             prob += fun(A - options[i].first, B - options[i].second, options,dp);
        }
        return dp[key]=prob*0.25;
    }

    double soupServings(int n) {
        if (n >= 20000) return 1;
        unordered_map<string, double> dp;
        vector<pair<int, int>> options = { {100,0},{75,25},{50,50},{25,75} };
        return fun(n,n,options,dp);
    }
};

int main() {
    Solution s;
    cout<<s.soupServings(30000);
	return 0;
}
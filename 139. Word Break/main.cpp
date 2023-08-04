#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool fun(string s, vector<string>& wordDict, unordered_map<string, bool>& dp) {
        int sizeString = s.length();
        if (sizeString == 0) return dp[s] = true;
        if (dp.find(s) != dp.end()) return dp[s];
        for (auto x : wordDict) {
            int size = x.length();
            string str = s.substr(0, size);
            if (str == x) {
                if (fun(s.substr(size), wordDict,dp)) return dp[s]=true;
            }
        }
        return dp[s] = false;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, bool> dp;
        return fun(s, wordDict,dp);
    }
};

int main() {

    Solution s;
    vector<string> dic = { "leet","code" };
    cout<<s.wordBreak("leetcode", dic);
	return 0;
}
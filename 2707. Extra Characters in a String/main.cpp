#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <functional>
using namespace std;

class Solution {
public:
    int fun(string s, int i, vector<string>& dictionary, int size, unordered_map<int, int>& dp) {
        if (i >= size) {
            return 0;
        }
        if (dp.find(i) != dp.end()) return dp[i];
        dp[i] = INT32_MAX;
        for (auto& x : dictionary) {
            string temp = s;
            temp = s.substr(i, x.size());
            if (x == temp) {
                dp[i] = min(dp[i], fun(s, i + x.size(), dictionary, size, dp));
            }
        }
        dp[i] = min(dp[i], fun(s, i + 1, dictionary, size, dp)+1);
        return dp[i];
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<int, int> dp;
        return fun(s,0, dictionary, s.size(), dp);
    }
};

/*class Solution {
public:
    int minExtraChar(string s, vector<string> dictionary) {
        int n = s.length();
        unordered_set<string> dictionarySet(dictionary.begin(), dictionary.end());
        unordered_map<int, int> memo;

        function<int(int)> dp = [&](int start) {
            if (start == n) {
                return 0;
            }
            if (memo.count(start)) {
                return memo[start];
            }
            // To count this character as a left over character 
            // move to index 'start + 1'
            int ans = dp(start + 1) + 1;
            for (int end = start; end < n; end++) {
                auto curr = s.substr(start, end - start + 1);
                if (dictionarySet.count(curr)) {
                    ans = min(ans, dp(end + 1));
                }
            }

            return memo[start] = ans;
            };

        return dp(0);
    }
};*/



int main() {
    Solution s;
    vector<string> v = {"ae", "zdzz","lgrhy","r","ohk","zkowk","g","zqpn","anoni","ka","qafkx","t","jr","xdye","mppc","bqqb","encgp","yf","vl","ctsxk","gn","cujh","ce","rwrpq","tze","zxhg","yzbe","c","o","hnk","gv","uzbc","xn","kk","ujjd","vv","mxhmv","ugn","at","kumr","ensv","x","uy","gb","jljuo","xqkgj" };
    cout<<s.minExtraChar("aencgpgvsckjrqafkxgyzbe",v);
	return 0;
}
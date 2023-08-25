#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:

    bool fun(string s1, int i1, string s2, int i2, string s3, int i3, unordered_map<string, bool>& dp) {
        if (i1 >= s1.size() && i2 >= s2.size()) return true;
        string key = to_string(i1) + " " + to_string(i2) + " " + to_string(i3);
        if (dp.find(key) != dp.end()) return dp[key];
        bool res = false;
        if (i1<s1.size() && i2<s2.size() && (s1[i1] == s3[i3] && s2[i2] == s3[i3])) {
            res = fun(s1, i1 + 1, s2, i2, s3, i3 + 1,dp) || fun(s1, i1, s2, i2 + 1, s3, i3 + 1,dp);
        }
        else if (i1<s1.size() && s1[i1] == s3[i3]) {
            res = fun(s1, i1 + 1, s2, i2, s3, i3 + 1,dp);
        }
        else if (i2<s2.size() && s2[i2] == s3[i3]) {
            res = fun(s1, i1, s2, i2 + 1, s3, i3 + 1,dp);
        }
        return dp[key] = res;
    }

    bool isInterleave(string s1, string s2, string s3) {
        unordered_map<string, bool> dp;
        if (s1.size() + s2.size() != s3.size()) return false;
        return fun(s1,0, s2,0, s3,0,dp);
    }
};

int main() {

	return 0;
}
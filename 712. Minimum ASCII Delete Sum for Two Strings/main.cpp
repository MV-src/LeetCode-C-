#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*class Solution {
public:
    int src(string s1, string s2) {
        int j = 0;
        int res = 0;
        for (int i = 0; i < s1.length(); i++) {
            if (s1[i] == s2[j]) j++;
            else res += (int)s1[i];
        }
        return res;
    }

    int minimumDeleteSum(string s1, string s2) {
        int res = INT32_MAX;
        string str = s1;
        int len = min(s1.length(),s2.length());
        if (len != s1.length()) s1 = s2;
        else s2 = str;
        if (s1.find(s2) != string::npos) {
            return src(s1, s2);
        }
        len--;
        int j = 0;
        while (len>0) {
            int diff = s1.length() - len;
            int temp = j;
            for (int i = 0; i < s1.length(); i++,j++) {
                str = s2;
                str.erase(i,j);
                res = min(res, src(s1, str));
            }
            j = temp;
            j += diff;
            len--;
        }
        return res;
    }
};*/

class Solution {
public:
    long long help(int i, int j, string& s1, string& s2, vector<vector<int>>& dp) {
        if (i == s1.size() && j == s2.size())return 0;
        if (i == s1.size()) {
            int d = 0;
            for (int k = j; k < s2.size(); k++) {
                d += (int)s2[k];
            }
            return d;
        }
        if (j == s2.size()) {
            int d = 0;
            for (int k = i; k < s1.size(); k++) {
                d += (int)s1[k];
            }
            return d;
        }
        if (dp[i][j] != -1)return dp[i][j];
        long long ans = INT_MAX;
        if (s1[i] == s2[j])ans = help(i + 1, j + 1, s1, s2, dp);
        else {
            ans = min(ans, s1[i] + help(i + 1, j, s1, s2, dp));
            ans = min(ans, s2[j] + help(i, j + 1, s1, s2, dp));
        }
        return dp[i][j] = ans;
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>>dp(s1.size(), vector<int>(s2.size(), -1));
        return help(0, 0, s1, s2, dp);
    }
};


int main() {
    Solution s;
    cout<<s.minimumDeleteSum("delete", "leet");
	return 0;
}
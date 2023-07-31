#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
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

/*class Solution {
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
};*/

struct hash_pair {
    template <class T1, class T2>
    size_t operator()(const pair<T1, T2>& p) const
    {
        auto hash1 = hash<T1>{}(p.first);
        auto hash2 = hash<T2>{}(p.second);

        if (hash1 != hash2) {
            return hash1 ^ hash2;
        }

        // If hash1 == hash2, their XOR is zero.
        return hash1;
    }
};

class Solution {
public:
    int fun(string s1, string s2,int i,int j, int size1, int size2, unordered_map<pair<int, int>, int, hash_pair>& dp) {
        int res = 0;
        if (dp.find(make_pair(i,j)) != dp.end()) return dp[make_pair(i, j)];
        if (i >= size1 && j >= size2) return dp[{i, j}] = 0;
        if (i >= size1) {
            for (; j < size2; j++) {
                res += s2[j];
            }
            return dp[{i, j}]=res;
        }

        if (j >= size2) {
            for (; i < size1; i++) {
                res += s1[i];
            }
            return dp[{i, j}] = res;
        }
        if (s1[i] == s2[j]) return dp[{i, j}]=fun(s1, s2, i + 1, j + 1, size1, size2, dp);
        res = INT32_MAX;
        
        res = min((int)s1[i]+fun(s1,s2,i+1,j,size1,size2,dp), (int)s2[j]+fun(s1, s2, i, j+1, size1, size2, dp));
        res = min(res, (int)s1[i]+(int)s2[j]+fun(s1, s2, i + 1, j+1, size1, size2, dp));
        return dp[{i, j}]=res;
    }


    int minimumDeleteSum(string s1, string s2) {
        unordered_map<pair<int, int>, int,hash_pair> dp;
        return fun(s1, s2,0,0, s1.length(), s2.length(), dp);
    }
};


int main() {
    Solution s;
    cout<<s.minimumDeleteSum("delete", "leet");
	return 0;
}
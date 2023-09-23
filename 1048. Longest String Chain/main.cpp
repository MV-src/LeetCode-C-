#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;

/*class Solution {
public:
    int fun(vector<string>& words, string currWord, int i, unordered_map<string, int>& dp) {
        if (i >= words.size()) return 0;
        if (dp.find(currWord) != dp.end()) return dp[currWord];
        int res = 1;
        for (int j = i + 1; j < words.size(); j++) {
            bool check = false;
            int k = 0;
            for (int l = 0; l < words[j].size(); l++) {
                if (words[j].size() == currWord.size()) break;
                if (currWord[k] == words[j][l]) k++;
                if (k == currWord.size()) {
                    check = true;
                    break;
                }
            }
            if (check) res = max(res, 1+fun(words, words[j], j, dp));
        }
        return dp[currWord] = res;
    }

    int longestStrChain(vector<string>& words) {
        
        sort(words.begin(), words.end());
        unordered_map<string, int> dp;
        int res = 0;
        for (int i = 0; i<words.size(); i++) {
            res = max(res, fun(words, words[i], i, dp));
        }
        return res;
    }
};*/

class Solution {
public:
    static bool cmp(const string& s1, const string& s2) {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), cmp);
        unordered_map<string, int> ump;
        int ans = 0;
        for (string w : words) {
            int longest = 0;
            for (int i = 0; i < w.length(); i++) {
                string sub = w;
                sub.erase(i, 1);
                longest = max(longest, ump[sub] + 1);
            }
            ump[w] = longest;
            ans = max(ans, longest);
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<string> v = { "a","b","ba","bca","bda","bdca" };
    cout<<s.longestStrChain(v);
	return 0;
}
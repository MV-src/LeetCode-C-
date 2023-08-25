#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    string reorganizeString(string s) {
        if (s.size() == 1) return s;
        vector<int> let(26,0);
        for (int i = 0; i < s.size(); i++) {
            let[s[i] - 97]++;
        }
        vector<pair<int, char>> letters;
        for (int i = 0; i < let.size(); i++) {
            if (let[i] == 0) continue;
            letters.push_back(make_pair(let[i], char(i + 97)));
        }
        if (s.size() >= 1 && letters.size() == 1) return "";
        string str = "";
        sort(letters.begin(), letters.end(), greater<pair<int, char>>());
        str += letters[0].second;
        letters[0].first--;
        sort(letters.begin(), letters.end(), greater<pair<int, char>>());
        while(letters[0].first != 0) {
            int i = 0;
            if (str.back() == letters[i].second) i++;
            if (letters[i].first == 0) return "";
            str += letters[i].second;
            letters[i].first--;
            sort(letters.begin(), letters.end(), greater<pair<int, char>>());
        }
        return str;
    }
};


class Solution2 {
public:
    string reorganizeString(string s) {
        vector<int> charCounts(26, 0);
        for (char c : s) {
            charCounts[c - 'a'] = charCounts[c - 'a'] + 1;
        }

        // Max heap ordered by character counts
        priority_queue<vector<int>> pq;
        for (int i = 0; i < 26; i++) {
            if (charCounts[i] > 0) {
                pq.push(vector<int>{charCounts[i], i + 'a'});
            }
        }

        string result;
        while (!pq.empty()) {
            auto first = pq.top();
            pq.pop();
            if (result.empty() || first[1] != result.back()) {
                result += char(first[1]);
                if (--first[0] > 0) {
                    pq.push(first);
                }
            }
            else {
                if (pq.empty()) {
                    return "";
                }
                auto second = pq.top();
                pq.pop();
                result += char(second[1]);
                if (--second[0] > 0) {
                    pq.push(second);
                }
                pq.push(first);
            }
        }

        return result;
    }
};

int main() {
    Solution2 s;
    cout<<s.reorganizeString("ddbbcddbca");
	return 0;
}
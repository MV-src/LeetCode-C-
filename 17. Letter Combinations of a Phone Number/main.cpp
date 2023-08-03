#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fun(string digits, int size, int i, unordered_map<int, string>& letters) {
        vector<string> res;
        string j(1, digits[i]);
        int n = stoi(j);
        if (i == size-1) {
            for (auto x : letters[n]) {
                string b(1, x);
                res.push_back(b);
            }
            return res;
        }
        
        for (auto x : letters[n]) {
            vector<string> s = fun(digits, size, i + 1, letters);
            for (auto& y : s) y +=x;
            for (auto y : s) res.push_back(y);
        }
        return res;
    }

    vector<string> letterCombinations(string digits) {
        int size = digits.size();
        reverse(digits.begin(), digits.end());
        unordered_map<int, string> letters;
        letters[2] = "abc";
        letters[3] = "def";
        letters[4] = "ghi";
        letters[5] = "jkl";
        letters[6] = "mno";
        letters[7] = "pqrs";
        letters[8] = "tuv";
        letters[9] = "wxyz";
        if (size == 0) return {};
        return fun(digits,size,0,letters);
    }
};

int main() {
    Solution s;
    vector<string> res = s.letterCombinations("23");
    for (auto x : res) {
        cout << x<<" ";
    }
    return 0;
}
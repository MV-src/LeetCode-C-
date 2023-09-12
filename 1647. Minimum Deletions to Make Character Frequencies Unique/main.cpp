#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minDeletions(string s) {
        vector<int> letters(26,0);
        for (auto& x : s) {
            letters[x-97]++;
        }
        int res = 0;
        sort(letters.rbegin(), letters.rend());
        for (int i = 1; i < letters.size(); i++) {
            int maximum = letters[i - 1];
            if (letters[i] == 0) continue;
            if (maximum == 0) maximum++;
            if (letters[i] >= maximum) {
                res+=letters[i]-maximum+1;
                letters[i] -= letters[i] - maximum+1;
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout<<s.minDeletions("bbcebab");
	return 0;
}
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i = 0;
        if (t.size() == 0 && s.size() == 0) return true;
        for (int j = 0; j < t.size(); j++) {
            if (s[i] == t[j]) i++;
            if (i == s.size()) return true;
        }
        return false;
    }
};

int main() {

	return 0;
}
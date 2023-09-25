#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            ans ^= s[i];
            ans ^= t[i];
        }
        ans ^= t[t.size() - 1];
        return ans;
    }
};
 
int main() {

	return 0;
}
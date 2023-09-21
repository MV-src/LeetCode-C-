#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;
        string res = "";
        for (int i = 0; i < numRows && i<s.size(); i++) {
            int jump1 = (numRows - i - 1)*2;
            int jump2 = i*2;
            int j = i;
            res += s[j];
            while (j < s.size()) {
                if (jump1 != 0) {
                    j += jump1;
                    if(j < s.size()) res += s[j];
                }
                if (jump2 != 0) {
                    j += jump2;
                    if(j < s.size())res += s[j];
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    cout<<s.convert("PAYPALISHIRING", 3);
	return 0;
}
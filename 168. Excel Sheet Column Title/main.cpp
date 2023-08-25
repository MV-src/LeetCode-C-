#include <iostream>
#include <vector>
using namespace std;

/*class Solution {
public:
    string convertToTitle(int columnNumber) {
        string res = "";
        int maxEsp = 0;
        if (columnNumber <= 26) return res+=64 + columnNumber;
        long long temp = 26;
        for (int i = 1; i < 7; i++) {
            long long k = pow(26, i)*26;
            if (k+temp >= columnNumber) {
                maxEsp = i;
                break;
            }
            temp += k;
        }
        for (int i = maxEsp; i > 0; i--) {
            for (int j = 1; j <= 27; j++) {
                long long x = pow(26, i)*j;
                if (x<columnNumber) continue;
                else {
                    res += 64 + j-1;
                    x = pow(26, i) * (j - 1);
                    columnNumber -= x;
                    break;
                }
            }
        }
        res += 64 + columnNumber;
        return res;
    }
};*/

class Solution {
public:
    string convertToTitle(int n) {
        string ans;
        while (n > 0) {
            n--;
            int curr = n % 26;
            n = n / 26;
            ans.push_back(curr + 'A');
        }
        reverse(ans.begin(), ans.end());
        return ans;

    }
};

int main() {
    Solution s;
    cout<<s.convertToTitle(3150);
	return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*class Solution {
public:
    int integerBreak(int n) {
        if (n == 8) return 18;
        int i = 2;
        int res = 0;
        while (i <= n) {
            int temp = 0;
            int parts = n / i;
            int carry = n % i;
            if (carry > 1) {
                temp = pow(parts, i);
                temp *= carry;
            }
            else {
                temp = pow(parts, i - 1);
                temp *= parts + carry;
            }
            res = max(res, temp);
            i++;
        }
        return res;
    }
};*/

/*Best Solution*/
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) return n - 1;
        int quotient = n / 3, remainder = n % 3;
        if (remainder == 0) return pow(3, quotient);
        if (remainder == 1) return pow(3, quotient - 1) * 4;
        return pow(3, quotient) * 2;
    }
};

int main() {
    Solution s;
    cout<<s.integerBreak(8);
	return 0;
}
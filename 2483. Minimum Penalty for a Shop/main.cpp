#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int bestClosingTime(string customers) {
        int sum = 0;
        for (auto& x : customers) {
            if (x == 'Y') sum++;
        }
        if (!sum) return 0;
        int pen = sum;
        int res = 0;
        int count = 1;
        for (int i = 0; i<customers.size();i++) {
            int temp = pen;
            if (customers[i] == 'Y') sum--;
            else sum++;
            pen = min(pen, sum);
            if (temp != pen) res = count;
            count++;
        }
        return res;
    }
};

int main() {
    Solution s;
    cout<<s.bestClosingTime("YYYY");
	return 0;
}
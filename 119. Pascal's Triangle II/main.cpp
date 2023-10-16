#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<vector<int>> r(rowIndex);
        for (int i = 0; i < rowIndex; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        return r[rowIndex-1];
    }
};

int main() {
    Solution s;
    s.getRow(3);
	return 0;
}
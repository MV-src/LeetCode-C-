#include <iostream>
#include <vector>
using namespace std;

/*class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if (numRows == 1) {
            res.push_back({1});
            return res;
        }
        else if (numRows == 2) {
            res.push_back({ 1 });
            res.push_back({ 1, 1 });
            return res;
        }
        res.push_back({ 1 });
        res.push_back({ 1, 1 });
        for (int i = 2; i <= numRows; i++) {
            res.push_back({ 1 });
            int r = 0;
            for (int l = 1; l < res[i - 1].size(); r++, l++) {
                res[i].push_back(res[i - 1][r] + res[i - 1][l]);
            }
            res[i].push_back(1);
        }
        return res;
    }
};*/


/*PASCAL TRIANGLE BEST ALGORITHM*/
class Solution {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int>> r(numRows);

        for (int i = 0; i < numRows; i++) {
            r[i].resize(i + 1);
            r[i][0] = r[i][i] = 1;

            for (int j = 1; j < i; j++)
                r[i][j] = r[i - 1][j - 1] + r[i - 1][j];
        }

        return r;
    }
};


int main() {

	return 0;
}
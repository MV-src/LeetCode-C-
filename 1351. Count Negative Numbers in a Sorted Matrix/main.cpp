#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int n = grid.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int ub = upper_bound(grid[i].rbegin(), grid[i].rend(), -1) - grid[i].rbegin();

            ans += ub;
        }

        return ans;
    }
};
/*class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int result = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                result += grid[i][j] < 0 ? 1 : 0;
            }
        }
        return result;
    }
};
*/
int main() {
    Solution s;
    vector<vector<int>> v = { {4,3,2,-1},{3,2,1,-1},{1,1,-1,-2},{-1,-1,-2,-3} };
    s.countNegatives(v);
    return 0;
}

/*
Best solution with Time Complexityi of O(n+m)
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {

        int n = grid.size();
        int ans = 0;

        for(int i=0;i<n;i++){
            int ub = upper_bound(grid[i].rbegin(),grid[i].rend(),-1) - grid[i].rbegin();

            ans += ub;
        }

        return ans;
    }
};
*/
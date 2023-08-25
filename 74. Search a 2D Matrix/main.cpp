#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool fun(vector<vector<int>>& matrix,int m, int n, int target,int sizeM) {
        if (m>sizeM || n<0) return false;
        if (target == matrix[m][n]) return true;
        if (target < matrix[m][n]) return fun(matrix, m, n-1, target, sizeM);
        if (target > matrix[m][n]) return fun(matrix, m+1,n, target, sizeM);
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return fun(matrix, 0, matrix[0].size() - 1, target, matrix.size() - 1);
    }
};

int main() {
    Solution s;
    vector<vector<int>> mat = { {1,3,5,7},{10,11,16,20},{23,30,34,60} };
    cout<<s.searchMatrix(mat, 80);
    return 0;
}
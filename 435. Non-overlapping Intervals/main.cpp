#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*class Solution {
public:
    int fun(vector<vector<int>>& intervals, int right, int left,int i, int size) {
        if (i >= size) return 0;
        int ans = 0;
        if ((intervals[i][1] <= left) || (intervals[i][0] >= right)) {
            left = min(left, intervals[i][0]);
            right = max(right, intervals[i][1]);
            ans = fun(intervals, right, left, i + 1, size);
        }
        else {
            int n1 = fun(intervals, right, left, i + 1, size);
            if (!(intervals[i][1] <= left)) right = intervals[i][1];
            if (!(intervals[i][0] >= right)) left = intervals[i][0];
            int n2 = fun(intervals, right, left, i + 1, size);
            ans = min(n1, n2)+1;
        }
        return ans;
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int size = intervals.size();
        sort(intervals.begin(), intervals.end());
        return fun(intervals,INT32_MIN,INT32_MIN,0,size);
    }
};*/

bool compareSecondElement(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), compareSecondElement);
        int ans = 0;
        int k = INT_MIN;

        for (int i = 0; i < intervals.size(); i++) {
            int x = intervals[i][0];
            int y = intervals[i][1];

            if (x >= k) {
                // Case 1
                k = y;
            }
            else {
                // Case 2
                ans++;
            }
        }

        return ans;
    }
};

int main() {
    vector<vector<int>> v = { {-1,1 },{10,11},{12,14},{3,4} };
    Solution s;
    cout << s.eraseOverlapIntervals(v);
    
	return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*class Solution {
public:
    bool test(int runtime, ) {

    }

    long long maxRunTime(int n, vector<int>& batteries) {
        int res = 0;
        int low = 0;
        int high = 1e9;
        int mid = 0;
        while (low > high) {
            mid = (low + high) / 2;
            if(fun())
        }

        return res;
    }
};*/

class Solution {
public:
    long long maxRunTime(int n, vector<int>& b) {
        long long low = 1;
        long long high = 0;
        for (auto x : b) {
            high += x;
        }
        high /= n;

        while (low < high) {
            long long mid = (high+low+1) / 2;
            long long time = 0;
            for (int t : b) time += min((long long)t, mid);

            if (mid * n <= time) low = mid;
            else high = mid - 1;
        }
        return low;
    }
};

int main() {
    Solution s;
    vector<int> v = { 3,3,3 };
    cout<<s.maxRunTime(2,v);
	return 0;
}
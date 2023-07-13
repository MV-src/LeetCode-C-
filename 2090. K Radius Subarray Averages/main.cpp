#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> avgs;
        int n = nums.size();
        int divider = (k * 2) + 1;
        if (n % 2 == 0) {
            if (k > (n / 2)-1) {
                for (int i = 0; i < n; i++) avgs.push_back(-1);
                return avgs;
            }
        }
        else {
            if (k > n / 2) {
                for (int i = 0; i < n; i++) avgs.push_back(-1);
                return avgs;
            }
        }
        
        long long sum = 0;
        
        for (int i = 0; i < k; i++) {
            sum += nums[i];
            avgs.push_back(-1);
        }
        for (int i = k; i < divider; i++) sum += nums[i];

        avgs.push_back(floor(sum / divider));
        
        for (int i = k + 1; i < n - k; i++) {
            sum -= nums[i - k-1];
            sum += nums[i + k];
            avgs.push_back(floor(sum / divider));
        }

        for (int i = n - k; i < n; i++) avgs.push_back(-1);
        return avgs;
    }
};


int main()
{
    Solution s;
    vector<int> v = { 1,11,17,21,29 };
    s.getAverages(v, 4);
	return 0;
}
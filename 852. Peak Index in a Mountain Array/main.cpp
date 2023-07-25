#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        //return find(arr.begin(), arr.end(),*max_element(arr.begin(),arr.end())) - arr.begin();
        int size = arr.size();
        int res = (arr.size()-1) / 2;
        int low = 0;
        int high = size;
        if (arr[res] < arr[res + 1]) low = res;
        else high = res;
        while (!(arr[res] > arr[res - 1] && arr[res] > arr[res + 1])) {
            if (arr[res] < arr[res + 1]) {
                low = res;
                res = (high + res) / 2;
            }
            else {
                high = res;
                res = (low + res) / 2;
            }
        }
        return res;
    }
};

int main() {
    vector<int> v = { 55,59,63,99,97,94,84,81,79,66,40,38,33,23,22,21,17,9,7 };
    Solution s;
    cout<<s.peakIndexInMountainArray(v);
	return 0;
}
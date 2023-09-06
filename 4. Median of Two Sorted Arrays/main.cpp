#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i = 0;
        int j = 0;
        float ans = 0;
        vector<int> res;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j]) {
                res.push_back(nums1[i]);
                i++;
            }
            else {
                res.push_back(nums2[j]);
                j++;
            }
        }
        for (; i < nums1.size(); i++) res.push_back(nums1[i]);
        for (; j < nums2.size(); j++) res.push_back(nums2[j]);
        int size = res.size();
        if (size % 2 == 1) {
            ans = res[size / 2];
        }
        else {
            ans = (float)(res[size / 2] + res[(size / 2) - 1]) / 2.0;
        }
        return ans;
    }
};

int main() {

	return 0;
}
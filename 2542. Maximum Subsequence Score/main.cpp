#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int size = nums1.size();
        vector<pair<int, int>> pairs;

        for (int i = 0; i < size; i++) {
            pairs.push_back({ nums2[i], nums1[i] });
        }

        std::sort(pairs.rbegin(), pairs.rend());
       
        long long ans = 0;
        long long currSum = 0;
        priority_queue<int, vector<int>, greater<int>> pq;

        for (int i = 0; i < k - 1; i++) {
            currSum += pairs[i].second;
            pq.push(pairs[i].second);
        }

        for (int i = k - 1; i < nums1.size(); i++) {
            currSum += pairs[i].second;
            pq.push(pairs[i].second);
            ans = std::max(ans, currSum * pairs[i].first);

            currSum -= pq.top();
            pq.pop();
        }
        return ans;
    }

};

int main()
{
    vector<int> nums1 = { 1,3,3,2 };
    vector<int> nums2 = { 2,1,3,4 };
    Solution s;
    std::cout << s.maxScore(nums1, nums2, 3);

    return 0;
}
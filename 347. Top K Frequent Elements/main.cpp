#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
#include "chains.h"
using namespace std;


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int>mp;
        vector<int> res;
        priority_queue<pair<int, int>> pq; 

        for (int i = 0; i < n; i++)
        {
            mp[nums[i]]++;
        }

        for (pair<int,int> n : mp) {
            pq.push(make_pair(n.second, n.first));
        }
        
        for (int i = 0; i < k; i++)
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }


};

int main() {
    Solution s;
    vector<int> nums = { 5,-3,9,1,7,7,9,10,2,2,10,10,3,-1,3,7,-9,-1,3,3 };
    vector<int> prova;
    prova = s.topKFrequent(nums, 3);
    for (int n : prova) {
        cout << n << " ";
    }
    return 0;
}





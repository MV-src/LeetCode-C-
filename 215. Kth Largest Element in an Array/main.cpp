#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int i = 0; i < nums.size(); i++) pq.push(nums[i]); 
        
        int size = pq.size() - k;
        for (int i = 0; i < size ; i++) pq.pop();

        return pq.top();
    }
};

int main() {
    Solution s;
    vector<int> v = { 3,2,3,1,2,4,5,5,6 };
    cout<<s.findKthLargest(v,4);
	return 0;
}
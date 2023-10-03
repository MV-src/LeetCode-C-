#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int res = 0;
        for(int i = 0; i<nums.size(); i++){
            for(int j = i+1; j<nums.size(); j++){
                if(nums[i] == nums[j]) res++;
            }
        }
        return res;
    }
};*/

/*Best Solution*/
class Solution {
public:
    int numIdenticalPairs(vector<int>& A) {
        int ans = 0;
        unordered_map<int, int> cnt;
        for (int x : A) {
            ans += cnt[x]++;
        }
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v = { 1,2,3,1,1,3 };
    s.numIdenticalPairs(v);

	return 0;
}
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2)
            return n;

        int longest = 2;
        vector<unordered_map<int, int>> dp(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;
                longest = max(longest, dp[i][diff]);
            }
        }

        return longest;
    }
};


int main() {
    Solution s;
    vector<int> v = { 9,4,7,2,10 };
    s.longestArithSeqLength(v);

	return 0;
}



/*
class Solution {
public:
    bool check(int x, int y, int magg) {
        if (magg == 1) {
            return x > y ? true : false;
        }
        else {
            return x < y ? true : false;
        }
    }

    int longestArithSeqLength(vector<int>& nums) {
        int result = 0;
        int temp = 0;
        int size = 0;
        for (int i = 0; i < nums.size(); i++) {
            size = max(nums[i], size);
        }
        size++;
        map<int, pair<int,int>> mp;
        for (int i = 0; i < size; i++) mp.emplace(i, make_pair( 0,0 ));
        for (int i = 0; i < nums.size(); i++)mp[nums[i]] = { 1,i };

        int i = 0;
        while (i < size) {
            if (mp[i].first == 0) {
                i++;
                continue;
            }
            int j = 1;
            while (j + i < size) {
                if (mp[j + i].first == 1) {
                    int key = j;
                    int z = i + j;
                    temp+=2;
                    int magg = mp[i].second > mp[i + j].second ? 1 : 0;
                    while (z + key < size && mp[z+key].first == 1 && check(mp[z].second, mp[z+key].second,magg)) {
                        temp++;
                        z += key;
                    }
                    result = max(temp, result);
                    temp = 0;
                }
                j++;
            }
            i++;
        }
        cout << result;
        return result;
    }
};


*/
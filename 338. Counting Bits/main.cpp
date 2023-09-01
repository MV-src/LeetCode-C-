#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for (int i = 0; i <= n; i++) res.push_back(__popcnt64(i)); //__builtin_popcount(i)
        return res;
    }
};

/*
Without builtin function*/
class Solution2 {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        // iterating fromt 0 to n
        for(int i = 0; i<=n; i++)
        {
            // sum is initialised as 0
            int sum = 0;
            int num = i;
            // while num not equals zero
            while(num != 0)
            {
                // we have to count 1's in binary representation of i, therefore % 2
                sum += num%2;
                num = num/2;
            }
            // add sum to ans vector
            ans.push_back(sum);
        }
        // return
        return ans;
    }
};


int main() {
    Solution s;
    vector<int> v = s.countBits(8);
	return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
public:

    int numberOfWays(vector<int>& coins,int i, int amount,vector<vector<int>>& memo) {
        if (amount == 0) {
            return 1;
        }
        if (i == coins.size()) {
            return 0;
        }
        if (memo[i][amount] != -1) {
            return memo[i][amount];
        }

        if (coins[i] > amount) {
            return memo[i][amount] = numberOfWays(coins,i + 1, amount,memo);
        }

        memo[i][amount] = numberOfWays(coins,i, amount - coins[i],memo) + numberOfWays(coins,i + 1, amount,memo);
        return memo[i][amount];
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> memo;
        memo = vector<vector<int>>(coins.size(), vector<int>(amount + 1, -1));
        return numberOfWays(coins,0, amount,memo);
    }
};

int main() {
    Solution s;
    vector<int> v = { 1,2,5 };
    cout<<s.change(5, v);
	return 0;
}
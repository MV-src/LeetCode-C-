#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    int fun(vector<int>& prices, int fee, int i, int prFlag, int size,vector<vector<int>>& dp) {
        int profit = 0;
        int tempProfit = 0;
        int temp = 0;
        if (i >= size) return 0;
        if (i == size - 1 && prFlag == 0) return 0;
        if (dp[i][prFlag] != -1) return dp[i][prFlag];
        if (!prFlag) {
            tempProfit -= prices[i];
        }
        else {
            tempProfit += prices[i] - fee;
        }
        return dp[i][prFlag] = max(fun(prices, fee, i + 1, prFlag, size, dp), tempProfit + fun(prices, fee, i + 1, prFlag, size, dp));
    }

    int maxProfit(vector<int>& prices, int fee) {
        int result = 0;
        int size = prices.size();
        if (size == 1) return 0;
        int temp = 0;
        vector<vector<int>> dp(size, vector<int>(2, -1));
        return fun(prices, fee, 0, 0, size,dp);
    }
};

int main() {
    vector<int> prices = { 1,3};
    int fee = 1;
    Solution s;
    s.maxProfit(prices, fee);
	return 0;
}

/*
Solution

class Solution {
public:


int getAns(vector<int> &Arr,int ind,int buy,int n,int fee,vector<vector<int>> &dp){

    if(ind==n) return 0; //base case

    if(dp[ind][buy]!=-1)
        return dp[ind][buy];

    int profit;

    if(buy==0){// We can buy the stock
        profit = max(0+getAns(Arr,ind+1,0,n,fee,dp), -Arr[ind] + getAns(Arr,ind+1,1,n,fee,dp));
    }

    if(buy==1){// We can sell the stock
        profit = max(0+getAns(Arr,ind+1,1,n,fee,dp), Arr[ind] -fee + getAns(Arr,ind+1,0,n,fee,dp));
    }

    return dp[ind][buy] = profit;
}

    int maxProfit(vector<int>& Arr, int fee) {

        vector<vector<int>> dp(Arr.size(),vector<int>(2,-1));

    if(Arr.size()==0) return 0;
    int ans = getAns(Arr,0,0,Arr.size(),fee,dp);
    return ans;
    }
};

*/
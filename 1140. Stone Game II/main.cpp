#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int helper(vector<int>& piles, vector<vector<int>>& dp, const vector<int>& suffixSum, int i, int M) {
        if (i == piles.size()) return 0;
        if (i + 2 * M >= piles.size()) return suffixSum[i];
        if (dp[i][M] != 0) return dp[i][M];
        int result = 0;
        for (int x = 1; x <= 2 * M; ++x) {
            result = max(result, suffixSum[i] - helper(piles, dp, suffixSum, i + x, max(M, x)));
        }
        dp[i][M] = result;
        return result;
    }
    int stoneGameII(vector<int>& piles) {
        if (piles.empty()) return 0;
        vector<vector<int>> dp(piles.size(), std::vector<int>(piles.size(), 0));
        vector<int> suffixSum(piles.size());
        suffixSum[suffixSum.size() - 1] = piles[piles.size() - 1];
        for (int i = piles.size() - 2; i >= 0; --i) suffixSum[i] = piles[i] + suffixSum[i + 1];
        return helper(piles, dp, suffixSum, 0, 1);
    }
};
/*class Solution {
public:
    int stoneGameII(std::vector<int>& piles) {
        return fun(piles, 1, 0, 1,0,0).first;
    }

    std::pair<int,int> fun(std::vector<int> piles, int turn, int pos, int M, int aliceTot, int bobTot) {
        int ans = 0;
        for (int i = pos; i < 2 * M; i++) {
            if (turn == 1) {
                if ((piles.size() - i - (2 * M)) < 1) {
                    for (int j = pos; j < piles.size(); j++) {
                        aliceTot += piles[j];
                    }
                    return { aliceTot, bobTot };
                }
                else {
                    aliceTot += piles[i];
                    int n = 0;
                    int newM = std::max(M, i);
                    n = fun(piles, -turn, i, newM,aliceTot,bobTot).first;
                    ans = std::max(ans, n);
                }
            }
            else {
                if ((piles.size() - i - (2 * M)) < 1) {
                    for (int j = pos; j < piles.size(); j++) {
                        bobTot += piles[j];
                    }
                    return { aliceTot, bobTot };
                }
                else {
                    bobTot += piles[i];
                    int n = 0;
                    int newM = std::max(M, i);
                    n = fun(piles, -turn, i, newM, aliceTot, bobTot).second;
                    ans = std::max(ans, n);
                }
            }
        }
        return { aliceTot, bobTot };
    }
};*/

int main() {
    Solution s;
    vector<int> v = { 2,7,9,4,4 };
    s.stoneGameII(v);
    return 0;
}
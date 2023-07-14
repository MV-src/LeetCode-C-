#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int res = 1; 
        unordered_map<int, int> dp;
        if (difference < 0) {
            while (arr.size()/difference > res) {
                int size = arr.size();
                int tempResult = 1;
                int maximum = *max_element(arr.begin(), arr.end());
                int i;
                for (i = 0; i < size; i++) {
                    if (maximum == arr[i]) {
                        break;
                    }
                }
                if (dp.find(maximum) != dp.end()) {
                    res = max(res, dp[maximum]);
                    auto it = find(arr.begin(), arr.end(), maximum);
                    do {
                        arr.erase(it);
                        it = find(arr.begin(), arr.end(), maximum);
                    } while (it != arr.end());
                    continue;
                }
                int currDiff = maximum+difference;
                for (int j = i+1; j < size; j++) {
                    if (arr[j] == currDiff) {
                        tempResult++;
                        currDiff += difference;
                    }
                }
                res = max(tempResult, res);
                for (int j = tempResult; j > 0;j-- ) {
                    if (dp.find(tempResult) == dp.end()) {
                        dp.insert(make_pair(tempResult, j));
                        tempResult += difference;
                    }
                }

                auto it = find(arr.begin(), arr.end(), maximum);
                do {
                    arr.erase(it);
                   it = find(arr.begin(), arr.end(), maximum);
                } while (it != arr.end());
            }
        }
        else {
            while (arr.size()/difference > res) {
                int size = arr.size();
                int tempResult = 1;
                int minimum = *min_element(arr.begin(), arr.end());
                int i;
                for (i = 0; i < size; i++) {
                    if (minimum == arr[i]) {
                        break;
                    }
                }

                if (dp.find(minimum) != dp.end()) {
                    res = min(res, dp[minimum]);
                    auto it = find(arr.begin(), arr.end(), minimum);
                    do {
                        arr.erase(it);
                        it = find(arr.begin(), arr.end(), minimum);
                    } while (it != arr.end());
                    continue;
                }
                int currDiff = minimum + difference;
                for (int j = i + 1; j < size; j++) {
                    if (arr[j] == currDiff) {
                        tempResult++;
                        currDiff += difference;
                    }
                }
                for (int j = tempResult; j > 0; j--) {
                    if (dp.find(tempResult) == dp.end()) {
                        dp.insert(make_pair(tempResult, j));
                        tempResult += difference;
                    }
                }
                res = max(tempResult, res);
                auto it = find(arr.begin(), arr.end(), minimum);
                do {
                    arr.erase(it);
                    it = find(arr.begin(), arr.end(), minimum);
                } while (it != arr.end());
            }
        }
        return res;
    }
};*/


class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        unordered_map<int, int> dp;
        int answer = 1;

        for (int a : arr) {
            int beforeA = dp.count(a - difference) ? dp[a - difference] : 0;
            dp[a] = beforeA + 1;
            answer = max(answer, dp[a]);
        }

        return answer;
    }
};

int main() {

	return 0;
}


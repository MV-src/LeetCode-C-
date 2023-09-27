#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*class Solution {
public:
    string decodeAtIndex(string s, int k) {
        vector<pair<int,int>> res;
        string curr="";
        long long size = 0;
        unordered_map<string, int> dp;
        int count = 0;
        for (auto& x : s) {
            if (x >= '0' && x <= '9') {
                if (dp.find(curr) == dp.end()) {
                    dp[curr] = count;
                    count++;
                }
                int temp = dp[curr];
                size -= curr.size();
                for (int i = 0; i < (int)x - 48 && res.size()<k; i++) {
                    res.push_back({ temp, curr.size()});
                    size += curr.size();
                }
                curr = "";
            }
            else {
                curr += x;
                size++;
            }
            if (size >= k) {
                dp[curr] = count;
                res.push_back({ count, curr.size() });
                break;
            }
        }
        int temp = 0;
        int i = 0;
        for (i = 0; i < res.size() && temp < k; i++) {
            temp += res[i].second;
        }
        string ans;
        if (i == res.size()) i--;
        for (auto& x : dp) {
            if (x.second == res[i].first) {
                ans = x.first;
                break;
            }
        }
        temp = temp - k;
        return ans.substr(temp+1,1);
    }
};*/


class Solution {
public:
    std::string decodeAtIndex(std::string inputString, int k) {
        long long decodedLength = 0; // Total length of the decoded string
        for (auto character : inputString) {
            if (isdigit(character)) {
                // If the character is a digit, update the decoded length accordingly
                decodedLength *= character - '0';
            } else {
                // If the character is a letter, increment the decoded length
                decodedLength++;
            }
        }

        // Traverse the input string in reverse to decode and find the kth character
        for (int i = inputString.size() - 1; i >= 0; i--) {
            if (isdigit(inputString[i])) {
                // If the character is a digit, adjust the length and k accordingly
                decodedLength /= (inputString[i] - '0');
                k = k % decodedLength;
            } else {
                // If the character is a letter, check if it's the kth character
                if (k == 0 || decodedLength == k)
                    return string("") + inputString[i]; // Return the kth character as a string
                decodedLength--;
            }
        }

        return ""; // Return an empty string if no character is found
    }
};

int main() {
    Solution s;
    cout<<s.decodeAtIndex("a2b3c4d5e6f7g8h9",9);
	return 0;
}
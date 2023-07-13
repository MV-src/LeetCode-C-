#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int res = 0;
        int size = answerKey.size();
        int count = 0;
        int left = 0;
        int lastPos = 0;
        bool check = true;
        queue<int> positions;
        for (int right = 0; right < size; right++) {
            if (answerKey[right] == 'F') {
                count++;
                if(right != 0)positions.push(right);
            }
            if (count == k+1) {
                res = max(right - left, res);
                if (left<size && answerKey[left + 1] == 'T' && check) {
                    left++;
                    count--;
                    check = false; 
                    continue;
                }
                left = positions.front();
                positions.pop();
                count--; 
                check = true;
            }
        }
        if (res == 0) return size;
        count = 0;
        while (!positions.empty()) {
            positions.pop();
        }
        left = 0;
        for (int right = 0; right < size; right++) {
            if (answerKey[right] == 'T') {
                count++;
                if (right != 0)positions.push(right);
            }
            if (count == k + 1) {
                res = max(right - left, res);
                if (left < size && answerKey[left + 1] == 'F' && check) {
                    left++;
                    check = false;
                    count--;
                    continue;
                }
                left = positions.front();
                positions.pop();
                count--;
                check = true;
            }
        }
        if (res == 0) return size;
        return res;
    }
};



class Solution2 {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int maxSize = k;
        unordered_map<char, int> count;
        for (int i = 0; i < k; i++) {
            count[answerKey[i]]++;
        }

        int left = 0;
        for (int right = k; right < answerKey.length(); right++) {
            count[answerKey[right]]++;

            while (min(count['T'], count['F']) > k) {
                count[answerKey[left]]--;
                left++;
            }

            maxSize = max(maxSize, right - left + 1);
        }

        return maxSize;
    }
};

int main() {
    string str = "FFTFTTTFFF";
    Solution s;
    cout<<s.maxConsecutiveAnswers(str, 1);
	return 0;
}
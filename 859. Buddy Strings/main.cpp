#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution2 {
public:
    bool buddyStrings(string s, string goal) {
        int size = s.size();
        int i = 0;
        if(size == 1) return false;
        if (s == goal) {
            string temp = s;
            int tempsize = temp.size();
            while(tempsize) {
                char ch = temp[0];
                temp.erase(temp.begin());
                if (temp.find(ch) != string::npos) {
                    return true;
                }
                tempsize--;
            }
        }
        for (i = 0; i < size; i++) {
            if (s[i] != goal[i]) break;
        }
        vector<int> v;
        for (int j = 0; j < size; j++) {
            if (s[j] == goal[i]) {
                string temp = s;
                swap(temp[j], temp[i]);
                if (temp == goal) return true;
            }
        }

        return false;
    }
};


class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.length();
        if (s == goal) {
            set<char> temp(s.begin(), s.end());
            return temp.size() < goal.size(); // Swapping same characters
        }

        int i = 0;
        int j = n - 1;

        while (i < j && s[i] == goal[i]) {
            i++;
        }

        while (j >= 0 && s[j] == goal[j]) {
            j--;
        }

        if (i < j) {
            swap(s[i], s[j]);
        }

        return s == goal;
    }
};


int main() {
    Solution s;
    cout<<s.buddyStrings("aca", "aca");
    return 0;
}
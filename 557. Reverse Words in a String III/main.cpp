#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string res = "";
        string temp = "";
        bool check = false;
        for (int i = 0;  i< s.size(); i++) {
            if (!check && s[i] == ' ') res += s[i];
            if (s[i] != ' ') {
                temp += s[i];
                check = true;
            }
            if (check && s[i] == ' ') {
                reverse(temp.begin(), temp.end());
                res += temp;
                res += " ";
                temp = "";
                check = false;
            }
        }

        if (check) {
            reverse(temp.begin(), temp.end());
            res += temp;
        }
        return res;
    }
};

int main() {
    Solution s;
    string str = "Let's take LeetCode contest";
    cout<<s.reverseWords(str);
	return 0;
}
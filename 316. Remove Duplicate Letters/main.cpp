#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>
using namespace std;

/*class Solution {
public:
    string fun(string& s,string res, int i, int maximum, map<char, int> letters, set<char> lettersUsed) {
        if (res.size() + (s.size() - i) < maximum) return " ";
        if (res.size() == maximum) return res;
        bool check = false;
        for (auto x : letters) {
            if (lettersUsed.find(x.first) != lettersUsed.end()) continue;
            for (int j = i; j < s.size(); j++) {
                if (s[j] == x.first) {
                    lettersUsed.insert(s[j]);
                    string temp = fun(s,res+s[j], j + 1, maximum, letters, lettersUsed);
                    lettersUsed.erase(s[j]);
                    if (temp == res || temp == " ") continue;
                    return temp;
                }
            }
        }
        return " ";
    }

    string removeDuplicateLetters(string s) {
        map<char, int> letters;
        set<char> lettersUsed;
        for (auto& x : s) letters[x]++;
        int maximum = letters.size();
        return fun(s,"",0,maximum,letters,lettersUsed);
    }
};*/


class Solution {
public:
    std::string removeDuplicateLetters(std::string s) {
        std::stack<char> stack;
        std::unordered_set<char> seen;
        std::unordered_map<char, int> last_occ;
        for (int i = 0; i < s.size(); i++) {
            last_occ[s[i]] = i;
        }

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (seen.find(c) == seen.end()) {
                while (!stack.empty() && c < stack.top() && i < last_occ[stack.top()]) {
                    seen.erase(stack.top());
                    stack.pop();
                }
                seen.insert(c);
                stack.push(c);
            }
        }

        std::string result = "";
        while (!stack.empty()) {
            result = stack.top() + result;
            stack.pop();
        }
        return result;
    }
};

int main() {
    Solution s;
    cout<<s.removeDuplicateLetters("cbacdcbcd");
	return 0;
}
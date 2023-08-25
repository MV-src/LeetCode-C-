#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> res;
        int i = 0;
        while (i < words.size()) {
            string temp = "";
            while (i < words.size()) {
                if ((temp + words[i]).size() > maxWidth) break;
                temp += words[i] + " ";
                i++;
            }
            res.push_back(temp);
        }
        string y = res.back();
        res.pop_back();
        for (auto& x : res) {
            if (x.back() == ' ') x.erase(x.begin()+x.length()-1);
            int spaces = std::count(x.begin(), x.end(), ' ');
            int difference = maxWidth - x.length();
            if (spaces == 0) {
                string t(difference, ' ');
                x += t;
                continue;
            }
            if (difference == 0) continue;
            int spaceDivide = difference / spaces;
            int spaceMod = difference % spaces;
            
            for (int i = 0; i < x.size();i++ ) {
                if (x[i] != ' ') continue;
                int space = spaceDivide;
                if (spaceMod != 0) {
                    space++;
                    spaceMod--;
                }
                string t(space, ' ');
                x.insert(i, t);
                i += t.size();
            }
        }
        if (y.back() == ' ') y.erase(y.begin() + y.length() - 1);
        int diff = maxWidth - y.size();
        y += string(diff, ' ');
        res.push_back(y);
        return res;
    }
};

int main() {
    Solution s;
    vector<string> vec = { "This", "is", "an", "example", "of", "text", "justification." };
    vector<string> temp = s.fullJustify(vec, 16);
	return 0;
}
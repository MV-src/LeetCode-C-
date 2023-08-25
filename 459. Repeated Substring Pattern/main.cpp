#include <iostream>
#include <vector>
#include <string>
using namespace std;

/*class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();
        
        for (int i = 0; i < size/2; i++) {
            string x = "";
            string temp = s.substr(0, i + 1);
            while(x.size()<size) {
                x += temp;
            }
            if (x == s) return true;
        }


        return false;
    }
};*/

/*Best Solution
class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int size = s.size();

        for (int i = 1; i <= size/2; i++) {
            if(size%i == 0){
                string x = "";
                string temp = s.substr(0, i);
                while(x.size()<size) {
                    x += temp;
                }
                if (x == s) return true;
            }
        }


        return false;
    }
};*/

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string t = s + s;
        string x = t.substr(1, t.size() - 2);
        return t.substr(1, t.size() - 2).find(s) != -1;
    }
};

int main() {
    Solution s;
    cout<<s.repeatedSubstringPattern("abcababcabc");
	return 0;
}
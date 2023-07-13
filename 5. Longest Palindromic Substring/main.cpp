#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int size = s.size();
        string result = s.substr(0,1);
        while (!s.empty()) {
            string currLetter = s.substr(0, 1);
            string superTemp = s;
            while (superTemp.size() > 1) {
                size_t curr2 = superTemp.find_last_of(currLetter);
                if (curr2 == string::npos || curr2 == 0) break;
                string tempString = superTemp.substr(0, curr2 + 1);
                string tempString2 = tempString;
                reverse(tempString2.begin(), tempString2.end());
                if (tempString == tempString2) {
                    if (tempString.size() > result.size()) {
                        result = tempString;
                        if (curr2 == s.size() - 1) return result;
                    }
                }
                superTemp = superTemp.substr(0, curr2);
                
            }
            s.erase(0, 1);
        }
        return result;
    }
};


int main()
{
    Solution s;
    cout<<s.longestPalindrome("aacabdkacaa");

	return 0;
}

/*
Best Solution
class Solution {
private:
    bool check(string &s, int i, int j){
        while(i<j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int starting_index = 0;
        int max_len = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(check(s, i, j)){
                    if(j-i+1 > max_len){
                        max_len = j-i+1;
                        starting_index = i;
                    }
                }
            }
        }
        return s.substr(starting_index, max_len);
    }
};


*/
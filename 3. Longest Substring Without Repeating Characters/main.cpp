#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int counter = 0;
        int result = 0;
        int size = s.size();
        unordered_map<char, int> hashmap;
        for (int i = 0; i < size; i++) {
            if (hashmap.find(s[i]) != hashmap.end()) continue;
            hashmap.insert({ s[i], 0});
        }
        for (int i = 0; i < size; i++) {
            for (int j = i;j<size;j++) {
                if (hashmap[s[j]] == 0) {
                    counter++;
                    hashmap[s[j]] = 1;
                }
                else {
                    result = max(result, counter);
                    counter = 0;
                    for (int k = 0; k < size; k++) {
                        hashmap[k] = 0;
                    }
                    break;
                }
            }
        }
        result = max(result, counter);

        return result;
    }
};



int main() {
    Solution s;
    s.lengthOfLongestSubstring("jbpnbwwd");
	return 0;
}

/*
Best Solution
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)return 0;   //if string of length zero comes simply return 0
        unordered_map<char,int> m;   //create map to store frequency,(get to know all unique characters
        int i=0,j=0,ans=INT_MIN;
        while(j<s.length())
        {
            m[s[j]]++;  //increase the frequency of the element as you traverse the string
            if(m.size()==j-i+1)  // whem map size is equal to the window size means suppose window size is 3 and map size is also three that means in map all unique characters are their
            {
                ans = max(ans,j-i+1);  //compare the length of the maximum window size
            }
            else if(m.size()<j-i+1)   //if the map size is less than the window size means there is some duplicate present like window size = 3 and map size = 2 means there is a duplicates
            {
                while(m.size()<j-i+1)  //so till the duplicates are removed completely
                {
                    m[s[i]]--;   //remove the duplicates
                    if(m[s[i]]==0)  //if the frequency becomes zero
                    {
                        m.erase(s[i]);//delete it completely
                    }
                    i++;  //go for next element
                }
            }
             j++;  //go for the next element
        }
        return ans;
    }
};


*/
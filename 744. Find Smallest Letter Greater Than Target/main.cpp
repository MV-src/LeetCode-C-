#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char firstElement = letters[0];
        vector<char> targets = { target };
        while(!letters.empty()) {
            
            if(!lexicographical_compare(letters.begin(), letters.end(), targets.begin(), targets.end())) {
                if (target == letters[0]) {
                    letters.erase(letters.begin());
                    continue;
                }
                return letters.at(0);
            }
            letters.erase(letters.begin());
        }
        return firstElement;
    }
};

class Solution2 {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        for (char n : letters) {
            if (target < n) {
                return n;
            }
        }
        return letters[0];
    }
};


int main() {
    vector<char> v = { 'c','f','j'};
    char target = 'g';
    Solution s;
    cout<< s.nextGreatestLetter(v, target);

	return 0;
}

/*
Application of binary search with O(log(n))

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int low=0;
        int high=letters.size()-1;

        if(letters[0] > target)
          return letters[0];

        else if(target >= letters[letters.size()-1])
        return letters[0];

        char ans;

        while( low <= high)
        {
            int mid=(low+high)/2;

             if(letters[mid] > target){
                 ans = letters[mid];
                 high = mid-1;
             }

             else
             low = mid+1;

        }

        return ans;

    }
};
*/
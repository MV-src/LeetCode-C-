#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> temp;
        while (asteroids != temp) {
            temp = asteroids;
            int i = 0;
            int size = asteroids.size();
            while(size && i<size-1) {
                if (asteroids[i] >= 0 && asteroids[i + 1] < 0) {
                    if (abs(asteroids[i]) > abs(asteroids[i + 1])) {
                        asteroids.erase(asteroids.begin()+i+1);
                    }
                    else if(abs(asteroids[i]) < abs(asteroids[i + 1])) {
                        asteroids.erase(asteroids.begin() + i);
                    }
                    else {
                        asteroids.erase(asteroids.begin() + i);
                        asteroids.erase(asteroids.begin() + i);
                    }
                    i--;
                }
                i++;
                size = asteroids.size();
            }
        }
        return asteroids;
    }
};

/*class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> stk;

        for (int i = 0; i < n; i++) {
            if (stk.empty() || asteroids[i] > 0) {
                stk.push(asteroids[i]);
            }
            else {
                while (!stk.empty() && stk.top() > 0 && stk.top() < abs(asteroids[i])) {
                    stk.pop();
                }

                if (!stk.empty() && stk.top() == abs(asteroids[i])) {
                    stk.pop();
                }
                else {
                    if (stk.empty() || stk.top() < 0) {
                        stk.push(asteroids[i]);
                    }
                }
            }
        }
        vector<int> ans(stk.size(), 0);
        int size = stk.size();
        while (!stk.empty()) {
            ans[--size] = stk.top();
            stk.pop();
        }
        return ans;
    }
};*/

int main() {
    vector<int> v = { 5,10,-5 };
    Solution s;
    s.asteroidCollision(v);
	return 0;
}
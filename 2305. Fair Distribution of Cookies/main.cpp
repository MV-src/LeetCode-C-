#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


class Solution {
public:
    int fun(vector<int>& cookies, int k, int i, int count,int size,vector<int> kids) {
        int result = INT32_MAX;
        bool check = false;
        if (i >= size) return *max_element(kids.begin(), kids.end());
        if ((size - i) < count)return INT32_MAX;
        for (int j = 0; j < k; j++) {
            if (kids[j] == 0) {
                count--;
                check = true;
            }
            kids[j] += cookies[i];
            result = min(fun(cookies, k, i + 1,count,size, kids), result);
            kids[j] -= cookies[i];
            if (check) {
                check = false;
                count++;
            }
        }
        return result;
    }

    int distributeCookies(vector<int>& cookies, int k) {
        vector<int> kids(k,0);
        int size = cookies.size();
        return fun(cookies,k,0,k,size,kids);
    }
};

int main() {
    Solution s;
    vector<int> cookies = { 76265,7826,16834,63341,68901,58882,50651,75609 };
    cout<< s.distributeCookies(cookies, 8);
	return 0;
}
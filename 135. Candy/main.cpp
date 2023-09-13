#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        for (int i = 0; i < ratings.size(); i++) pq.push({ ratings[i], i });
        vector<int> res(ratings.size(), 1);

        while (!pq.empty()) {
            auto x = pq.top();
            pq.pop();
            int i, j;
            i = j = x.second;
            bool check1 = false;
            bool check2 = false;
            while (!check1 && !check2) {
                if ((i >= 1 && ratings[i - 1] > ratings[i]) && res[i - 1] < res[i] + 1) {
                    res[i - 1] = res[i] + 1;
                    i++;
                }
                else check1 = true;
                if (j < ratings.size() - 1 && ratings[j] < ratings[j + 1] && res[j + 1] < res[j] + 1) {
                    res[j + 1] = res[j] + 1;
                    j++;
                }
                else check2 = true;
            }
        }
        int ans = 0;
        for (auto& x : res) ans += x;
        return ans;
    }
};

int main() {
    Solution s;
    vector<int> v = { 0,1,2,1,3,4,0,5,2 };
    cout<<s.candy(v);
	return 0;
}
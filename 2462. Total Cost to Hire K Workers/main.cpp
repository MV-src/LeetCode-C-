#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution2 {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int i = 0;
        int j = costs.size() - 1;
        priority_queue<int, vector<int>, greater<int >> pq1;
        priority_queue<int, vector<int>,greater<int>> pq2;

        long long ans = 0;
        while (k--) {
            while (pq1.size() < candidates && i <= j) {
                pq1.push(costs[i++]);
            }
            while (pq2.size() < candidates && i <= j) {
                pq2.push(costs[j--]);
            }

            int t1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int t2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if (t1 <= t2) {
                ans += t1;
                pq1.pop();
            }
            else {
                ans += t2;
                pq2.pop();
            }
        }
        return ans;
    }
};


/*class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long result = 0;
        int size = costs.size();
        bool cond = true;
        for (int i = 0; i < k; i++) {
            if (candidates >= (size+1)/2) {
                if (cond) {
                    sort(costs.begin(), costs.end());
                    cond = true;
                }
                int temp = costs[0];
                costs.erase(costs.begin());
                result += temp;
            }else {
                int temp1 = *min_element(costs.begin(), costs.begin() + candidates);
                int temp2 = *min_element(costs.end() - candidates, costs.end());
                if (temp1 <= temp2) {
                    auto it = find(costs.begin(), costs.begin() + candidates, temp1);
                    costs.erase(it);
                    result += temp1;
                }
                else {
                    auto it = find(costs.end() - candidates, costs.end(), temp2);
                    costs.erase(it);
                    result += temp2;
                }
            }
            size--;
        }
        return result;
    }
};*/

class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue<int, vector<int>, greater<int>> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        int i = 0;
        int j = costs.size() - 1;
        long long result = 0;
        while (k--) {
            while (pq1.size() < candidates && i <= j) {
                pq1.push(costs[i++]);
            }
            while (pq2.size() < candidates && i <= j) {
                pq2.push(costs[j--]);
            }
            int top1 = pq1.size() > 0 ? pq1.top() : INT_MAX;
            int top2 = pq2.size() > 0 ? pq2.top() : INT_MAX;

            if (top1 <= top2) {
                result += top1;
                pq1.pop();
            }
            else {
                result += top2;
                pq2.pop();
            }
        }
        return result;
    }
};



int main() {
    Solution s;
    vector<int> v = { 17,12,10,2,7,2,11,20,8 };
    s.totalCost(v,3,4);

	return 0;
}
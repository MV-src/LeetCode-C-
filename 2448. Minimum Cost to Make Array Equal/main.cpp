#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
class Solution {
public:
    long long f(vector<int>& A, vector<int>& cost, int x) {
        long long res = 0;
        for (int i = 0; i < A.size(); ++i)
            res += 1L * abs(A[i] - x) * cost[i];
        return res;
    }
    long long minCost(vector<int>& A, vector<int>& cost) {
        long long l = 1, r = 1000000, res = f(A, cost, 1), x;
        while (l < r) {

            x = (l + r) / 2;
            long long y1 = f(A, cost, x), y2 = f(A, cost, x + 1);
            res = min(y1, y2);
            if (y1 < y2)
                r = x;
            else
                l = x + 1;
        }
        return res;
    }
};


int main() {
    Solution s;
    vector<int> v = { 1,3,5,2 };
    vector<int> cost = { 2,3,1,14 };
    s.minCost(v, cost);

	return 0;
}

/*
* Solution with trinary search
* 
* class Solution {
public:
long long f(vector<int>& A, vector<int>& cost, int x) {
long long res = 0;
for (int i = 0; i < A.size(); ++i)
res += 1L * abs(A[i] - x) * cost[i];
return res;
}
long long minCost(vector<int>& A, vector<int>& cost) {
long long l = 1, r = 1000000, res = f(A, cost, 1), x;
while (l < r) {

x = (l + r) / 2;
long long y1 = f(A, cost, x), y2 = f(A, cost, x + 1);
res = min(y1, y2);
if (y1 < y2)
r = x;
else
l = x + 1;
}
return res;
}
};

Solution
class Solution {
public:
    long long f(vector<int>& A, vector<int>& cost, int x) {
        long long res = 0;
        for (int i = 0; i < A.size(); ++i)
            res += 1L * abs(A[i] - x) * cost[i];
            return res;
        }
    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long total=0;
        long long sum=0;
        long long median;
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({nums[i],cost[i]});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<cost.size();i++){
            sum+=v[i].second;
        }
        int i=0;
        while(total<(sum+1)/2 && i<nums.size()){
            total+=v[i].second;
            median=v[i].first;
            i++;
        }
        return f(nums,cost,median);
    }
};

*/
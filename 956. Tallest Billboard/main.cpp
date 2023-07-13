#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <tuple>

using namespace std;
class Solution {
public:
    int fun(vector<int>& rods, int i, int r1, int r2, int size) {
        int result = 0;
        if (r1 == r2 && i >= size) return r1;
        if (i >= size) return 0;
        result = max(fun(rods, i + 1, r1, r2, size), fun(rods, i + 1, r1 + rods[i], r2, size));
        result = max(fun(rods, i + 1, r1, r2 + rods[i], size), result);
        if (r1 == r2) return max(result, r1);
        return result;
    }

    int tallestBillboard(vector<int>& rods) {
        int size = rods.size();
        if (size == 1) return 0;
        sort(rods.begin(), rods.end());
        return fun(rods, 0, 0, 0, size);
    }
};
/*class Solution {
public:
    struct hash_tuple {

        template <class T1, class T2, class T3>

        size_t operator()(
            const tuple<T1, T2, T3>& x)
            const
        {
            return get<0>(x)
                ^ get<1>(x)
                ^ get<2>(x);
        }
    };

    int fun(vector<int>& rods, int i, int r1, int r2, int size, unordered_map<tuple<int, int, int>, int,hash_tuple>& dp) {
        int result = 0;
        if (dp.find(make_tuple(r1,r2,i)) == dp.end()) return dp[make_tuple(r1,r2,i)];
        if (r1 == r2 && i >= size) return dp[make_tuple(r1, r2, i)] = r1;
        if (i >= size) return 0;
        result = max(fun(rods, i + 1, r1, r2, size,dp), fun(rods, i + 1, r1 + rods[i], r2, size,dp));
        result = max(fun(rods, i + 1, r1, r2 + rods[i], size,dp), result);
        if (r1 == r2)
        {
            dp.emplace(make_tuple(r1, r2, i), max(result, r1));
            return result; 
        }
        dp.emplace(make_tuple(r1, r2, i), result);
        return result;
    }

    int tallestBillboard(vector<int>& rods) {
        int size = rods.size();
        if (size == 1) return 0;
        sort(rods.begin(), rods.end());
        unordered_map<tuple<int,int,int>,int,hash_tuple> dp;
        dp.emplace(make_tuple(0,0,0), 0);
        return fun(rods,0,0,0,size,dp);
    }
};*/


int main() {
    Solution s;
    vector<int> v = { 2,2,4,8 };
    cout<<s.tallestBillboard(v);
	return 0;
}


//My first recurisve solution that works without dp :)


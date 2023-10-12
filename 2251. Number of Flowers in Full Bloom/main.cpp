#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

/*class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        sort(flowers.begin(), flowers.end());
        vector<int> res = people;
        sort(people.begin(), people.end());
        int currBloom = 0;
        int j = 0;
        int k = 0;
        unordered_map<int, int> dp;
        vector<int> bloomPeriod(people.back()+1,0);
        for (int i = 1; i < people.back()+1; i++) {
            while (j < flowers.size() && flowers[j][0] == i) {
                currBloom++;
                if(flowers[j][1] + 1 < people.back()+1) bloomPeriod[flowers[j][1] + 1]++;
                j++;
            }
            currBloom -= bloomPeriod[i];
            while (k<people.size() && people[k] == i) {
                dp[i] = currBloom;
                k++;
            }
        }
        for (int i = 0; i < res.size(); i++) {
            res[i] = dp[res[i]];
        }
        return res;
    }
};*/

/*Best Solution*/
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> st, bl; // Initialize vectors to store start and bloom times.
        int n = flowers.size();

        // Extract start and bloom times from the flowers array and store them in separate vectors.
        for (auto i : flowers) {
            int x = i[0];
            int y = i[1];
            st.push_back(x);
            bl.push_back(y);
        }

        // Sort the start and bloom time vectors in ascending order.
        sort(st.begin(), st.end());
        sort(bl.begin(), bl.end());

        vector<int> v; // Initialize a result vector to store bloom statuses.

        // Iterate through each person's bloom time.
        for (int i = 0; i < people.size(); i++) {
            // Calculate the number of flowers blooming at or before the person's bloom time.
            int p = st.size() - (upper_bound(st.begin(), st.end(), people[i]) - st.begin());

            // Calculate the number of flowers blooming at or after the person's bloom time.
            int q = bl.size() - (lower_bound(bl.begin(), bl.end(), people[i]) - bl.begin());

            // Calculate the bloom status for the person and store it in the result vector.
            v.push_back(q - p);
        }

        return v; // Return the vector containing bloom statuses for each person.
    }
};

int main() {
    Solution s;
    vector<vector<int>> v = { {11,11}, {24,46},{3,25},{44,46} };
    vector<int> p = { 1,8,26,7,43,26,1 };
    s.fullBloomFlowers(v, p);
	return 0;
}
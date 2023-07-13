#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> result;
        int size1 = nums1.size();
        int size2 = nums2.size();
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<tuple<int,int,int>>> pq;
        pq.push(make_tuple(nums1[0] + nums2[0], nums1[0], nums2[0]));
        int n = 1;
        int i, j;
        i = j = 0;
        while (n < k && i<size1) {
            while (n < k && j < size2) {
                if(i<size1-1)pq.push(make_tuple(nums1[i + 1] + nums2[j], nums1[i + 1], nums2[j]));
                if(j<size2-1)pq.push(make_tuple(nums1[i] + nums2[j + 1], nums1[i], nums2[j + 1]));
                j++;
                n++;
            }
            i++;
        }
        
        i = 0;
        while (k-- && !pq.empty()) {
            result.push_back(vector<int>(2, -1));
            tuple<int, int, int> tp = pq.top();
            int n1 = get<1>(tp);
            int n2 = get<2>(tp);
            result[i][0] = n1;
            result[i][1] = n2;
            pq.pop();
            i++;
        }
        
        return result;
    }
};

class SolutionBest {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {

        priority_queue<pair<int, pair<int, int>>> pq;
        int n = nums1.size();
        int m = nums2.size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

                int sum = nums1[i] + nums2[j];

                if (pq.size() < k)
                    pq.push({ sum,{nums1[i],nums2[j]} });

                else if (sum < pq.top().first) {

                    pq.pop();
                    pq.push({ sum,{nums1[i],nums2[j]} });
                }

                else
                    break;
            }
        }

        vector<vector<int>> ans;

        while (!pq.empty()) {

            ans.push_back({ pq.top().second.first,pq.top().second.second });
            pq.pop();
        }

        return ans;
    }
};

int main() {
    SolutionBest s;
    vector<int> v1 = { 1,2 };
    vector<int> v2 = { 3 };
    vector<vector<int>> result = s.kSmallestPairs(v1, v2, 3);
    for (int i = 0; i < result.size(); i++) {
        for (int j = 0; j < result[0].size(); j++) {
            cout << result[i][j]<<" ";
        }
        cout << endl;
    }
	return 0;
}
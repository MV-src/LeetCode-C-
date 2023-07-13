#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> result;
        vector<bool> array;
        vector<bool> thereWas;
        for (int i = 0; i < n; i++) {
            array.push_back(false);
            thereWas.push_back(false);
        }
        for (int i = 0; i < edges.size(); i++) {
            array[edges[i][1]] = true;
            thereWas[edges[i][0]] = true;
        }
        for (int i = 0; i < n; i++) {
            if (!array[i] && thereWas[i]) {
                result.push_back(i);
            }
        }
        return result;
    }
};

/*
Best Solution

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> indegree(n, 0);
        for(auto edge : edges)
            indegree[edge[1]]++;

        vector<int> ans;
        for(int i = 0;i < n; i++){
            if(indegree[i]==0)
                ans.push_back(i);
        }

        return ans;
    }
};
*/
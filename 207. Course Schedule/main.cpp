#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    int check(int pos, int numCourses, vector<vector<int>>& prerequisites, vector<int> thisNode, vector<int>& dp, set<int> visited, int& size,set<vector<int>>visitedNodes) {
        visited.insert(thisNode[0]);
        visitedNodes.insert(thisNode);
        if (visited.find(thisNode[1]) != visited.end()) return false;
        if (dp[thisNode[0]] == 1) return true;
        else if (dp[thisNode[0]] == 0) return false;
        for (int i = 0; i < size; i++) {
            if (visitedNodes.find(prerequisites[i]) != visitedNodes.end()) continue;
            if (prerequisites[i][0] == thisNode[1]) {
                if (!check(i, numCourses, prerequisites, prerequisites[i], dp, visited, size,visitedNodes)) {
                    return dp[pos] = false;
                }
            }
        }
        return dp[pos] = true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int size = prerequisites.size();
        set<int> visisted;
        set<vector<int>> visitedNodes;
        vector<int> dp(numCourses,-1);
        for (int i = 0; i < size; i++) {
            if (!check(i,numCourses,prerequisites,prerequisites[i],dp,visisted,size,visitedNodes)) return false;
        }
        return true;
    }
};

/*
Best Solution
class Solution {
public:
   bool detectcycle(vector<vector<int>>&v,int src,vector<int>&rst,vector<int>&vis){
        vis[src]=1;
        rst[src]=1;
        for(auto x:v[src]){
            if(!vis[x]&&detectcycle(v,x,rst,vis)){
                return true;
            }
            else if(rst[x]==1)
            return true;
        }
        rst[src]=0;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>v(numCourses);
        stack<int>s;
        vector<int>vis(numCourses),rst(numCourses);
        for(auto x: prerequisites){
            v[x[1]].push_back(x[0]);
        }
        for(int i=0;i<numCourses;i++){
           if(!vis[i])
           if(detectcycle(v,i,rst,vis))
           return false;
        }

        return true;
    }
};

*/


int main() {
    vector<vector<int>> v = { {1,0},{0,3},{0,2},{3,2},{2,5 },{4,5},{5,6},{2,4} };
    Solution s;
    cout << "test";
    cout<<s.canFinish(7, v);
	return 0;
}
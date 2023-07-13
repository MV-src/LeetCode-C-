#include <iostream>
#include <vector>
#include "Queue.h"
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> hashmap(graph.size(), 0);
        vector<bool> modified(graph.size(), false);
        Queue q;
        q.enqueue(0);
        int before = 0;
        while (!q.isEmpty()) {
            int i = q.dequeue();
            if (hashmap[i] == 0) hashmap[i] = 2;
                for (int j = 0; j < graph[i].size(); j++) {
                    if (hashmap[graph[i][j]] == hashmap[i] && modified[graph[i][j]]) return false;
                    hashmap[graph[i][j]] = -hashmap[i];
                    modified[graph[i][j]] = true;
                    q.enqueue(graph[i][j]);
                }
                before = i;
        }
        return true;
    }
};

int main() {
    vector<vector<int>> edges = { { 1,3 }, { 0, 2 }, { 1, 3 }, { 0, 2 }};

    Solution s;
    std::cout<<s.isBipartite(edges);


}

/*
Best Solution

class Solution {
public:
    bool isBipartite(vector<vector<int>>& gr) {
        int n = gr.size();
        vector<int> colour(n, 0);

        for(int node = 0; node < n; node++){
            if(colour[node] != 0) continue;

            queue<int> q;
            q.push(node);
            colour[node] = 1;

            while(!q.empty()){
                int cur = q.front();
                q.pop();

                for(int ne : gr[cur]){
                    if(colour[ne] == 0){
                        colour[ne] = -colour[cur];
                        q.push(ne);
                    }else if(colour[ne] != -colour[cur]){
                        return false;
                    }
                }
            }
        }

        return true;
    }
};
*/

































/*class Solution {
public:
    bool validColouring(vector<vector<int>>& gr, vector<int>& colour, int node, int col) {
        if (colour[node] != 0)
            return (colour[node] == col);

        colour[node] = col;
        for (int ne : gr[node]) {
            if (!validColouring(gr, colour, ne, -col))
                return false;
        }

        return true;
    }

    bool isBipartite(vector<vector<int>>& gr) {
        int n = gr.size();
        vector<int> colour(n, 0);

        for (int node = 0; node < n; node++) {
            if (colour[node] == 0 && !validColouring(gr, colour, node, 1))
                return false;
        }

        return true;
    }
};*/
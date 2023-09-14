#include <iostream>
#include <vector>
#include <set>
#include <unordered_map>
#include <queue>
using namespace std;

/*class Solution {
public:
    vector<string> fun(string curr, vector<vector<string>>& tickets, set<int> usedTickets) {
        vector<string> res;
        res.push_back(curr);
        vector<pair<string,int>> temp;
        for (int i = 0; i < tickets.size(); i++) {
            if (tickets[i][0] == curr && usedTickets.find(i) == usedTickets.end()) {
                temp.push_back({tickets[i][1], i});
            }
        }

        vector<pair<string,int>> dests;
        for (auto& x : temp) {
            dests.push_back({ x.first,x.second });
        }

        for (int i = 0; i < dests.size(); ++i) {
            for (int j = 0; j <dests.size()-1; ++j) {
                if (dests[j].first > dests[j + 1].first) {
                    auto tempo = dests[j];
                    dests[j] = dests[j + 1];
                    dests[j + 1] = tempo;
                }
            }
        }

        for (auto& x : dests) {
            usedTickets.insert(x.second);
            vector<string> t = fun(x.first, tickets, usedTickets);
            for (auto& x : t) res.push_back(x);
            usedTickets.erase(x.second);
        }
        return res;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        set<int> usedTickets;
        return fun("JFK",tickets,usedTickets);
    }
};*/


/*BEST SOLUTION*/
class Solution {
private:
    // Create an adjacency list to represent the flights
    unordered_map<string, vector<string>> flightGraph;

    // Store the final itinerary
    vector<string> itinerary;

public:

    // Depth-First Search to traverse the flight itinerary
    void dfs(string airport) {
        vector<string>& destinations = flightGraph[airport];

        // Visit destinations in lexical order
        while (!destinations.empty()) {
            string nextDestination = destinations.back();
            destinations.pop_back();
            dfs(nextDestination);
        }

        // Add the current airport to the itinerary after visiting all destinations
        itinerary.push_back(airport);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        // Populate the flight graph using ticket information
        for (int i = 0; i < tickets.size(); i++) {
            string from = tickets[i][0];
            string to = tickets[i][1];

            flightGraph[from].push_back(to);
        }

        // Sort destinations in reverse order to visit lexical smaller destinations first
        for (auto& entry : flightGraph) {
            sort(entry.second.rbegin(), entry.second.rend());
        }

        // Start the DFS from the JFK airport
        dfs("JFK");

        // Reverse the itinerary to get the correct order
        reverse(itinerary.begin(), itinerary.end());

        return itinerary;
    }
};

int main() {
    vector<vector<string>> v{ {"JFK","SFO"}, {"JFK","ATL"}, {"SFO","ATL"}, {"ATL","JFK"}, {"ATL","SFO"} };
    Solution s;
    s.findItinerary(v);

	return 0;
}
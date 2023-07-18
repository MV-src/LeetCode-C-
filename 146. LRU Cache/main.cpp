#include <iostream>
#include <queue>
#include <map>
using namespace std;

bool cmp(pair<int, pair<int,int>>& a,
    pair<int, pair<int, int>>& b)
{
    return a.second.second < b.second.second;
}

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator () (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        // Mainly for demonstration purposes, i.e. works but is overly simple
        // In the real world, use sth. like boost.hash_combine
        return h1 ^ h2;
    }
};

class LRUCache {
    map<int, pair<int,int>,pair_hash> dp;
    int capacity;
    int count;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        count = 0;
    }

    int get(int key) {
        if (dp.find(key) != dp.end()) {
            dp[key].second++;
            return dp[key].first;
        }
        return -1;
    }

    void put(int key, int value) {
        if (dp.find(key) != dp.end()) {
            dp[key] = make_pair(value,dp[key].second++);
        }
        if (count == capacity) {
            sort(dp.begin(), dp.end(), cmp);
            dp.erase(dp.begin());
            count--;
        }
        dp.insert(make_pair(key, make_pair(value,0)));
        count++;
    }


};

int main() {
	return 0;
}
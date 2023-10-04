#include <iostream>
#include <vector>
using namespace std;

class MyHashMap {
public:
    vector<int> hs;
    MyHashMap() {
        hs = vector<int>(1e6+1, -1);
    }

    void put(int key, int value) {
        hs[key] = value;
    }

    int get(int key) {
        return hs[key];
    }

    void remove(int key) {
        hs[key] = -1;
    }
};

int main() {

	return 0;
}
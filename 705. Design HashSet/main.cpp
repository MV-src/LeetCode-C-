#include <iostream>
#include <vector>

using namespace std;
class MyHashSet {
public:
    vector<int> v;
    MyHashSet() {
        v.resize(10e6, 0);
    }

    void add(int key) {
        v[key] = 1;
    }

    void remove(int key) {
        v[key] = 0;
    }

    bool contains(int key) {
        return v[key];
    }
};

int main() {

	return 0;
}
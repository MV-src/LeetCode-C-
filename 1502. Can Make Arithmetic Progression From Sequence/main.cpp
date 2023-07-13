#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& arr) {
        int siz = arr.size();
        sort(arr.begin(), arr.end());
        int difference = arr[1] - arr[0];
        for (int i = 1; i < siz - 1; i++) {
            if (difference != arr[i + 1] - arr[i]) {
                return false;
            }
        }
        return true;
    }
};

int main() {

	return 0;
}
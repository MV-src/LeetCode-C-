#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    bool winnerOfGame(string colors) {
        int alice = 0;
        int bob = 0;
        bool res = false;
        for (int i = 1; i < colors.size()-1; i++) {
            if (colors[i - 1] == 'A' && colors[i] == 'A' && colors[i + 1] == 'A') alice++;
            if (colors[i - 1] == 'B' && colors[i] == 'B' && colors[i + 1] == 'B') bob++;
        }
        res = alice > bob ? true : false;
        return res;
    }
};

/*Best Solution*/
/*class Solution {
public:
    bool winnerOfGame(string colors) {
        map<char, int> c;
        for (auto it = colors.begin(); it != colors.end(); ) {
            char x = *it;
            auto t = it;
            while (t != colors.end() && *t == x) {
                t++;
            }
            c[x] += max(int(distance(it, t) - 2), 0);
            it = t;
        }

        if (c['A'] > c['B']) {
            return true;
        }
        return false;
    }
};*/

int main() {
    Solution s;
    s.winnerOfGame("ABBBBBBBAAA");
	return 0;
}
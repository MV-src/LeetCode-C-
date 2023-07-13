#include <iostream>
#include <bitset>
using namespace std;



class Solution {
public:
    int minFlips(int a, int b, int c) {
		/*auto fun = [](int n) {
			int x = 0;
			while (true) {
				if ((double)n / pow(2, x) < 1) return x;
				x++;
			}

			return -1;
		};
		int maximum = max(a, b);
		maximum = max(maximum, c);
		int size = fun(maximum);*/
		int result = 0;
		bitset<32> newA(a);
		bitset<32> newB(b);
		bitset<32> newC(c);

		for (int i = 0; i < 32; i++) {

			if (newC.test(i) == 0) {
				if (newA.test(i) != 0 && newB.test(i) != 0) {
					result+=2;
				}
				else if (newA.test(i) != 0 || newB.test(i) != 0) {
					result++;
				}
			}
			else {
				if (newA.test(i) == 0 && newB.test(i) == 0) {
					result++;
				}
			}
		}
		return result;
    }
};

int main() {
	Solution s;
	s.minFlips(1, 72, 1);
	return 0;
	
}

/*
Best solution using bitwise operations
class Solution {
public:
	int minFlips(int a, int b, int c) {
		int flips = 0;
		while (a > 0 || b > 0 || c > 0) {
			int bitA = a & 1;
			int bitB = b & 1;
			int bitC = c & 1;

			if (bitC == 0) {
				flips += (bitA + bitB);
			} else {
				if (bitA == 0 && bitB == 0) {
					flips += 1;
				}
			}

			a >>= 1; shifting right from one position
			b >>= 1;
			c >>= 1;
		}

		return flips;
	}
};

Another solution with XOR application
class Solution {
public:
	int minFlips(int a, int b, int c) {
		return __builtin_popcount((a|b)^c) + __builtin_popcount(a & b & (a|b)^c));
	}
};

*/
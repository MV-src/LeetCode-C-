#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
	int fun(vector<int>& stoneValue, int pos) {
		static vector<int> dp;
		if (pos == stoneValue.size()-1) return stoneValue[pos];
		if (dp[pos] != -1) return dp[pos];
		for (int i = 0; i < 3; i++) {
			int n = fun(stoneValue, ) - fun();
		}

		
		return n;
	}

	string stoneGameIII(vector<int>& stoneValue) {
		string s = "";
		
		int n = fun();
		
		if (n> 0) {
			s = "Alice";
		}
		else if(n<0){
			s = "Bob";
		}
		else {
			s = "Tie";
		}

		return s;
	}
};

int main() {
	vector<int> v = { 1,2,3,7 };

	return 0;
}

/*
class Solution {
public:
	string stoneGameIII(vector<int>& stoneValue)
	{
	   int n = stoneValue.size();
	   vector<int> dp(3, 0);

	   for (int i = n - 1; i >= 0; i--) {
			int takeOne = stoneValue[i] - dp[(i + 1) % 3];

			int takeTwo = INT_MIN;
			if (i + 1 < n) takeTwo = stoneValue[i] + stoneValue[i + 1] - dp[(i + 2) % 3];

			int takeThree = INT_MIN;
			if (i + 2 < n) takeThree = stoneValue[i] + stoneValue[i + 1] + stoneValue[i + 2] - dp[(i + 3) % 3];

			dp[i % 3] = max({takeOne, takeTwo, takeThree});
		}

	   int value = dp[0];
	   if(value > 0)
		   return "Alice";
		else if(value  < 0)
			return "Bob";
		else
			return "Tie";
	}
};

*/
#include <iostream>
#include <vector>
using namespace std;
class Solution {

public:

    bool checkStraightLine(vector<vector<int>>& coordinates) {
        bool result = true;
        int length = coordinates.size();
        for (int i = 0; i < length; i++) {
            if (coordinates[0][0] == coordinates[i][0]) {
                result = true;
            }
            else {
                result = false;
                break;
            }
        }
        if (result) return result;
        for (int i = 0; i < length; i++) {
            if (coordinates[0][0] == coordinates[i][1]) {
                result = true;
            }
            else {
                result = false;
                break;
            }
        }
        if (result) return result;
        double m = 0; //2
        double q = 0; //-1
        m = (double)(coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        q = (double)coordinates[0][1] - (m * coordinates[0][0]);
        result = true;
        for (int i = 2; i < length; i++) {
            if (coordinates[i][1] == (m * coordinates[i][0] + q)) {
                result = true;
            }
            else {
                result = false;
                break;
            }
        }
        return result;
    }
};


int main() {

	return 0;
}

/*
Best Solution Using Straight Line Formula Based On Two Points;
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x0 = coordinates[0][0];
        int y0 = coordinates[0][1];
        int x1 = coordinates[1][0];
        int y1 = coordinates[1][1];

        for (int i = 2; i < coordinates.size(); i++) {
            int x = coordinates[i][0];
            int y = coordinates[i][1];
            if ((x - x0) * (y1 - y0) != (y - y0) * (x1 - x0)) {
                return false;
            }
        }

        return true;
    }
};
*/
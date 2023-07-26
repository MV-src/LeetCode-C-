#include <iostream>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*class Solution {
public:
    int BS(vector<int> dist, double hour) {
        int l = 0;
        int h = 1e7+1;
        int mid = 0;
        while (l < h) {
            mid = (l + h) / 2;
            if (fun(0, mid, 0, dist, hour, dist.size())==INT32_MAX) {
                l = mid+1;
            }
            else {
                h = mid-1;
            }
            
        }
        return mid;
    }

    int fun(double totalTime, int currSpeed,int i, vector<int>& dist, double hour, int size) {
        if (totalTime > hour) return INT32_MAX;
        if (i >= size) return currSpeed;
        if (!(totalTime == floor(totalTime))) totalTime = ceil(totalTime);
        totalTime += (double)dist[i]/currSpeed;
        return fun(totalTime, currSpeed, i + 1, dist, hour, size);
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int size = dist.size();
        int res = 0;
        int maxSpeed = BS(dist,hour);
        
        if (size > hour +1) return -1;
        for (int i = 1; i < maxSpeed+1; i++) {
            res = fun(0, i, 0, dist, hour, dist.size());
            if (res != INT32_MAX) break;
        }
        if (res == INT32_MAX) return -1;
        return res;
    }
};*/

class Solution {
public:
    double timeRequired(vector<int>& dist, int speed) {
        double time = 0.0;
        for (int i = 0; i < dist.size(); i++) {
            double t = (double)dist[i] / (double)speed;
            // Round off to the next integer, if not the last ride.
            time += (i == dist.size() - 1 ? t : ceil(t));
        }
        return time;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {
        int left = 1;
        int right = 1e7;
        int minSpeed = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            // Move to the left half.
            if (timeRequired(dist, mid) <= hour) {
                minSpeed = mid;
                right = mid - 1;
            }
            else {
                // Move to the right half.
                left = mid + 1;
            }
        }
        return minSpeed;
    }
};

int main() {
    Solution s;
    vector <int> v = { 1,1,100000 };
    cout<<s.minSpeedOnTime(v, 2.01);
    return 0;
}
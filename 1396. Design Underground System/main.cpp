#include <iostream>
#include <vector>
using namespace std;
class User {
public:
    int id;
    string stationName;
    int t;
    User(int id, string stationName, int t) {
        this->id = id;
        this->stationName = stationName;
        this->t = t;
    }

};

class Stations {
public:
    int sumTime;
    int nTimes;
    string startStation;
    string endStation;
    double averageTime;

    Stations(string startStation, string endStation) {
        sumTime = 0;
        averageTime = 0;
        nTimes = 0;
        this->startStation = startStation;
        this->endStation = endStation;
    }

    void calculateAverage(int n) {
        sumTime += n;
        nTimes++;
        averageTime = (double)sumTime / nTimes;
    }
};

class UndergroundSystem {
public:
    vector<Stations> sta;
    vector<User> users;
    UndergroundSystem() {

    }

    void checkIn(int id, string stationName, int t) {
        User s(id, stationName, t);
        users.push_back(s);
    }

    void checkOut(int id, string stationName, int t) {
        int i = 0;
        for (i = 0; i < users.size(); i++) {
            if (users[i].id == id) break;
        }
        bool flag = false;
        int j = 0;
        for (j = 0; j < sta.size(); j++) {
            if (sta[j].startStation == users[i].stationName && sta[j].endStation == stationName) {
                flag = true;
                break;
            }
        }
        double diffTime = (double)(t - users[i].t);
        if (flag) {
            sta[j].calculateAverage(diffTime);
        }
        else {
            Stations s(users[i].stationName, stationName);
            s.calculateAverage(diffTime);
            sta.push_back(s);
        }
        auto c = users.begin();
        for (int k = 0; k < i; k++) {
            c++;
        }
        users.erase(c);
    }

    double getAverageTime(string startStation, string endStation) {
        for (int i = 0; i < sta.size(); i++) {
            if (sta[i].startStation == startStation && sta[i].endStation == endStation) {
                return sta[i].averageTime;
            }
        }
        return -1;
    }
};

int main() {

	return 0;
}

/*
Best answer using unordered_hashmap
class UndergroundSystem {
public:
        // id -> {station name,time}
        unordered_map<int,pair<string,int>>checkInStation;

        // Route -> {total time,count}
        unordered_map<string,pair<int,int>> checkOutStation;

    UndergroundSystem() {
    }

    void checkIn(int id, string stationName, int t) {
          checkInStation[id] = {stationName,t};
    }

    void checkOut(int id, string stationName, int t) {

          auto cIn = checkInStation[id];
           checkInStation.erase(id);

           string route = cIn.first + "_" + stationName;

           checkOutStation[route].first += t - cIn.second;
           checkOutStation[route].second += 1;
    }

    double getAverageTime(string startStation, string endStation) {

           string route  = startStation + "_" + endStation;
           auto time = checkOutStation[route];

        return (double)time.first/time.second;
    }
};
*/
#include <iostream>
class ParkingSystem {
public:
    int big = 0;
    int medium = 0;
    int small = 0;
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
    }

    bool addCar(int carType) {
        bool result = false;
        if (carType == 1 && big > 0) {
            big--;
            result = true;
        }
        else if (carType == 2 && medium > 0) {
            medium--;
            result = true;
        }
        else if (carType == 3 && small > 0) {
            small--;
            result = true;
        }
        return result;
    }
};

int main() {

	return 0;
}

/*
usage of an array

class ParkingSystem {
private:
    int spots[3];

public:
    ParkingSystem(int big, int medium, int small) {
        spots[0] = big;
        spots[1] = medium;
        spots[2] = small;
    }

    bool addCar(int carType) {
        if (spots[carType - 1] > 0) {
            spots[carType - 1]--;
            return true;
        } else {
            return false;
        }
    }
};
*/
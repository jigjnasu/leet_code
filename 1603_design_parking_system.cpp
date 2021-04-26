/*
  LeetCode.com
  Problem No: 1603
  Problem: Design Parking System
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 16/04/2021
*/

#include <bits/stdc++.h>

class ParkingSystem {
public:
    ParkingSystem(int big, int medium, int small) {
        s = {big, medium, small};
    }

    bool addCar(int carType) {
        return s[carType - 1]-- > 0;
    }

private:
    std::vector<int> s;
};

int main() {
    ParkingSystem ps(1, 1, 0);
    std::vector<int> q = {1, 2, 3, 1};
    for (int s : q)
        printf("%d ", ps.addCar(s));
    printf("\n");

    return 0;
}

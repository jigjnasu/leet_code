/*
  Leetcode.com
  Problem No : 1845
  Problem : Seat Reservation Manager
  Author : cpp.rakesh@gmail.com
  Date : 11/05/2021
*/

#include <bits/stdc++.h>

class SeatManager {
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; ++i)
            pq.push(i);
    }

    int reserve() {
        int res = pq.top();
        pq.pop();
        return res;
    }

    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }

private:
    std::priority_queue<int, std::vector<int>, std::greater<int>> pq;
};

void test_1() {
    SeatManager sm(5);
    printf("reserve   ==> [%d]\n", sm.reserve());
    printf("reserve   ==> [%d]\n", sm.reserve());
    sm.unreserve(2);
    printf("unreserve ==> [%d]\n", 2);
    printf("reserve   ==> [%d]\n", sm.reserve());
    printf("reserve   ==> [%d]\n", sm.reserve());
    printf("reserve   ==> [%d]\n", sm.reserve());
    printf("reserve   ==> [%d]\n", sm.reserve());
    sm.unreserve(5);
    printf("unreserve ==> [%d]\n", 5);
}

int main() {
    test_1();

    return 0;
}

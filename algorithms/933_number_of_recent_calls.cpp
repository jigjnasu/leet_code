/*
  Leetcode.com
  Problem No : 933
  Problem : Number of Recent Calls
  Author : cpp.rakesh@gmail.com
  Date: 26/04/2021
*/

#include <bits/stdc++.h>

class RecentCounter {
public:
    RecentCounter() {
        list.clear();
    }

    int ping(int t) {
        list.push_back(t);
        while (list.front() < t - 3000)
            list.pop_front();
        return static_cast<int>(list.size());
    }

    std::list<int> list;
};

int main() {
    RecentCounter rc;
    printf("%d ", rc.ping(1));
    printf("%d ", rc.ping(100));
    printf("%d ", rc.ping(3001));
    printf("%d ", rc.ping(3002));
    printf("\n");

    return 0;
}

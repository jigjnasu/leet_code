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
        std::queue<int> t;
        std::swap(q, t);
    }

    int ping(int t) {
        q.push(t);
        while (q.front() < t - 3000)
            q.pop();
        return static_cast<int>(q.size());
    }

    std::queue<int> q;
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

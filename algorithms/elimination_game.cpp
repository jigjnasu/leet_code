/*
  Solution for Elimination game
  Author: cpp.rakesh@gmail.com
  09/08/2019
*/

#include <bits/stdc++.h>

class Solution {
public:
    int lastRemaining(int n) {
        int count = 1, base = 1, first = 1;
        int last  = n;

        while (n > 1) {
            if (count & 1) {
                first += base;
                if (n & 1)
                    last -= base;
            } else {
                last -= base;
                if (n & 1)
                    first += base;
            }

            n >>= 1;
            ++count;
            base <<= 1;
        }

        return first;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.lastRemaining(9));

    return 0;
}

/*
  LeetCode.com
  Solution for Binary Number with Alternating Bits
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 11/03/2018
 */

#include <bits/stdc++.h>

using namespace std;

const vector<bool> prime = {0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0};

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        int c = 0;
        for (int i = L; i <= R; ++i)
            c += prime[__builtin_popcount(i)];

        return c;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.countPrimeSetBits(289098, 296294));
    return 0;
}

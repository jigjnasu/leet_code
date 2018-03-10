/*
  LeetCode.com
  Solution for Binary Number with Alternating Bits
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 11/03/2018
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int a = n % 2;
        n /=2 ;
        while (n) {
            if (a == n % 2)
                return false;
            a = n % 2;
            n /= 2;
        }

        return true;
    }
};

int main() {
    Solution s;
    int n = 10;
    printf("%d\n", s.hasAlternatingBits(n));

    return 0;
}

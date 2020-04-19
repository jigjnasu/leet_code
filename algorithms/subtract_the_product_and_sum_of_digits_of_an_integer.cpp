/*
  LeetCode.com
  Solution for Subtract the product and sum of digits of an integer
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 20/04/2020
*/

#include <bits/stdc++.h>

class Solution {
public:
    int subtractProductAndSum(int n) {
        int p = 1;
        int s = 0;
        while (n) {
            const int t = n % 10;
            p *= t;
            s += t;
            n /= 10;
        }

        return p - s;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.subtractProductAndSum(234));
    printf("%d\n", s.subtractProductAndSum(4421));

    return 0;
}

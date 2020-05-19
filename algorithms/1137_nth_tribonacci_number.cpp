/*
  Leetcode.com
  Problem No: 1137
  Problem: Nth tribonacci number
  Author: cpp.rakesh@gmail.com
  Date: 08/08/2019
*/

#include <bits/stdc++.h>

class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n == 1 || n == 2) return 1;

        int a = 0;
        int b = 1;
        int c = 1;
        int i = 3;
        while (i <= n) {
            const int t = a + b + c;
            a = b;
            b = c;
            c = t;
            ++i;
        }

        return c;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.tribonacci(4));
    printf("%d\n", s.tribonacci(25));

    return 0;
}

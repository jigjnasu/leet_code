/*
  LeetCode.com
  Solution for Fibonacci number
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 13/08/2019
 */

#include <bits/stdc++.h>

class Solution {
public:
    int fib(int N) {
        if (N == 0)
            return 0;
        if (N == 1)
            return 1;

        int a = 0;
        int b = 1;
        for (int i = 2; i <= N; ++i) {
            const int c = a + b;
            a = b;
            b = c;
        }

        return b;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.fib(2));
    printf("%d\n", s.fib(3));
    printf("%d\n", s.fib(4));

    return 0;
}

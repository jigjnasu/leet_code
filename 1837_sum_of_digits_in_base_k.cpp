/*
  Leetcode.com
  Problem No: 1837
  Problem: Sum of Digits in Base K
  Author: cpp.rakesh@gmail.com
  Date: 18/06/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int sumBase(int n, int k) {
        int sum = 0;
        while (n) {
            sum += n % k;
            n /= k;
        }
        return sum;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.sumBase(34, 6));
    printf("%d\n", s.sumBase(10, 10));
    printf("%d\n", s.sumBase(42, 2));
    return 0;
}

/*
  LeetCode.com
  Problem No: 1551
  Problem: Minimum Operations to Make Array Equal
  Rakesh Kumar
  Date: 26/03/2021
*/

#include <cstdio>

class Solution {
public:
    int minOperations(int n) {
        if (n & 1) {
            n >>= 1;
            return (n * (4 + (n - 1) * 2)) >> 1;
        } else {
            n >>= 1;
            return (n * (2 + (n - 1) * 2)) >> 1;
        }
    }
};

int main() {
    Solution s;
    printf("%d\n", s.minOperations(6));

    return 0;
}

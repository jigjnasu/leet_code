/*
  LeetCode.com
  Problem No: 1486
  Problem: XOR Operation in an Array
  Rakesh Kumar
  Date: 17/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int xorOperation(int n, int start) {
        int res = start;
        for (int i = 1; i < n; ++i)
            res ^= start + (i << 1);
        return res;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.xorOperation(5, 0));
    printf("%d\n", s.xorOperation(4, 3));
    printf("%d\n", s.xorOperation(1, 7));
    printf("%d\n", s.xorOperation(10, 5));

    return 0;
}


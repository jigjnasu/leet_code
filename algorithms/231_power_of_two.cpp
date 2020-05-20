/*
  LeetCode.com
  Problem No: 231
  Problem: Power of Two
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Nov 18th, 2016
 */

#include <cstdio>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && !(n & (n - 1));
    }
};

int main() {
    Solution s;
    for (int i = 1; i < 100; ++i)
        if (s.isPowerOfTwo(i))
            printf("[%8d] is power of 2\n", i);

    return 0;
}

/*
  Leetcode.com
  Problem No: 191
  Problem: Number of 1 Bits
  Author: cpp.rakesh@gmail.com
  Date: Nov 18th, 2016
*/

#include <cstdio>
#include <stdint.h>

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int bits = 0;
        for (int i = 0; i < 32; ++i)
            if ((1 << i) & n)
                ++bits;

        return bits;
    }
};

int main() {
    Solution s;
    printf("number of on bits == [%d]\n", s.hammingWeight(32));
    return 0;
}

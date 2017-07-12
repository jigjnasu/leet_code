/*
  Solution for Reverse Bits
  Author: cpp.rakesh@gmail.com
  11/07/2017
*/

#include <cstdio>

class Solution {
public:
    unsigned int reverseBits(unsigned int n) {
        unsigned int m = 0;
        for (int i = 0; i < 32; ++i) {
            m <<= 1;
            m |= n & 1;
            n >>= 1;
        }

        return m;
    }
};

int main() {
    unsigned int n = 12;
    Solution s;
    printf("%u\n", s.reverseBits(n));

    return 0;
}

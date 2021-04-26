/*
  Leetcode.com
  Problem No: 476
  Problem: Number Complement
  Author: cpp.rakesh@gmail.com
  Date: Feb 7th 18th, 2017
*/

#include <cstdio>

class Solution {
public:
    int findComplement(int n) {
        unsigned int mask = ~0;

        while (n & mask)
            mask <<= 1;

        return ~n & ~mask;
    }
};

int main() {
    Solution s;
    int n = 5;
    printf("Complement of [%d] == [%d]\n", n, s.findComplement(n));
    return 0;
}

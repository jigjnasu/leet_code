/*
  LeetCode.com
  Problem No: 461
  Problem: Hamming Distancd
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Nov 28th, 2016
 */

#include <cstdio>
#include <cmath>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int t = x ^ y;
        int r = 0;
        while (t > 0) {
            r+= t & 1;
            t >>= 1;
        }

        return r;
    }
};

int main() {
    Solution s;
    const int x = 7;
    const int y = 15;
    printf("Hamming distance between [%d] and [%d] == [%d]\n", x, y, s.hammingDistance(x, y));

    return 0;
}

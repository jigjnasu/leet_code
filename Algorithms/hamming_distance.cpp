/*
  LeetCode.com
  Solution for Hamming Distancd
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Nov 28th, 2016
 */

#include <cstdio>
#include <cmath>

class Solution {
public:
    int hammingDistance(int x, int y) {
        int count = 0;
        for (int i = 0; i < 32; ++i)
            if (((1 << i) & x) != ((1 << i) & y))
                ++count;

        return count;
    }
};

int main() {
    Solution s;
    const int x = 7;
    const int y = 15;
    printf("Hamming distance between [%d] and [%d] == [%d]\n", x, y, s.hammingDistance(x, y));
    
    return 0;
}

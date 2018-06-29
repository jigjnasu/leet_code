/*
  LeetCode.com
  Solution for Power Of Three
  Rakesh Kumar, cpp-rakesh(at)gmail.com
  Date: Jan 17th, 2017
 */

#include <cstdio>
#include <cmath>
#include <cstdlib>

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n <= 0)
            return false;
        return (static_cast<int>(std::pow(3, 19)) % n) == 0;
    }

    
};

int main() {
    Solution s;
    int n = 125;
    if (s.isPowerOfThree(n))
        printf("[%d] is a power of three\n", n);
    else
        printf("[%d] is not a power of three\n", n);

    return 0;
}

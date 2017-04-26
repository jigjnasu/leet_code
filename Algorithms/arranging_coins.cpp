/*
  LeetCode.com
  Solution for Arranging Coins.
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 26/04/2017
*/

#include <cstdio>
#include <cmath>

/*
  Let's find out the soution by Mathematics.
  As we know sum of positive n numbers = floor((n (n + 1)) / 2).
  Using discrement formula to get n.
  -b +- (sqrt(b ^ 2 - 4ac)) / 2a
  Let's use this value to find n.
  And that is the answer.
 */

class Solution {
public:
    int arrangeCoins(int n) {
        return static_cast<int>(-1 + std::sqrt(1 + 8 * static_cast<double>(n))) >> 1;
    }
};


int main() {
    Solution solution;
    const int n = 1804289383;
    printf("Complete rows == [%d] for [%d]\n", solution.arrangeCoins(n), n);

    return 0;
}

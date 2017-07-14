/*
  Solution for Counting Bits
  Author: cpp.rakesh@gmail.com
  14/07/2017
*/

#include <cstdio>
#include <vector>

class Solution {
public:
    std::vector<int> countBits(int num) {
        std::vector<int> ones(num + 1, 0);
        for (int i = 1; i <= num; ++i)
            ones[i] = ones[i >> 1] + (1 & i);

        return ones;
    }
};

int main() {
    Solution s;
    const std::vector<int> bits = s.countBits(300);
    for (std::size_t i = 0; i < bits.size(); ++i)
        printf("%d ", bits[i]);
    printf("\n");

    return 0;
}

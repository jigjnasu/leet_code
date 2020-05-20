/*
  Leetcode.com
  Problem No: 260
  Problem: Single Number III
  Author: cpp.rakesh@gmail.com
  14/07/2017
*/

#include <cstdio>
#include <vector>

class Solution {
public:
    std::vector<int> singleNumber(std::vector<int>& nums) {
        std::vector<int> result(2, 0);
        int bits = 0;
        for (std::size_t i = 0; i < nums.size(); ++i)
            bits ^= nums[i];

        bits &= -bits;

        for (std::size_t i = 0; i < nums.size(); ++i)
            if (nums[i] & bits)
                result[0] ^= nums[i];
            else
                result[1] ^= nums[i];

        return result;
    }
};

int main() {
    Solution s;
    std::vector<int> n = {1, 2, 1, 3, 2, 5};
    const std::vector<int> r = s.singleNumber(n);
    printf("%d %d\n", r[0], r[1]);

    return 0;
}

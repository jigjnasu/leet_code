/*
  Solution for Array Partition I
  Author: cpp.rakesh@gmail.com
  14/07/2017
*/

#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
public:
    int arrayPairSum(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        int sum = 0;
        for (std::size_t i = 1; i < nums.size(); i += 2)
            sum += m_min(nums[i], nums[i - 1]);

        return sum;
    }

private:
    int m_min(int a, int b) const {
        return a < b ? a : b;
    }
};

int main() {
    Solution s;
    std::vector<int> nums = {1, 3, 4, 2};
    printf("%d\n", s.arrayPairSum(nums));

    return 0;
}

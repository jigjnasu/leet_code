/*
  LeetCode.com
  Problem Number: 217
  Problem: Contains Duplicate.
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 26/04/2017
*/

#include <cstdio>
#include <vector>
#include <algorithm>

class Solution {
public:
    bool containsDuplicate(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());

        for (std::size_t i = 1; i <nums.size(); ++i)
            if (nums[i] == nums[i - 1])
                return true;

        return false;
    }
};

int main() {
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8};
    Solution solution;
    printf("%d\n", solution.containsDuplicate(nums));

    return 0;
}

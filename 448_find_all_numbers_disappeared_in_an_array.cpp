/*
  LeetCode.com
  Problem No: 448
  Problem: Find all numbers disappeared in an array
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: March 8th, 2017
*/

#include <cstdio>
#include <vector>
#include <cstdlib>

class Solution {
public:
    std::vector<int> findDisappearedNumbers(std::vector<int>& nums) {
        for (std::size_t i = 0; i < nums.size(); ++i)
            if (nums[std::abs(nums[i]) - 1] > 0)
                nums[std::abs(nums[i]) - 1] *= -1;

        std::vector<int> result;
        for (std::size_t i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)
                result.push_back(i + 1);
        return result;
    }
};

int main() {
    std::vector<int> a = {4,3,2,7,8,2,3,1};
    Solution sol;

    const std::vector<int> result = sol.findDisappearedNumbers(a);

    for (std::size_t i = 0; i < result.size(); ++i)
        printf("%d ", result[i]);
    printf("\n");

    return 0;
}

/*
  Leetcode.com
  Problem No: 1827
  Problem: Minimum Operations to Make the Array Increasing
  Author: cpp.rakesh@gmail.com
  Date: 19/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int minOperations(std::vector<int>& nums) {
        int h = nums[0];
        int t = 0;
        for (std::size_t i = 1; i < nums.size(); ++i) {
            t += std::max(0, h + 1 - nums[i]);
            h = std::max(nums[i], h + 1);
        }
        return t;
    }
};

int main() {
    Solution s;
    std::vector<int> v1 = {1, 1, 1};
    printf("%d\n", s.minOperations(v1));

    std::vector<int> v2 = {1,5,2,4,1};
    printf("%d\n", s.minOperations(v2));

    std::vector<int> v3 = {8};
    printf("%d\n", s.minOperations(v3));

    return 0;
}

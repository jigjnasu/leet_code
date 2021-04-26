/*
  LeetCode.com
  Problem No: 1512
  Problem: Number of Good Pairs
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 16/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int numIdenticalPairs(std::vector<int>& nums) {
        int t = 0;
        for (std::size_t i = 0; i < nums.size() - 1; ++i)
            for (std::size_t j = i + 1; j < nums.size(); ++j)
                if (nums[i] == nums[j])
                    ++t;
        return t;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {1,2,3,1,1,3};
    printf("%d\n", s.numIdenticalPairs(v));

    return 0;
}

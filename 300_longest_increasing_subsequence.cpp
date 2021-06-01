/*
  LeetCode.com
  Problem No: 300
  Problem: Longest Increasing Subsequence
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 01/06/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int lengthOfLIS(std::vector<int>& nums) {
        std::vector<int> res;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
            if (it == res.end()) res.push_back(nums[i]);
            else *it = nums[i];
        }
        return static_cast<int>(res.size());
    }
};

int main() {
    Solution s;
    std::vector<int> v = {10,9,2,5,3,7,101,18};
    printf("%d\n", s.lengthOfLIS(v));

    v = {0,1,0,3,2,3};
    printf("%d\n", s.lengthOfLIS(v));

    v = {7,7,7,7,7,7,7,7,7,7};
    printf("%d\n", s.lengthOfLIS(v));

    return 0;
}


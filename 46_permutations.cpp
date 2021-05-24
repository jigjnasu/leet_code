/*
  LeetCode.com
  Problem No: 46
  Problem: Permutations
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 25/05/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> list;
        backtrack(nums, res, list);
        return res;
    }

private:
    void backtrack(std::vector<int>& nums, std::vector<std::vector<int>>& res, std::vector<int>& list) {
        if (list.size() == nums.size()) {
            res.emplace_back(list);
            return;
        }
        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (std::find(list.begin(), list.end(), nums[i]) != list.end()) continue;
            list.emplace_back(nums[i]);
            backtrack(nums, res, list);
            list.pop_back();
        }
    }
};

inline void print(const std::vector<std::vector<int>>& vec) {
    printf("-----------------------------------------------------\n");
    for (const auto& v : vec) {
        for (int e : v)
            printf("%d ", e);
        printf("\n");
    }
    printf("-----------------------------------------------------\n");
}

int main() {
    Solution s;
    std::vector<int> v = {1,2,3};
    print(s.permute(v));

    return 0;
}

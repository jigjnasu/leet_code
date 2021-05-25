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
    std::vector<std::vector<int>> permute_bt(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> list;
        backtrack(nums, res, list);
        return res;
    }

    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        std::vector<int> list;
        permute_rec(nums, res, 0);
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

    void permute_rec(std::vector<int>& nums, std::vector<std::vector<int>>& res, int start) {
        if (start >= nums.size()) {
            res.emplace_back(nums);
            return;
        }
        for (int i = start; i < static_cast<int>(nums.size()); ++i) {
            std::swap(nums[i], nums[start]);
            permute_rec(nums, res, start + 1);
            std::swap(nums[i], nums[start]);
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
    std::vector<int> v = {1,2};
    print(s.permute(v));

    v = {1,2,3};
    print(s.permute(v));

    v = {1,2,3,4,5,6,7,8,9};
    print(s.permute(v));

    return 0;
}

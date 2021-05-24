/*
  LeetCode.com
  Problem No: 39
  Problem: Combination Sum
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 20/04/2020
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> res;
        std::vector<int> comb;
        backtrack(candidates, target, res, comb, 0);
        return res;
    }

private:
    void backtrack(std::vector<int>& candidates, int target, std::vector<std::vector<int>>& res, std::vector<int>& comb, int start) {
        if (target == 0) {
            res.emplace_back(comb);
            return;
        }
        for (int i = start; i < static_cast<int>(candidates.size()) && target >= candidates[i]; ++i) {
            comb.emplace_back(candidates[i]);
            backtrack(candidates, target - candidates[i], res, comb, i);
            comb.pop_back();
        }
    }
};

void print(const std::vector<std::vector<int>>& vec) {
    printf("----------------------------------------------------\n");
    for (auto& v : vec) {
        for (int e : v) {
            printf("%d ", e);
        }
        printf("\n");
    }
    printf("----------------------------------------------------\n");
}

int main() {
    Solution s;
    std::vector<int> v = {2,3,6,7};
    print(s.combinationSum(v, 7));

    v = {2};
    print(s.combinationSum(v, 1));

    v = {1};
    print(s.combinationSum(v, 1));

    v = {1};
    print(s.combinationSum(v, 2));

    return 0;
}

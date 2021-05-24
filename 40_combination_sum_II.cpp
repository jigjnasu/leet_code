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
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target) {
        std::vector<std::vector<int>> res;
        std::sort(candidates.begin(), candidates.end());
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
            if (i == start || candidates[i] != candidates[i - 1]) {
                comb.emplace_back(candidates[i]);
                backtrack(candidates, target - candidates[i], res, comb, i + 1);
                comb.pop_back();
            }
        }
    }
};

inline void print(const std::vector<std::vector<int>>& vec) {
    printf("--------------------------------------------------------------------\n");
    for (const auto& v : vec) {
        for (int e : v)
            printf("%d ", e);
        printf("\n");
    }
    printf("--------------------------------------------------------------------\n");
}

int main() {
    Solution s;
    std::vector<int> v = {10,1,2,7,6,1,5};
    print(s.combinationSum2(v, 8));

    v = {2,5,2,1,2};
    print(s.combinationSum2(v, 5));

    v = {1,1,2};
    print(s.combinationSum2(v, 2));

    return 0;
}

/*
  LeetCode.com
  Problem No: 1672
  Problem: Richest Customer Wealth
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 16/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>>& accounts) {
        int max_wealth = 0;
        for (auto cust : accounts) {
            int total = 0;
            for (int w : cust)
                total += w;
            max_wealth = std::max(total, max_wealth);
        }
        return max_wealth;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> v1 = {{1,2,3},
                                        {3,2,1}};
    printf("%d\n", s.maximumWealth(v1));
    std::vector<std::vector<int>> v2 = {{1,5},{7,3},{3,5}};
    printf("%d\n", s.maximumWealth(v2));
    std::vector<std::vector<int>> v3 = {{2,8,7},{7,1,3},{1,9,5}};
    printf("%d\n", s.maximumWealth(v3));

    return 0;
}

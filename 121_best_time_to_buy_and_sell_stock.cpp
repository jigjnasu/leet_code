/*
  Leetcode.com
  Problem No: 121
  Problem: Best Time to Buy and Sell Stock
  Author: cpp.rakesh@gmail.com
  Date: 27/05/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int max_pro = 0;
        int min_pri = INT_MAX;
        for (std::size_t i = 0; i < prices.size(); ++i) {
            min_pri = std::min(min_pri, prices[i]);
            max_pro = std::max(max_pro, prices[i] - min_pri);
        }
        return max_pro;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {7,1,5,3,6,4};
    printf("max profit == [%d]\n", s.maxProfit(v));

    v = {7,6,5,4,3,2,1};
    printf("max profit == [%d]\n", s.maxProfit(v));

    return 0;
}

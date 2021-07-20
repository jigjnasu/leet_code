/*
  Leetcode.com
  Problem No: 1475
  Problem : Final Prices With a Special Discount in a Shop
  Author: cpp.rakesh@gmail.com
  Date: 20/07/2021
*/

#include <bits/stdc++.h>

inline void print(const std::vector<int>& v) {
    printf("-------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n-------------------------------------------\n");
}

class Solution {
public:
    /*
    * O(n^2) time complexity
    */
    std::vector<int> finalPrices_n2(std::vector<int>& prices) {
        std::vector<int> res;
        for (std::size_t i = 0; i < prices.size(); ++i) {
            bool found = false;
            for (std::size_t j = i + 1; j < prices.size(); ++j) {
                if (prices[j] <= prices[i]) {
                    res.emplace_back(prices[i] - prices[j]);
                    found = true;
                    break;
                }
            }
            if (!found)
                res.emplace_back(prices[i]);
        }
        return res;
    }

    /*
    * O(n) time complexity
    */
    std::vector<int> finalPrices(std::vector<int>& prices) {
        std::vector<std::size_t> stack;
        for (std::size_t i = 0; i < prices.size(); ++i) {
            while (!stack.empty() && prices[stack.back()] >= prices[i]) {
                prices[stack.back()] -= prices[i];
                stack.pop_back();
            }
            stack.push_back(i);
        }
        return prices;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {8,4,6,2,3};
    print(s.finalPrices(v));

    v = {1,2,3,4,5};
    print(s.finalPrices(v));

    v = {10,1,1,6};
    print(s.finalPrices(v));   

    return 0;
}
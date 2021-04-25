/*
  Leetcode.com
  Problem No : 1833
  Problem : Maximum Ice Cream Bars
  Author : cpp.rakesh@gmail.com
  Date : 26/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int maxIceCream(std::vector<int>& costs, int coins) {
        std::sort(costs.begin(), costs.end());
        std::size_t i = 0;
        while (i < costs.size() && coins >= 0 && costs[i] <= coins)
            coins -= costs[i++];
        return i;
    }
};


int main() {
    Solution s;
    std::vector<int> v1 = {1,3,2,4,1};
    printf("%d\n", s.maxIceCream(v1, 7));

    std::vector<int> v2 = {10,6,8,7,7,8};
    printf("%d\n", s.maxIceCream(v2, 5));

    std::vector<int> v3 = {1,6,3,1,2,5};
    printf("%d\n", s.maxIceCream(v3, 20));

    return 0;
}

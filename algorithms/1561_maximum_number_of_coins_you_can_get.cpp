/*
  Leetcode.com
  Problem No : 1290
  Problem : Convert Binary Number in a Linked List to Integer
  Author : cpp.rakesh@gmail.com
  Date: 24/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int maxCoins(std::vector<int>& piles) {
        int s = 0;
        std::sort(piles.begin(), piles.end());
        int j = static_cast<int>(piles.size() - 2);
        for (int i = 0; i < static_cast<int>(piles.size()) / 3; ++i) {
            s += piles[j];
            j -= 2;
        }
        return s;
    }
};

int main() {
    Solution s;
    std::vector<int> v1 = {2,4,1,2,7,8};
    printf("%d\n", s.maxCoins(v1));

    std::vector<int> v2 = {2,4,5};
    printf("%d\n", s.maxCoins(v2));

    std::vector<int> v3 = {9,8,7,6,5,1,2,3,4};
    printf("%d\n", s.maxCoins(v3));

    return 0;
}

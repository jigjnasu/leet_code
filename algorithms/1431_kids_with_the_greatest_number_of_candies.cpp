/*
  LeetCode.com
  Problem Number: 1431
  Problem: Kids with the greatest number of candies
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 08/05/2020
 */

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<bool> kidsWithCandies(std::vector<int>& candies, int extraCandies) {
        int m = candies[0];
        for (std::size_t i = 1; i < candies.size(); ++i)
            m = std::max(m, candies[i]);

        std::vector<bool> r(candies.size(), false);
        for (std::size_t i = 0; i < r.size(); ++i)
            r[i] = candies[i] + extraCandies >= m;
        return r;
    }
};

inline void print(const std::vector<bool>& v) {
    printf("------------------------------------------------------\n");
    for (bool b : v)
        printf("%s ", b ? "true" : "false");
    printf("\n------------------------------------------------------\n");
}

int main() {
    Solution s;

    std::vector<int> c = {2, 3, 5, 1, 3};
    int extraCandies = 3;
    print(s.kidsWithCandies(c, extraCandies));

    c = {4, 2, 1, 1, 2};
    extraCandies = 1;
    print(s.kidsWithCandies(c, extraCandies));

    return 0;
}

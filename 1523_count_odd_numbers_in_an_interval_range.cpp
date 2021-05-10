/*
  Leetcode.com
  Problem No : 1523
  Problem : Count Odd Numbers in an Interval Range
  Author : cpp.rakesh@gmail.com
  Date : 11/05/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int countOdds(int low, int high) {
        int res = (high - low) >> 1;
        if (low & 1 || high & 1)
            ++res;
        return res;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.countOdds(3, 7));
    printf("%d\n", s.countOdds(8, 10));
    printf("%d\n", s.countOdds(1, 1));
    printf("%d\n", s.countOdds(2, 2));

    return 0;
}

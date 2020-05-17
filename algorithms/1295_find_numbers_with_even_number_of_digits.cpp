/*
  LeetCode.com
  Problem No: 1295
  Problem: Find numbers with even number of digits
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 02/01/2020
 */

#include <bits/stdc++.h>

class Solution {
public:
    int findNumbers(std::vector<int>& nums) {
        int c = 0;
        for (int n : nums) {
            int x = 0;
            while (n) {
                n /= 10;
                ++x;
            }
            if ((x & 1) == 0)
                ++c;
        }
        return c;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {12, 345, 2, 6, 7896};
    printf("%d\n", s.findNumbers(v));

    return 0;
}

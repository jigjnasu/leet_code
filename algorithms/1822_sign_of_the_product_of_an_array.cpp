/*
  Leetcode.com
  Problem No: 1822
  Problem: Sign of the Product of an Array
  Author: cpp.rakesh@gmail.com
  Date: 18/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int arraySign(std::vector<int>& nums) {
        int n = 0;
        for (int e : nums)
            if (e == 0)
                return 0;
            else if (e < 0)
                ++n;
        if (n & 1)
            return -1;
        return 1;
    }
};

int main() {
    Solution s;
    std::vector<int> v1 = {-1,-2,-3,-4,3,2,1};
    printf("%d\n", s.arraySign(v1));

    std::vector<int> v2 = {1,5,0,2,-3};
    printf("%d\n", s.arraySign(v2));

    std::vector<int> v3 = {-1,1,-1,1,-1};
    printf("%d\n", s.arraySign(v3));

    return 0;
}

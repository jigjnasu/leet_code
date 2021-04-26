/*
  LeetCode.com
  Problem No: 1389
  Problem: Create Target Array in the Given Order
  Rakesh Kumar
  Date: 17/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> createTargetArray(std::vector<int>& nums, std::vector<int>& index) {
        std::vector<int> v;
        for (std::size_t i = 0; i < nums.size(); ++i)
            v.insert(v.begin() + index[i], nums[i]);
        return v;
    }
};

inline void print(const std::vector<int>& v) {
    printf("-----------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n-----------------------------------------------\n");
}

int main() {
    Solution s;
    std::vector<int> n1 = {0,1,2,3,4};
    std::vector<int> i1 = {0,1,2,2,1};
    print(s.createTargetArray(n1, i1));

    std::vector<int> n2 = {1,2,3,4,0};
    std::vector<int> i2 = {0,1,2,3,0};
    print(s.createTargetArray(n2, i2));

    return 0;
}

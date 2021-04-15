/*
  LeetCode.com
  Problem No: 1480
  Problem: Running Sum of 1d Array
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 16/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> runningSum(std::vector<int>& nums) {
        for (std::size_t i = 1; i < nums.size(); ++i)
            nums[i] += nums[i - 1];
        return nums;
    }
};

inline void print(const std::vector<int>& v) {
    printf("---------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n---------------------------------------------\n");
}

int main() {
    std::vector<int> v1 = {1,2,3,4};
    Solution s;
    print(s.runningSum(v1));

    std::vector<int> v2 = {1,1,1,1,1};
    print(s.runningSum(v2));

    return 0;
}

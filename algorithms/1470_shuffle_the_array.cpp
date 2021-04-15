/*
  LeetCode.com
  Problem No: 1470
  Problem: Shuffle the Array
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 16/04/2021
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
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        std::vector<int> v(n << 1, 0);
        for (int i = 0; i < n; ++i) {
            v[i << 1] = nums[i];
            v[(i << 1) + 1] = nums[n + i];
        }
        return v;
    }
};

int main() {
    Solution s;
    std::vector<int> v1 = {2,5,1,3,4,7};
    print(s.shuffle(v1, 3));
    std::vector<int> v2 = {1,2,3,4,4,3,2,1};
    print(s.shuffle(v2, 4));
    std::vector<int> v3 = {1,1,2,2};
    print(s.shuffle(v3, 2));

    return 0;
}

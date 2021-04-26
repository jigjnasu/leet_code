/*
  LeetCode.com
  Problem No: 1313
  Problem: Decompress run length encoded list
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 20/04/2020
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> decompressRLElist(std::vector<int>& nums) {
        std::vector<int> r;
        for (std::size_t i = 0; i < nums.size() - 1; i += 2)
            for (int j = 0; j < nums[i]; ++j)
                r.push_back(nums[i + 1]);
        return r;
    }
};

inline void print(const std::vector<int>& v) {
    printf("-------------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n-------------------------------------------------------\n");
}

int main() {
    Solution s;
    std::vector<int> v = {1, 2, 3, 4};
    print(s.decompressRLElist(v));

    v = {1, 1, 2, 3};
    print(s.decompressRLElist(v));

    return 0;
}

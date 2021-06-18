/*
  LeetCode.com
  Problem Number: 1460
  Problem: Make Two Arrays Equal by Reversing Sub-arrays
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 16/06/2021
 */

#include <bits/stdc++.h>

class Solution {
public:
    bool canBeEqual(const std::vector<int>& target, const std::vector<int>& arr) {
        std::unordered_map<int, int> dict;
        for (int v : target)
            ++dict[v];
        for (int v : arr)
            --dict[v];
        for (const auto& it : dict)
            if (it.second != 0)
                return false;
        return true;
    }
};

int main() {
    Solution s;
    std::vector<int> t = {1,2,3,4};
    std::vector<int> a = {2,4,1,3};
    printf("%d\n", s.canBeEqual(t, a));

    t = {7};
    a = {7};
    printf("%d\n", s.canBeEqual(t, a));

    t = {1,12};
    a = {12,1};
    printf("%d\n", s.canBeEqual(t, a));

    t = {3,7,9};
    a = {3,7,11};
    printf("%d\n", s.canBeEqual(t, a));

    t = {1,1,1,1,1};
    a = {1,1,1,1,1};
    printf("%d\n", s.canBeEqual(t, a));

    return 0;
}
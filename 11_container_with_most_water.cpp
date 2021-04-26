/*
  LeetCode.com
  Problem No: 11
  Problem: Container With Most Water
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 29/03/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int maxArea(std::vector<int>& h) {
        int i = 0;
        int j = h.size() - 1;
        int r = 0;
        while (i < j) {
            r = std::max(r, (j - i) * std::min(h[i], h[j]));
            if (h[i] < h[j])
                ++i;
            else
                --j;
        }
        return r;
    }
};

int main() {
    Solution s;
    std::vector<int> v1 = {1,8,6,2,5,4,8,3,7};
    printf("%d\n", s.maxArea(v1));

    std::vector<int> v2 = {4,3,2,1,4};
    printf("%d\n", s.maxArea(v2));

    std::vector<int> v3 = {1, 2, 1};
    printf("%d\n", s.maxArea(v3));

    std::vector<int> v4 = {2,3,10,5,7,8,9};
    printf("%d\n", s.maxArea(v4));


    return 0;
}


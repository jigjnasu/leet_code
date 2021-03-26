/*
  LeetCode.com
  Problem No: 1464
  Problem: Maximum Product of Two Elements in an Array
  Rakesh Kumar
  Date: 26/03/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int maxProduct(std::vector<int>& v) {
        int f = v[0];
        int s = v[1];
        if (v[1] > f) {
            s = f;
            f = v[1];
        }
        for (std::size_t i = 2; i < v.size(); ++i) {
            if (v[i] > f) {
                s = f;
                f = v[i];
            } else if (v[i] > s) {
                s = v[i];
            }
        }
        return (f - 1) * (s - 1);
    }
};

int main() {
    std::vector<int> v = {3, 4, 5, 2};
    Solution s;
    printf("%d\n", s.maxProduct(v));
    return 0;
}

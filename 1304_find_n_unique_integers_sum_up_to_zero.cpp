/*
  LeetCode.com
  Problem: Find N unique integers sum up to zero
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 08/05/2020
 */

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> sumZero(int n) {
        std::vector<int> v;
        if (n & 1 == 1) {
            v.push_back(0);
            --n;
        }

        for (int i = 1; i <= (n >> 1); ++i) {
            v.push_back(i);
            v.push_back(-i);
        }
        return v;
    }
};

inline void print(const std::vector<int>& v) {
    printf("---------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n---------------------------------------------------\n");
}

int main() {
    Solution s;
    print(s.sumZero(4));
    return 0;
}

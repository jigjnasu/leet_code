/*
  Leetcode.com
  Problem No : 1823
  Problem : Find the Winner of the Circular Game
  Author : cpp.rakesh@gmail.com
  Date: 28/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int findTheWinner(int n, int k) {
        int r = 0;
        for (int i = 1; i <= n; ++i)
            r  = (r + k) % i;
        return r + 1;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.findTheWinner(5, 2));
    printf("%d\n", s.findTheWinner(6, 5));

    return 0;
}

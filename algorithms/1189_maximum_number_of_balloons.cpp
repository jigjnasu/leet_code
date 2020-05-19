/*
  LeetCode.com
  Problem No: 1189
  Problem: Maximum number of ballons
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 20/04/2020
*/

#include <bits/stdc++.h>

class Solution {
public:
    int maxNumberOfBalloons(std::string text) {
        int d[26] = {0};
        for (char c : text)
            ++d[c - 'a'];

        int a = std::min(std::min(d[0], d[1]), d[13]); // min of a, b and n
        int b = std::min(d[11], d[14]); // min of l and o
        return std::min(a, b >> 1);
    }
};

int main() {
    Solution s;
    printf("%d\n", s.maxNumberOfBalloons("nlaebolko"));
    printf("%d\n", s.maxNumberOfBalloons("loonbalxballpoon"));
    printf("%d\n", s.maxNumberOfBalloons("leetcode"));

    return 0;
}

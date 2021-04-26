/*
  LeetCode.com
  Problem No: 1221
  Problem: Split a String in Balanced Strings
  Rakesh Kumar
  Date: 17/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int balancedStringSplit(std::string s) {
        int l = 0;
        int r = 0;
        int count = 0;
        for (char c : s) {
            if (c == 'L') ++l;
            if (c == 'R') ++r;
            if (l == r) {
                ++count;
                l = r = 0;
            }
        }
        return count;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.balancedStringSplit("RLRRLLRLRL"));
    printf("%d\n", s.balancedStringSplit("RLLLLRRRLR"));
    printf("%d\n", s.balancedStringSplit("LLLLRRRR"));
    printf("%d\n", s.balancedStringSplit("RLRRRLLRLL"));

    return 0;
}

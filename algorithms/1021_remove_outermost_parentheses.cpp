/*
  LeetCode.com
  Problem No: 1021
  Problem: Remove Outermost Parentheses
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 26/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::string removeOuterParentheses(std::string s) {
        std::string r;
        int opened = 0;
        for (char c : s) {
            if ('(' == c && opened++ > 0) r += c;
            if (')' == c && opened-- > 1) r += c;
        }
        return r;
    }
};

int main() {
    Solution s;
    printf("%s\n", s.removeOuterParentheses("(()())(())").c_str());
    printf("%s\n", s.removeOuterParentheses("()()()").c_str());
    printf("%s\n", s.removeOuterParentheses("(()())(())(()(()))").c_str());

    return 0;
}

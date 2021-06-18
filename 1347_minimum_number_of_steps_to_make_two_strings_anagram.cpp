/*
  LeetCode.com
  Problem No: 1221
  Problem: Split a String in Balanced Strings
  Rakesh Kumar
  Date: 18/06/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int minSteps(const std::string s, const std::string t) {
        std::vector<int> dict(26, 0);
        for (char c : s)
            ++dict[c-'a'];
        for (char c : t)
            --dict[c-'a'];
        int res = 0;
        for (int v : dict)
            if (v > 0)
                res += v;
        return res;
    }
};

int main() {
    Solution s;
    std::string a = "bab";
    std::string b = "aba";
    printf("%d\n", s.minSteps(a, b));

    a = "leetcode";
    b = "practice";
    printf("%d\n", s.minSteps(a, b));

    a = "anagram";
    b = "mangaar";
    printf("%d\n", s.minSteps(a, b));

    a = "xxyyzz";
    b = "xxyyzz";
    printf("%d\n", s.minSteps(a, b));

    a = "friend";
    b = "family";
    printf("%d\n", s.minSteps(a, b));

    return 0;
}

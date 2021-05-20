/*
  Leetcode.com
  Problem No: 5
  Problem: Longest Palindromic Substring
  Author: cpp.rakesh@gmail.com
  Date: 20/05/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        if (s.size() <= 1)
            return s;
        low = 0, high = 0, max_len = 0;
        for (std::size_t i = 0; i < s.size() - 1; ++i) {
            expand(s, i, i);
            expand(s, i, i + 1);
        }
        return s.substr(low, max_len);
    }

private:
    int low = 0;
    int high = 0;
    int max_len = 0;

    void expand(const std::string& s, int l, int r) {
        while (l >= 0 && r < static_cast<int>(s.size()) && s[l] == s[r]) {
            --l; ++r;
        }
        if (r-l-1 > max_len) {
            max_len = r-l-1;
            low = l + 1; high = r - 1;
        }
    }
};

int main() {
    Solution s;
    printf("%s\n", s.longestPalindrome("rraarrbcdlel").c_str());
    printf("%s\n", s.longestPalindrome("babad").c_str());
    printf("%s\n", s.longestPalindrome("cbbd").c_str());
    printf("%s\n", s.longestPalindrome("a").c_str());
    printf("%s\n", s.longestPalindrome("ac").c_str());

    return 0;
}

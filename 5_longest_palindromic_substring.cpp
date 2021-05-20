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
    /*
      Time complexity
      for this approach we can think of worst case as follows->
      whole string is a palindrome
     */
    std::string longestPalindrome_bf(std::string s) {
        std::string res;
        for (std::size_t i = 0; i < s.size(); ++i) {
            for (std::size_t j = i; j < s.size(); ++j) {
                if (palindrome(s.substr(i, j-i+1))) {
                    if (s.substr(i, j-i+1).size() > res.size())
                        res = s.substr(i, j-i+1);
                }
            }
        }
        return res;
    }
    /*
      Time complexity
      for this approach we can think of the worst case as follows->
      whole string is a palindrome
      for i = 0 to n - 2:
          for i = mid to 0, n - 1:
      therefore O(n^2)
      Space complexity O(1)
     */
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

    bool palindrome(const std::string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j)
            if (s[i++] != s[j--])
                return false;
        return true;
    }
};

void test() {
    Solution s;
    std::string str = "rraarrbcdlel";
    printf("brute force O(n^3) == [%s]\n", s.longestPalindrome_bf(str).c_str());
    printf("exapnd      O(n^2) == [%s]\n", s.longestPalindrome(str).c_str());

    str = "babad";
    printf("brute force O(n^3) == [%s]\n", s.longestPalindrome_bf(str).c_str());
    printf("exapnd      O(n^2) == [%s]\n", s.longestPalindrome(str).c_str());

    str = "cbbd";
    printf("brute force O(n^3) == [%s]\n", s.longestPalindrome_bf(str).c_str());
    printf("exapnd      O(n^2) == [%s]\n", s.longestPalindrome(str).c_str());

    str = "a";
    printf("brute force O(n^3) == [%s]\n", s.longestPalindrome_bf(str).c_str());
    printf("exapnd      O(n^2) == [%s]\n", s.longestPalindrome(str).c_str());

    str = "ac";
    printf("brute force O(n^3) == [%s]\n", s.longestPalindrome_bf(str).c_str());
    printf("exapnd      O(n^2) == [%s]\n", s.longestPalindrome(str).c_str());

    str = "rakeshracecarkumar";
    printf("brute force O(n^3) == [%s]\n", s.longestPalindrome_bf(str).c_str());
    printf("exapnd      O(n^2) == [%s]\n", s.longestPalindrome(str).c_str());
}

int main() {
    test();

    return 0;
}

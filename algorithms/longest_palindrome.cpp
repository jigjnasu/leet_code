/*
  Solution for Longest Palindrome
  Author: cpp.rakesh@gmail.com
  Date: Nov 18th, 2016
*/

#include <cstdio>
#include <string>

class Solution {
public:
    int longestPalindrome(std::string s) {
        int dict[128] = {0};
        int total = 0;
        for (std::size_t i = 0; i < s.size(); ++i)
            ++dict[s[i]];
        for (int i = 0; i < 128; ++i)
            total += (dict[i] % 2) ? (total % 2 ? dict[i] - 1 : dict[i]) : dict[i];
        return total;
    }
};

int main() {
    Solution sol;
    printf("%d\n", sol.longestPalindrome("abccccdd"));
    
    return 0;
}

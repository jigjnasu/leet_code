/*
  LeetCode.com
  Problem No: 1844
  Problem: Replace All Digits with Characters
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 10/05/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::string replaceDigits(std::string s) {
        for (std::size_t i = 1; i < s.size(); i += 2)
            s[i] += s[i - 1] - '0';
        return s;
    }
};

int main() {
    Solution s;
    printf("%s\n", s.replaceDigits("a1c1e1").c_str());
    printf("%s\n", s.replaceDigits("a1b2c3d4e").c_str());
    return 0;
}

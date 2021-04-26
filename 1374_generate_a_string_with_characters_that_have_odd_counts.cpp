/*
  LeetCode.com
  Problem Number: 1374
  Problem: Generate a string with characters that have odd counts
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 11/05/2020
 */

#include <bits/stdc++.h>

class Solution {
public:
    std::string generateTheString(int n) {
        std::string r(n - 1, 'a');
        if (n & 1 == 1)
            r += 'a';
        else
            r += 'b';
        return r;
    }
};

int main() {
    Solution s;
    printf("%s\n", s.generateTheString(4).c_str());
    printf("%s\n", s.generateTheString(2).c_str());
    printf("%s\n", s.generateTheString(7).c_str());

    return 0;
}

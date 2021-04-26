/*
  LeetCode.com
  Problem Number: 1323
  Problem: Maximum 69 number
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 08/05/2020
 */

#include <bits/stdc++.h>

class Solution {
public:
    int maximum69Number (int num) {
        std::string s = std::to_string(num);
        for (std::size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '6') {
                s[i] = '9';
                break;
            }
        }

        return std::atoi(s.c_str());
    }
};

int main() {
    Solution s;

    printf("%d\n", s.maximum69Number(9669));
    printf("%d\n", s.maximum69Number(9996));
    printf("%d\n", s.maximum69Number(9999));

    return 0;
}

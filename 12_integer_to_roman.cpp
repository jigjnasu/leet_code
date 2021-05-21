/*
  Leetcode.com
  Problem No: 12
  Problem: Integer to Roman
  Author: cpp.rakesh@gmail.com
  Date: 21/05/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::string intToRoman(int num) {
        std::vector<int> val = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        std::vector<std::string> rom = {"M", "CM" , "D", "CD", "C" , "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        std::string r;
        std::size_t i = 0;
        while (num > 0) {
            while (num >= val[i]) {
                num -= val[i];
                r += rom[i];
            }
            ++i;
        }
        return r;
    }
};

int main() {
    Solution s;

    for (int i = 1; i <= 4000; ++i)
        printf("[%8d] == [%s]\n", i, s.intToRoman(i).c_str());

    return 0;
}

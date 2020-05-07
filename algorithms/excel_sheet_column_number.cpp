/*
  LeetCode.com
  Solution for Excel Sheet Column Number
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Nov 18th, 2016
 */

#include <cstdio>
#include <string>
#include <cmath>

class Solution {
public:

    int titleToNumber(std::string s) {
        int number = 0;
        int index = 0;
        for (int i = s.size() - 1; i >= 0; --i)
            number += std::pow(26, index++) * ((s[i] - 'A') + 1);

        return number;
    }
};

int main() {
    Solution s;
    std::string number = "A";
    printf("[%8d] for [%s]\n", s.titleToNumber(number), number.c_str());
    number = "Z";
    printf("[%8d] for [%s]\n", s.titleToNumber(number), number.c_str());
    number = "DZ";
    printf("[%8d] for [%s]\n", s.titleToNumber(number), number.c_str());
    number = "AAD";
    printf("[%8d] for [%s]\n", s.titleToNumber(number), number.c_str());
    number = "ZDEA";
    printf("[%8d] for [%s]\n", s.titleToNumber(number), number.c_str());

    return 0;
}

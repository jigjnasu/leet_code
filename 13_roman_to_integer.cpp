/*
  Leetcode.com
  Problem No: 13
  Problem: Roman to Integer
  Author: cpp.rakesh@gmail.com
  Date: 21/05/2021
*/

#include <bits/stdc++.h>

std::unordered_map<char, int> dict = {
    {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
    {'C', 100}, {'D', 500}, {'M', 1000}
};

class Solution {
public:
    int romanToInt(std::string s) {
        if (s.empty()) return 0;
        int i = static_cast<int>(s.size()) - 1;
        int res = dict[s[i--]];
        for (; i >= 0; --i) {
            if (dict[s[i]] < dict[s[i + 1]])
                res -= dict[s[i]];
            else
                res += dict[s[i]];
        }
        return res;
    }
};

int main() {
    Solution s;
    std::vector<std::string> nums = {"I", "II", "III", "IV", "V",
                                     "VI", "VII", "VIII", "IX", "X",
                                     "LVIII", "MCMXCIV"};
    for (const std::string& str : nums)
        printf("[%20s] == [%8d]\n", str.c_str(), s.romanToInt(str));

    return 0;
}

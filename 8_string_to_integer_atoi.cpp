/*
  Leetcode.com
  Problem No: 8
  Problem: String to Integer (atoi)
  Author: cpp.rakesh@gmail.com
  Date: 21/05/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int myAtoi(std::string s) {
        int i = 0;
        while (s[i] == ' ')
            ++i;
        int sign = 1;
        if (s[i] == '-' || s[i] == '+') {
            if (s[i] == '-')
                sign *= -1;
            ++i;
        }
        int r = 0;
        while (s[i] >= '0' && s[i] <= '9') {
            const int digit = s[i++] - '0';
            if (r > INT_MAX / 10 || (r == INT_MAX / 10 && digit > INT_MAX % 10))
                return sign == 1 ? INT_MAX : INT_MIN;
            r = (r * 10) + digit;
        }
        return r * sign;
    }
};


int main() {
    Solution s;
    printf("%d\n", s.myAtoi("    -123    "));
    printf("%d\n", s.myAtoi("83738"));

    return 0;
}

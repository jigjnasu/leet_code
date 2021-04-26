/*
  Leetcode.com
  Problem No : 7
  Problem : Reverse Integer
  Author : cpp.rakesh@gmail.com
  Date: 26/04/2021
*/

#include <bits/stdc++.h>

/*
  Two solutions
  1. using string
  2. Simple arithmatic techniques
 */
class Solution {
public:
    int reverse(int x) {
        std::string s = std::to_string(x);
        if (x < 0)
            s = s.substr(1, s.size() - 1);
        int i = 0;
        int j = s.size() - 1;
        while (i < j)
            swap_me(s[i++], s[j--]);
        long long r = std::stoll(s);
        if (x < 0)
            r *= -1;
        return (r < INT_MIN || r > INT_MAX) ? 0 : r;
    }

    int reverse_1(int x) {
        long long r = 0;
        while (x) {
            r = r * 10 + x % 10;
            x /= 10;
        }
        return (r < INT_MIN || r > INT_MAX) ? 0 : r;
    }

private:
    void swap_me(char& a, char& b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
};

int main() {
    Solution s;
    printf("%d %d\n", s.reverse(123), s.reverse_1(123));
    printf("%d %d\n", s.reverse(-123), s.reverse_1(-123));
    printf("%d %d\n", s.reverse(120), s.reverse_1(120));

    return 0;
}

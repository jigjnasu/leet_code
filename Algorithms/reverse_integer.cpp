/*
  LeetCode.com
  Solution for Reverse Integer
  Rakesh Kumar, cpp-rakesh(at)gmail.com
  Date: 26/03/2018
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x < 0)
            printf("-%d\n", m_reverse(x * -1));
        else
            printf("%d\n", m_reverse(x));
    }

private:
    int m_reverse(int x) {
        string s;
        while (x) {
            s.push_back((x % 10) + '0');
            x /= 10;
        }
        return atoi(s.c_str());
    }
};

int main() {
    Solution s;
    s.reverse(120);

    return 0;
}

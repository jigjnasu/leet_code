/*
  LeetCode.com
  Solution for Valid Parentheses
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 29/03/2018
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        int l = 0;
        int a = 0;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == 'A') {
                ++a;
                l = 0;
            } else if (s[i] == 'L') {
                ++l;
            } else {
                l = 0;
            }

            if (a > 1)
                return false;
            if (l > 2)
                return false;
        }

        return true;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.checkRecord("LALL"));

    return 0;
}

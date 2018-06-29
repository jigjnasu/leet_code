/*
  Solution for Nim Game from Leet Code.
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 18th, Nov, 2016
 */

#include <cstdio>

class Solution {
public:
    bool canWin(int n) {
        if (n % 4 == 0)
            return false;
        else
            return true;
    }
};

int main() {
    Solution s;
    for (int i = 1; i < 25; ++i)
        printf("n == [%d] win == [%s]\n", i, s.canWin(i) ? "Yes" : "No");
    
    return 0;
}

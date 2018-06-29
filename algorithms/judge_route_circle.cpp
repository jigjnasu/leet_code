/*
  LeetCode.com
  Solution for Judge Route Circle
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 10/03/2018
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool judgeCircle(string moves) {
        int x = 0;
        int y = 0;
        for (size_t i = 0; i < moves.size(); ++i) {
            switch (moves[i]) {
            case 'L': --x; break;
            case 'R': ++x; break;
            case 'U': ++y; break;
            case 'D': --y; break;
            default: break;
            }
        }

        return (x == 0 && y == 0);
    }
};

int main() {
    Solution s;
    printf("%d\n", s.judgeCircle("LL"));

    return 0;
}

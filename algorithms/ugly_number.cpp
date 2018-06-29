/*
  Solution for Ugly Number
  Author: cpp.rakesh@gmail.com
  10/07/2017
*/

#include <cstdio>

class Solution {
public:
    bool isUgly(int num) {
        if (num > 1) {
            for (int i = 2; i < 6; ++i) {
                while (num % i == 0)
                    num /= i;
            }
        }

        return num == 1;
    }
};

int main() {
    Solution s;
    int n = 9;
    printf("%d\n", s.isUgly(n));

    return 0;
}

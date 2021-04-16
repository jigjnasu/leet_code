/*
  LeetCode.com
  Problem Number: 1342
  Problem: Number of Steps to Reduce a Number to Zero
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 16/04/2021
 */

#include <bits/stdc++.h>

class Solution {
public:
    int numberOfSteps(int num) {
        int step = 0;
        while (num) {
            if (num & 1)
                --num;
            else
                num >>= 1;
            ++step;
        }
        return step;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.numberOfSteps(14));
    printf("%d\n", s.numberOfSteps(8));
    printf("%d\n", s.numberOfSteps(123));

    return 0;
}

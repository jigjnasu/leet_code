/*
  LeetCode.com
  Solution for Add Digits
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Nov 18th, 2016
 */

#include <cstdio>

class Solution {
public:
    int addDigits(int num) {
        return num > 0 ? num % 9 == 0 ? 9 : num % 9 : 0;
    }
};

int main() {
    Solution s;
    printf("Sum of Digits == [%d]\n", s.addDigits(123761));
    
    return 0;
}

/*
  Solution for Two Sum
  Author: cpp.rakesh@gmail.com
  Date: Nov 18th, 2016
*/

#include <cstdio>

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0) return 1;

        if (n % 2 == 0) {
            const double t = myPow(x, n / 2);
            return t * t;
        } else {
            const double t = myPow(x, n / 2);
            return (n > 0 ? x : 1.0f / x) * t * t;
        }
    }
};


int main() {
    Solution s;
    printf("power == [%f]\n", s.myPow(2, -2));
    
    return 0;
}

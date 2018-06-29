/*
  LeetCode.com
  Solution for Sum Of Two Integers
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Nov 18th, 2016
 */

#include <cstdio>
#include <cstdlib>

class Solution {
public:
    int getSum(int a, int b) {
        if (b == 0)
            return a;
        return getSum(a ^ b, (a & b) << 1);
    }
};

int random_number() {
    const int min = 0;
    const int max = 1000000;

    return min + rand() % (max - min) + 1;
}

int main() {
    Solution s;
    for (int i = 0; i < 100; ++i) {
        const int a = random_number();
        const int b = random_number();
        printf("[%8d] + [%8d] == [%8d]\n", a, b, s.getSum(a, b));
    }

    return 0;
}

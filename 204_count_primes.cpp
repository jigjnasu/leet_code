/*
  Problem Number: 204
  Problem: Count Primes
  Author: cpp.rakesh@gmail.com
  10/07/2017
*/

#include <cstdio>
#include <string>

class Solution {
public:
    int countPrimes(int n) {
        int count = 0;
        std::string p;
        for (int i = 0; i < n; ++i)
            p.push_back(1);

        for (std::size_t i = 2; i < p.size(); ++i) {
            if (p[i]) {
                ++count;
                for (std::size_t j = 2 * i; j < p.size(); j += i)
                    p[j] = 0;
            }
        }

        return count;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.countPrimes(8484));

    return 0;
}

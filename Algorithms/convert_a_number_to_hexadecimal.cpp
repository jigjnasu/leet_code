/*
  LeetCode.com
  Solution for Convert a Number to Hexadecimal
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Dec 29th, 2016
 */

#include <cstdio>
#include <cstdlib>
#include <string>
#include <sstream>

const std::string hex_values = "0123456789abcdef";

class Solution {
public:
    std::string toHex(int num) {
        if (num == 0)
            return "0";
        
        std::string str_num;
        while (num && str_num.size() <= 8) {
            str_num.insert(str_num.begin(), hex_values[num & 15]);
            num >>= 4;
        }

        return str_num;
    }

    int power(int x, int y) const {
        if (y == 1) {
            return x;
        } else {
            if (y % 2) {
                const int t = power(x, y / 2);
                return x * t * t;
            } else {
                const int t = power(x, y / 2);
                return x * x;
            }
        }
    }

    int random(int min, int max) const {
        return min + rand() % (max - min) + 1;
    }
};

int main() {
    Solution s;
    const int min = 0;
    const int max = s.power(2, 31);

    for (int i = 0; i < 100; ++i) {
        const int num = s.random(min, max);
        printf("[%8d] == [%s]\n", num, s.toHex(num).c_str());
    }

    return 0;
}

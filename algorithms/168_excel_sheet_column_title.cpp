/*
  Problem No: 168
  Problem: Excel Sheet Column Title
  Author: cpp.rakesh@gmail.com
  13/07/2017
*/

#include <cstdio>
#include <string>

class Solution {
public:
    std::string convertToTitle(int n) {
        std::string s;
        while (n) {
            s = static_cast<char>(((n - 1) % 26 + 'A')) + s;
            n = (n - 1) / 26;
        }

        return s;
    }
};

int main() {
    int n = 84;
    Solution s;
    printf("%s\n", s.convertToTitle(n).c_str());

    return 0;
}

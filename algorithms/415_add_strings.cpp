/*
  LeetCode.com
  Solution for Add Strings
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Nov 18th, 2016
 */

#include <cstdio>
#include <string>
#include <algorithm>

class Solution {
public:
    std::string addStrings(std::string num1, std::string num2) {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int c = 0;
        std::string result;
        while (i >= 0 && j >= 0) {
            const int s = c + (num1[i] - '0') + (num2[j] - '0');
            result.push_back((s % 10) + '0');
            c = s / 10;
            --i;
            --j;
        }

        while (i >= 0) {
            const int s = c + (num1[i] - '0');
            result.push_back((s % 10) + '0');
            c = s / 10;
            --i;
        }

        while (j >= 0) {
            const int s = c + (num2[j] - '0');
            result.push_back((s % 10) + '0');
            c = s / 10;
            --j;
        }

        while (c) {
            result.push_back((c % 10) + '0');
            c /= 10;
        }

        std::reverse(result.begin(), result.end());
        return result;
    }
};

int main() {
    Solution s;
    std::string a = "12424";
    std::string b = "817";
    printf("[%s] + [%s] == [%s]\n", a.c_str(), b.c_str(), s.addStrings(a, b).c_str());
    
    return 0;
}

/*
  LeetCode.com
  Problem No: 1551
  Problem: Minimum Operations to Make Array Equal
  Rakesh Kumar
  Date: 26/03/2021
*/

#include <cstdio>
#include <string>

class Solution {
public:
    std::string freqAlphabets(std::string s) {
        std::size_t i = 0;
        std::string r;
        while (i < s.size()) {
            if (i + 1 < s.size()) {
                if (s[i + 2] == '#') {
                    r += std::stoi(s.substr(i, 2)) - 10 + 'j';
                    i += 3;
                } else {
                    r += s[i] - '1' + 'a';
                    ++i;
                }
            } else {
                r += s[i] - '1' +'a';
                ++i;
            }
        }
        return r;
    }
};

int main() {
    Solution s;
    printf("%s\n", s.freqAlphabets("10#11#12").c_str());
    printf("%s\n", s.freqAlphabets("12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#").c_str());

    return 0;
}

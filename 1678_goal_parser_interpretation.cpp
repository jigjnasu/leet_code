/*
  LeetCode.com
  Problem Number: 1678
  Problem: Goal Parser Interpretation
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 16/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::string interpret(std::string command) {
        std::size_t i = 0;
        std::string r;
        while (i < command.size()) {
            if (command[i] == 'G') {
                r += 'G';
            } else if (command[i] == 'a') {
                r += "al";
                ++i;
            } else if (command[i] == '(' && command[i + 1] == ')') {
                r += 'o';
                ++i;
            }
            ++i;
        }
        return r;
    }
};

int main() {
    Solution s;
    printf("%s\n", s.interpret("G()(al)").c_str());
    printf("%s\n", s.interpret("G()()()()(al)").c_str());
    printf("%s\n", s.interpret("(al)G(al)()()G").c_str());

    return 0;
}

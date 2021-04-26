/*
  Leetcode.com
  Problem No : 1816
  Problem : Truncate Sentence
  Author : cpp.rakesh@gmail.com
  Date : 26/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::string truncateSentence(std::string s, int k) {
        for (std::size_t i = 0; i < s.size(); ++i)
            if (s[i] == ' ' && --k == 0)
                return s.substr(0, i);
        return s;
    }
};

int main() {
    Solution s;
    printf("%s\n", s.truncateSentence("Hello how are you Contestant",4).c_str());
    printf("%s\n", s.truncateSentence("What is the solution to this problem", 4).c_str());

    return 0;
}

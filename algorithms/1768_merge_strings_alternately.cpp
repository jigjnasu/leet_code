/*
  LeetCode.com
  Problem No: 1768
  Problem : Merge Strings Alternately
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 28903/2021
 */

#include <bits/stdc++.h>

class Solution {
public:
    std::string mergeAlternately(std::string w1, std::string w2) {
        std::size_t i = 0;
        std::size_t j = 0;
        std::string r;
        while (i < w1.size() && j < w2.size()) {
            r += w1[i++];
            r += w2[j++];
        }

        while (i < w1.size())
            r += w1[i++];
        while (j < w2.size())
            r += w2[j++];
        return r;
    }
};

int main() {
    Solution s;
    printf("%s\n", s.mergeAlternately("abc", "pqr").c_str());
    printf("%s\n", s.mergeAlternately("ab", "pqrs").c_str());
    printf("%s\n", s.mergeAlternately("abcd", "pq").c_str());

    return 0;
}

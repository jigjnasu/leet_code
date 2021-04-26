/*
  LeetCode.com
  Problem No: 389
  Problem: Find the Difference
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Nov 18th, 2016
 */

#include <cstdio>
#include <string>

class Solution {
public:
    char findTheDifference(std::string s, std::string t) {
        int loner = 0;
        std::size_t i = 0;

        while (i < s.size()) {
            loner += t[i] - s[i];
            ++i;
        }

        return loner += t[i];
    }
};

int main() {
    Solution sol;
    const std::string s = "abcdef";
    const std::string t = "fdercba";

    printf("[%c] is extra in [%s] compare to [%s]\n", sol.findTheDifference(s, t), t.c_str(), s.c_str());
    return 0;
}

/*
  Leetcode.com
  Problem No : 1684
  Problem : Count the Number of Consistent Strings
  Author : cpp.rakesh@gmail.com
  Date : 11/05/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int countConsistentStrings(std::string allowed, std::vector<std::string>& words) {
        int res = 0;
        std::vector<bool> dict(26, false);
        for (char c : allowed)
            dict[c - 'a'] = true;
        for (const std::string& s : words) {
            ++res;
            for (char c : s) {
                if (dict[c - 'a'] == false) {
                    --res;
                    break;
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    std::vector<std::string> w1 = {"ad","bd","aaab","baa","badab"};
    printf("%d\n", s.countConsistentStrings("ab", w1));
    std::vector<std::string> w2 = {"a","b","c","ab","ac","bc","abc"};
    printf("%d\n", s.countConsistentStrings("abc", w2));
    std::vector<std::string> w3 = {"cc","acd","b","ba","bac","bad","ac","d"};
    printf("%d\n", s.countConsistentStrings("cad", w3));

    return 0;
}

/*
  LeetCode.com
  Problem No: 242
  Problem: Valid Anagram
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Nov 18th, 2016
 */

#include <cstdio>
#include <string>

class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size())
            return false;

        int s_a[26] = { 0 };
        int s_t[26] = { 0 };

        for (std::size_t i = 0; i < s.size(); ++i) {
            ++s_a[s[i] - 'a'];
            ++s_t[t[i] - 'a'];
        }

        for (int i = 0; i < 26; ++i)
            if (s_a[i] != s_t[i])
                return false;
        return true;
    }
};

int main() {
    Solution s;
    const std::string a = "hansraj";
    const std::string b = "jarsnah";
    if (s.isAnagram(a, b))
        printf("[%s] and [%s] are Anagrams\n", a.c_str(), b.c_str());
    else
        printf("[%s] and [%s] are NOT Anagrams\n", a.c_str(), b.c_str());

    return 0;
}

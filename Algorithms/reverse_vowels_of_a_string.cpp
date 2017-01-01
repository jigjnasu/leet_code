/*
  Solution for Reverse of a String from LeetCode.com
  Author: Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Jan 2nd, 2017
*/

#include <cstdio>
#include <string>

class Solution {
public:
    std::string reverseVowels(std::string s) {
        int i = 0;
        int j = s.size() - 1;

        while (i < j) {
            while (i < j && !m_is_vowel(s[i]))
                ++i;
            while (i < j && !m_is_vowel(s[j]))
                --j;

            const char t = s[i];
            s[i] = s[j];
            s[j] = t;
            ++i;
            --j;
        }
        
        return s;
    }

private:
    bool m_is_vowel(char c) const {
        bool result = false;
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' ||
            c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            result = true;

        return result;
    }
};

int main() {
    Solution sol;
    std::string s = "HansRajModelSchoolPunjabiBaghNewDelhi";
    printf("%s\n", s.c_str());
    printf("%s\n", sol.reverseVowels(s).c_str());    
    
    return 0;
}

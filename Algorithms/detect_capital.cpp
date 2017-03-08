/*
  LeetCode.com
  Solution for Detect Capital
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: March 8th, 2017
*/

#include <cstdio>
#include <string>

class Solution {
public:
    bool detectCapitalUse(const std::string& word) {
        int small_counter = 0;
        int capital_counter = 0;

        for (std::size_t i = 0; i < word.size(); ++i) {
            if (word[i] >= 'a' && word[i] <= 'z')
                ++small_counter;
            else
                ++capital_counter;
        }

        if (word.size() - small_counter == 0 ||
            word.size() - capital_counter == 0)
            return true;

        if (capital_counter > 1)
            return false;

        if (word[0] >= 'A' && word[0] <= 'Z')
            return true;

        return false;
    }
};

int main() {
    Solution sol;
    
    printf("[%d]\n", sol.detectCapitalUse("Rakesh"));
    printf("[%d]\n", sol.detectCapitalUse("rakesh"));
    printf("[%d]\n", sol.detectCapitalUse("RAKESH"));
    printf("[%d]\n", sol.detectCapitalUse("RakesH"));    
    
    return 0;
}

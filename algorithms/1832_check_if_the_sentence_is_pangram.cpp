/*
  Leetcode.com
  Problem No : 1832
  Problem : Check if the Sentence Is Pangram
  Author : cpp.rakesh@gmail.com
  Date: 26/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    bool checkIfPangram(std::string sentence) {
        int d = 0;
        for (char c : sentence)
            d |= 1 << (c - 'a');
        return d == (1 << 26) - 1;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.checkIfPangram("thequickbrownfoxjumpsoverthelazydog"));
    printf("%d\n", s.checkIfPangram("leetcode"));

    return 0;
}

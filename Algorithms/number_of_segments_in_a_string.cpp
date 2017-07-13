/*
  Solution for Number of Segments in a String
  Author: cpp.rakesh@gmail.com
  14/07/2017
*/

#include <cstdio>
#include <string>

const char space = 32;

class Solution {
public:
    int countSegments(std::string s) {
        int count = 0;
        std::size_t i = 0;
        while (i < s.size()) {
            if (s[i] != space) {
                ++count;
                std::size_t j = i + 1;
                while (j < s.size() && s[j++] != space);
                i = j - 1;
            }
            ++i;
        }

        return count;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.countSegments("Rakesh Kumar"));

    return 0;
}

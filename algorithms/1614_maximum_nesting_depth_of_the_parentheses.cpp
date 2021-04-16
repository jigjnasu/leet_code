/*
  Problem No: 1614
  Problem : Maximum nesting depth of the parantheses
  Author : cpp.rakesh@gmail.com
  Date : 16/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int maxDepth(const std::string& s) {
        int lp_count = 0;
        int max_depth = 0;
        for (char c : s) {
            if (c == '(')
                ++lp_count;
            if (c == ')') {
                max_depth = std::max(max_depth, lp_count);
                --lp_count;
            }
        }
        return max_depth;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.maxDepth("(1+(2*3)+((8)/4))+1"));
    printf("%d\n", s.maxDepth("(1)+((2))+(((3)))"));
    return 0;
}


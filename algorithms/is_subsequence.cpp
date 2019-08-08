/*
  Solution for Is subsequence
  Author: cpp.rakesh@gmail.com
  Date: 09/08/2019
*/

#include <bits/stdc++.h>

class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int index = 0;
        for (const auto& x : s) {
            const int p = pos(x, index, t);
            if (p == -1)
                return false;
            index = p + 1;
        }

        return true;
    }

private:
    int pos(char c, int index, std::string& t) {
        for (int i = index; i < t.size(); ++i)
            if (c == t[i])
                return i;
        return -1;
    }
};

int main() {
    Solution s;
    printf("%d\n", s.isSubsequence("abc", "ahbgdc"));
    printf("%d\n", s.isSubsequence("axc", "ahbgdc"));

    return 0;
}

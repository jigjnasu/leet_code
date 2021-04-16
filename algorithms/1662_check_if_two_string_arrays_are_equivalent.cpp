/*
  LeetCode.com
  Solution : 1662. Check If Two String Arrays are Equivalent
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 17/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    bool arrayStringsAreEqual(std::vector<std::string>& word1, std::vector<std::string>& word2) {
        std::string a, b;
        for (const std::string& s : word1)
            a += s;
        for (const std::string& s : word2)
            b += s;
        return a == b;
    }
};

int main() {
    Solution s;
    std::vector<std::string> v11 = {"ab", "c"};
    std::vector<std::string> v12 = {"a", "bc"};
    printf("%d\n", s.arrayStringsAreEqual(v11, v12));

    std::vector<std::string> v21 = {"a", "cb"};
    std::vector<std::string> v22 = {"ab", "c"};
    printf("%d\n", s.arrayStringsAreEqual(v21, v22));

    std::vector<std::string> v31 = {"abc", "d", "defg"};
    std::vector<std::string> v32 = {"abcddefg"};
    printf("%d\n", s.arrayStringsAreEqual(v31, v32));

    return 0;
}


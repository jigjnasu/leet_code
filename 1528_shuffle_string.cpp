/*
  LeetCode.com
  Problem No: 1528
  Problem: Shuffle String
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 16/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::string restoreString(std::string s, std::vector<int>& indices) {
        std::string r = s;
        for (std::size_t i = 0; i < indices.size(); ++i)
            r[indices[i]] = s[i];
        return r;
    }
};

int main() {
    Solution s;
    std::vector<int> i = {4,5,6,7,0,2,1,3};
    printf("%s\n", s.restoreString("codeleet", i).c_str());
    return 0;
}

/*
  LeetCode.com
  Solution for Find common characters
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 20/04/2020
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::string> commonChars(std::vector<std::string>& arr) {
        int d[26] = {0};
        for (char c : arr[0])
            ++d[c - 'a'];

        for (std::size_t i = 1; i < arr.size(); ++i) {
            int t[26] = {0};
            for (char c : arr[i])
                ++t[c - 'a'];
            for (int j = 0; j < 26; ++j)
                d[j] = std::min(d[j], t[j]);
        }

        std::vector<std::string> r;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < d[i]; ++j) {
                std::string s;
                s = 'a' + i;
                r.push_back(s);
            }
        }
        return r;
    }
};

inline void print(const std::vector<std::string>& s) {
    printf("------------------------------------------------\n");
    for (std::string c : s)
        printf("%s ", c.c_str());
    printf("\n------------------------------------------------\n");
}


int main() {
    Solution s;

    std::vector<std::string> v = {"bella", "label", "roller"};
    print(s.commonChars(v));

    v = {"cool", "lock", "cook"};
    print(s.commonChars(v));

    return 0;
}

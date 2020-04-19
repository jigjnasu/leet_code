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
        std::vector<std::vector<int>> d(arr.size(), std::vector<int>(26, 0));

        int i = 0;
        for (const std::string& s : arr) {
            for (char c : s)
                ++d[i][c - 'a'];
            ++i;
        }

        std::vector<std::string> r;
        for (int i = 0; i < 26; ++i) {
            int m = arr[0].size();
            for (std::vector<int> v : d) {
                m = std::min(m, v[i]);
            }

            for (int j = 0; j < m; ++j) {
                std::string s;
                s += 'a' + i;
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

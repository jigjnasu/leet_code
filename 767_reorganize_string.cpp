/*
  LeetCode.com
  Problem No: 767
  Problem: Reorganize String
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 02/06/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::string reorganizeString(std::string s) {
        int freq = 0;
        std::vector<int> v(26, 0);
        for (char c : s) {
            ++v[c-'a'];
            if (v[c-'a'] > v[freq])
                freq = c-'a';
        }
        if (2 * v[freq] > s.size() + 1) return std::string("");
        int i = 0;
        while (v[freq]) {
            s[i] = freq + 'a';
            i += 2;
            --v[freq];
        }
        for (int j = 0; j < 26; ++j) {
            while (v[j]) {
                if (i >= s.size()) i = 1;
                s[i] = 'a' + j;
                i += 2;
                --v[j];
            }
        }
        return s;
    }
};

int main() {
    Solution s;
    printf("%s\n", s.reorganizeString("bba").c_str());
    printf("%s\n", s.reorganizeString("rakeshkumaradwitaatharv").c_str());

    return 0;
}


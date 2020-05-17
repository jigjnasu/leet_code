/*
  LeetCode.com
  Solution for find words that can be formed by charachters
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 03/09/2019
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    vector<int> calc(string& str) {
        vector<int> d(26, 0);
        for (char c : str)
            ++d[c - 'a'];
        return d;
    }

    int have(vector<int>& a, vector<int>& b) {
        for (std::size_t i = 0; i < b.size(); ++i)
            if (b[i] > a[i])
                return 0;
        return 1;
    }
public:
    int countCharacters(vector<string>& words, string chars) {
        int len = 0;
        vector<int> a = calc(chars);
        for (string w : words) {
            vector<int> b = calc(w);
            if (have(a, b))
                len += w.size();
        }
        return len;
    }
};

int main() {
    Solution s;
    vector<string> w = {"cat","bt","hat","tree"};
    string c = "atach";

    printf("%d\n", s.countCharacters(w, c));

    w = {"hello","world","leetcode"};
    c = "welldonehoneyr";
    printf("%d\n", s.countCharacters(w, c));
    return 0;
}

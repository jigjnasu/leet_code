/*
  LeetCode.com
  Solution for compare strings by frequency of the smallest character
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 03/09/2019
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
    int count(string w) {
        int d[26] = {0};
        for (std::size_t i = 0; i < w.size(); ++i)
            ++d[w[i] - 'a'];
        for (int i = 0; i < 26; ++i)
            if (d[i])
                return d[i];

        return 0;
    }

public:
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        vector<int> w;
        for (std::size_t i = 0; i < words.size(); ++i)
            w.push_back(count(words[i]));

        vector<int> r;
        sort(w.begin(), w.end());

        for (std::size_t i = 0; i < queries.size(); ++i)
            r.push_back(w.end() - upper_bound(w.begin(), w.end(), count(queries[i])));

        return r;
    }
};

inline void print(const std::vector<int>& v) {
    for (const auto& x : v)
        printf("%d ", x);
    printf("\n");
}

int main() {
    Solution s;
    std::vector<std::string> q = {"cbd"};
    std::vector<std::string> w = {"zaaaz"};
    print(s.numSmallerByFrequency(q, w));

    q = {"bbb","cc"};
    w = {"a","aa","aaa","aaaa"};
    print(s.numSmallerByFrequency(q, w));

    return 0;
}

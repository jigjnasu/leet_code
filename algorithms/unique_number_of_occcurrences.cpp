/*
  LeetCode.com
  Solution for Unique number of occurrences
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 03/01/2020
 */

#include <bits/stdc++.h>

class Solution {
public:
    bool uniqueOccurrences(std::vector<int>& arr) {
        std::unordered_map<int, int> d;
        for (int v : arr)
            ++d[v];

        bool result = true;
        std::vector<bool> v(1001, false);
        for (auto it = d.begin(); it != d.end(); ++it) {
            if (v[it->second] == true) {
                result = false;
                break;
            }
            v[it->second] = true;
        }
        return result;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {1, 2, 2, 1, 1, 3};
    printf("%s\n", s.uniqueOccurrences(v) ? "true" : "false");

    v = {1, 2};
    printf("%s\n", s.uniqueOccurrences(v) ? "true" : "false");

    v = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    printf("%s\n", s.uniqueOccurrences(v) ? "true" : "false");

    return 0;
}

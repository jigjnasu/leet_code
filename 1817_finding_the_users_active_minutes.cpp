/*
  Leetcode.com
  Problem No : 1817
  Problem : Finding the Users Active Minutes
  Author : cpp.rakesh@gmail.com
  Date : 26/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> findingUsersActiveMinutes(std::vector<std::vector<int>>& logs, int k) {
        std::unordered_map<int, std::set<int>> dict;
        for (const std::vector<int>& v : logs)
            dict[v[0]].insert(v[1]);
        std::vector<int> r(k, 0);
        for (auto& it : dict)
            ++r[it.second.size() - 1];
        return r;
    }
};

inline void print(const std::vector<int>& v) {
    printf("------------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n------------------------------------------------------\n");
}

int main() {
    Solution s;
    std::vector<std::vector<int>> v1 = {{0,5},{1,2},{0,2},{0,5},{1,3}};
    print(s.findingUsersActiveMinutes(v1, 5));

    std::vector<std::vector<int>> v2 = {{1,1},{2,2},{2,3}};
    print(s.findingUsersActiveMinutes(v2, 4));
    return 0;
}

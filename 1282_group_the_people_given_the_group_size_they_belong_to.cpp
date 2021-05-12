/*
  LeetCode.com
  Problem Number: 1282
  Problem: Group the People Given the Group Size They Belong To
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 08/05/2020
 */

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::vector<int>> groupThePeople(std::vector<int>& gs) {
        std::vector<std::vector<int>> res;
        std::unordered_map<int, std::vector<int>> dict;
        for (std::size_t i = 0; i < gs.size(); ++i) {
            dict[gs[i]].emplace_back(i);
            if (static_cast<int>(dict[gs[i]].size()) == gs[i]) {
                res.emplace_back(dict[gs[i]]);
                dict[gs[i]].clear();
            }
        }
        return res;
    }
};

inline void print(const std::vector<std::vector<int>>& v) {
    printf("--------------------------------------------------\n");
    for (const auto& row : v) {
        for (int e : row)
            printf("%d ", e);
        printf("\n");
    }
    printf("--------------------------------------------------\n");
}

int main() {
    Solution s;
    std::vector<int> v1 = {3,3,3,3,3,1,3};
    print(s.groupThePeople(v1));

    return 0;
}

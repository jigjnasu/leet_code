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
        std::unordered_map<int, std::vector<int>> dict;
        for (std::size_t i = 0; i < gs.size(); ++i)
            dict[gs[i]].emplace_back(i);
        std::vector<std::vector<int>> res;
        for (const auto& it : dict) {
            for (std::size_t i = 0; i < it.second.size() / it.first; ++i) {
                std::vector<int> temp;
                for (int j = i * it.first; j < it.first * (i + 1); ++j)
                    temp.emplace_back(it.second[j]);
                res.emplace_back(temp);
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

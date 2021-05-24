/*
  LeetCode.com
  Problem No: 56
  Problem: Merge Intervals
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 25/05/2021
*/

#include <bits/stdc++.h>

inline void print(const std::vector<std::vector<int>>& vec) {
    printf("-----------------------------------------------------------------\n");
    for (const auto& v : vec) {
        for (int e : v)
            printf("%d ", e);
        printf("\n");
    }
    printf("-----------------------------------------------------------------\n");
}

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.size() <= 1)
            return intervals;
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
                                                          return a[0] < b[0];
                                                      });
        std::vector<std::vector<int>> res;
        res.emplace_back(intervals[0]);
        for (std::size_t i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] <= res[res.size()-1][1])
                res[res.size()-1][1] = std::max(res[res.size()-1][1], intervals[i][1]);
            else
                res.emplace_back(intervals[i]);
        }
        return res;
    }
};


int main() {
    Solution s;
    std::vector<std::vector<int>> v = {{20,23},{1,3},{2,6},{8,10},{15,18}};
    print(s.merge(v));

    v = {{1,4},{4,5}};
    print(s.merge(v));

    v = {{1,4}, {5,6}};
    print(s.merge(v));

    v = {{1,4}, {2,3}};
    print(s.merge(v));

    v = {{2,3},{4,5},{6,7},{8,9},{1,10}};
    print(s.merge(v));

    return 0;
};

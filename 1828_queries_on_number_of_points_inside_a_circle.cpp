/*
  Leetcode.com
  Problem No: 1828
  Problem: Queries on Number of Points Inside a Circle
  Author: cpp.rakesh@gmail.com
  Date: 18/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> countPoints(std::vector<std::vector<int>>& p,
                                 std::vector<std::vector<int>>& q) {
        std::vector<int> res;
        for (std::size_t i = 0;  i < q.size(); ++i) {
            int count = 0;
            for (std::size_t j = 0; j < p.size(); ++j)
                if (std::sqrt(((q[i][0] - p[j][0]) * (q[i][0] - p[j][0])) +
                              ((q[i][1] - p[j][1]) * (q[i][1] - p[j][1]))) <= q[i][2])
                    ++count;
            res.emplace_back(count);
        }
        return res;
    }
};

inline void print(const std::vector<int>& v) {
    printf("---------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n---------------------------------------------------\n");
}

int main() {
    Solution s;
    std::vector<std::vector<int>> p1 = {{1,3},{3,3},{5,3},{2,2}};
    std::vector<std::vector<int>> q1 = {{2,3,1},{4,3,1},{1,1,2}};
    print(s.countPoints(p1, q1));

  std::vector<std::vector<int>> p2 = {{1,1},{2,2},{3,3},{4,4},{5,5}};
  std::vector<std::vector<int>> q2 = {{1,2,2},{2,2,2},{4,3,2},{4,3,3}};
  print(s.countPoints(p2, q2));

  return 0;
}

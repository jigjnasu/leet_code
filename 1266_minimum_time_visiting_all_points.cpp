/*
  LeetCode.com
  Problem Number: 1266
  Problem: minimum time visiting all points
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 11/05/2020
 */

#include <bits/stdc++.h>

class Solution {
public:
    int minTimeToVisitAllPoints(std::vector<std::vector<int>>& points) {
        int t = 0;
        for (std::size_t i = 1; i < points.size(); ++i) {
            const int x = std::abs(points[i][0] - points[i - 1][0]);
            const int y = std::abs(points[i][1] - points[i - 1][1]);
            t += std::max(x, y);
        }

        return t;
    }
};

int main() {
    Solution s;

    std::vector<std::vector<int>> v = { {1, 1}, {3, 4}, {-1, 0} };
    printf("%d\n", s.minTimeToVisitAllPoints(v));

    v = { {3, 2}, {-2, 2} };
    printf("%d\n", s.minTimeToVisitAllPoints(v));

    return 0;
}

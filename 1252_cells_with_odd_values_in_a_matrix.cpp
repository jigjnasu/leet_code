/*
  LeetCode.com
  Problem No: 1252
  Problem : Cells with Odd Values in a Matrix
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 28/03/2021
 */

#include <bits/stdc++.h>

inline void print(const std::vector<std::vector<int>>& v) {
    printf("----------------------------------------------------\n");
    for (auto& r : v) {
        for (int e : r)
            printf("%d ", e);
        printf("\n");
    }
    printf("----------------------------------------------------\n");
}

class Solution {
public:
    int oddCells(int m, int n, std::vector<std::vector<int>>& indices) {
        std::vector<std::vector<int>> cells(m, std::vector<int>(n, 0));
        for (auto& i : indices) {
            for (int c = 0; c < n; ++c)
                ++cells[i[0]][c];
            for (int r = 0; r < m; ++r)
                ++cells[r][i[1]];
        }
        int odds = 0;
        for (auto& r : cells)
            for (int e : r)
                if (e & 1)
                    ++odds;
        return odds;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> v1 = {{0, 1}, {1, 1}};
    printf("%d\n", s.oddCells(2, 3, v1));

    std::vector<std::vector<int>> v2 = {{1, 1}, {0, 0}};
    printf("%d\n", s.oddCells(2, 2, v2));

    return 0;
}

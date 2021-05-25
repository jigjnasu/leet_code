/*
  LeetCode.com
  Problem No: 64
  Problem: Minimum Path Sum
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 26/05/2021
*/

#include <bits/stdc++.h>

inline void print(const std::vector<std::vector<int>>& grid) {
    printf("----------------------------------------------\n");
    for (const auto& row : grid) {
        for (int e : row)
            printf("%d ", e);
        printf("\n");
    }
    printf("----------------------------------------------\n");
}

class Solution {
public:
    int minPathSum(std::vector<std::vector<int>>& grid) {
        int m = static_cast<int>(grid.size());
        int n = static_cast<int>(grid[0].size());
        std::vector<std::vector<int>> res(m, std::vector<int>(n, grid[0][0]));
        for (int r = 1; r < m; ++r)
            res[r][0] = res[r-1][0] + grid[r][0];
        for (int c = 1; c < n; ++c)
            res[0][c] = res[0][c-1] + grid[0][c];
        for (int r = 1; r < m; ++r)
            for (int c = 1; c < n; ++c)
                res[r][c] = std::min(res[r-1][c], res[r][c-1]) + grid[r][c];
        return res[m-1][n-1];
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> grid = {{1,1,1,1},
                                          {1,1,1,1},
                                          {1,1,1,1},
                                          {1,1,1,1}};
    printf("%d\n", s.minPathSum(grid));

    grid = {{1,3,1},
            {1,5,1},
            {4,2,1}};
    printf("%d\n", s.minPathSum(grid));

    return 0;
}

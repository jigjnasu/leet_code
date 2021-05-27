/*
  Leetcode.com
  Problem No: 200
  Problem : Number of Islands
  Author : cpp.rakesh@gmail.com
  Date: 27/05/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        int islands = 0;
        for (std::size_t r = 0; r < grid.size(); ++r) {
            for (std::size_t c = 0; c < grid[r].size(); ++c) {
                if (grid[r][c] == '1') {
                    ++islands;
                    removeIsland(grid, r, c);
                }
            }
        }

        return islands;
    }

private:
    void removeIsland(std::vector<std::vector<char>>& grid, int r, int c) {
        if (r < 0 || r == static_cast<int>(grid.size()) ||
            c < 0 || c == static_cast<int>(grid[0].size()) ||
            grid[r][c] == '0')
            return;
        grid[r][c] = '0';
        removeIsland(grid, r - 1, c);
        removeIsland(grid, r + 1, c);
        removeIsland(grid, r, c - 1);
        removeIsland(grid, r, c + 1);
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> grid = {
        {'1','1','1','1','0'},
        {'1','1','0','1','0'},
        {'1','1','0','0','0'},
        {'0','0','0','0','0'}
    };
    printf("number of islands == [%d]\n", s.numIslands(grid));

    grid = {
        {'1','1','0','0','0'},
        {'1','1','0','0','0'},
        {'0','0','1','0','0'},
        {'0','0','0','1','1'}
    };
    printf("number of islands == [%d]\n", s.numIslands(grid));

    return 0;
}

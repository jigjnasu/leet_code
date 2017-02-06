/*
  Solution for Island Perimeter
  Author: cpp.rakesh@gmail.com
  Date: Feb 7th 18th, 2017
*/

#include <cstdio>
#include <vector>

class Solution {
public:
    int islandPerimeter(std::vector< std::vector<int> >& grid) {
        int total = 0;
        int neighbours = 0;
        for (int r = 0; r < grid.size(); ++r) {
            for (int c = 0; c < grid[r].size(); ++c) {
                if (grid[r][c]) {
                    ++total;
                    if (r < grid.size() - 1 && grid[r + 1][c]) ++neighbours;
                    if (c < grid[r].size() - 1 && grid[r][c + 1]) ++neighbours;
                }
            }
        }
        return (4 * total) - (2 * neighbours);
    }
};

int main() {
    Solution s;
    std::vector < std::vector<int> > grid = { {1, 1} };
    
    printf("Island perimeter == [%d]\n", s.islandPerimeter(grid));

    return 0;
}

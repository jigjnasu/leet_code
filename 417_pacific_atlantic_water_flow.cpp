/*
  LeetCode.com
  Problem No: 417
  Problem: Pacific Atlantic Water Flow
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 02/06/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>>& h) {
        std::vector<std::vector<int>> res;
        int m = static_cast<int>(h.size());
        int n = static_cast<int>(h[0].size());
        if (m && n) {
            std::vector<std::vector<bool>> pacific(m, std::vector<bool>(n, 0));
            std::vector<std::vector<bool>> atlantic(m, std::vector<bool>(n, 0));
            for (int r = 0; r < m; ++r) {
                dfs(h, pacific, r, 0);
                dfs(h, atlantic, r, n-1);
            }
            for (int c = 0; c < n; ++c) {
                dfs(h, pacific, 0, c);
                dfs(h, atlantic, m-1, c);
            }

            for (int r = 0; r < m; ++r)
                for (int c = 0; c < n; ++c)
                    if (pacific[r][c] && atlantic[r][c]) {
                        std::vector<int> v = {r,c};
                        res.emplace_back(v);
                    }
        }
        return res;
    }

private:
    void dfs(const std::vector<std::vector<int>>& h, std::vector<std::vector<bool>>& visited, int r, int c) {
        int m = static_cast<int>(h.size());
        int n = static_cast<int>(h[0].size());
        visited[r][c] = true;
        // up
        if (r-1 >= 0 && visited[r-1][c] == false && h[r-1][c] >= h[r][c])
            dfs(h, visited, r-1, c);
        // down
        if (r+1 < m && visited[r+1][c] == false && h[r+1][c] >= h[r][c])
            dfs(h, visited, r+1, c);
        // left
        if (c-1 >=0 && visited[r][c-1] == false && h[r][c-1] >= h[r][c])
            dfs(h, visited, r, c-1);
        // righht
        if (c+1 < n && visited[r][c+1] == false && h[r][c+1] >= h[r][c])
            dfs(h, visited, r,c+1);
    }
};

inline void print(const std::vector<std::vector<int>>& vec) {
    printf("------------------------------------------------------\n");
    for (const auto& v : vec) {
        for (int e : v)
            printf("%d ", e);
        printf("\n");
    }
    printf("------------------------------------------------------\n");
}

int main() {
    Solution s;
    std::vector<std::vector<int>> h = {
        {1,2,2,3,5},
        {3,2,3,4,4},
        {2,4,5,3,1},
        {6,7,1,4,5},
        {5,1,1,2,4}
    };
    print(s.pacificAtlantic(h));

    h = {{2,1},{1,2}};
    print(s.pacificAtlantic(h));

    return 0;
}

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
        m = static_cast<int>(h.size());
        n = static_cast<int>(h[0].size());
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
    int m = 0;
    int n = 0;

    void dfs(const std::vector<std::vector<int>>& h, std::vector<std::vector<bool>>& visited, int r, int c) {
        visited[r][c] = true;
        if (!out(r-1, c) && !visited[r-1][c] && h[r][c] <= h[r-1][c])
            dfs(h, visited, r-1, c);
        if (!out(r+1, c) && !visited[r+1][c] && h[r][c] <= h[r+1][c])
            dfs(h, visited, r+1, c);
        if (!out(r, c-1) && !visited[r][c-1] && h[r][c] <= h[r][c-1])
            dfs(h, visited, r, c-1);
        if (!out(r, c+1) && !visited[r][c+1] && h[r][c] <= h[r][c+1])
            dfs(h, visited, r, c+1);
    }

    bool out(int r, int c) {
        return r < 0 || c < 0 || r >= m || c >= n;
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

/*
  LeetCode.com
  Problem No: 289
  Problem: Game of Life
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 01/06/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    void gameOfLife(std::vector<std::vector<int>>& board) {
        int m = static_cast<int>(board.size());
        int n = static_cast<int>(board[0].size());
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                int count = 0;
                for (int R = std::max(0, r - 1); R < std::min(r + 2, m); ++R)
                    for (int C = std::max(0, c - 1); C < std::min(c + 2, n); ++C)
                        count += board[R][C] & 1;
                if (count == 3 || count - board[r][c] == 3)
                    board[r][c] |= 2;
            }
        }
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                board[r][c] >>= 1;
    }
};

inline void print(const std::vector<std::vector<int>>& board) {
    printf("---------------------------------------------------------------\n");
    for (const auto& r : board) {
        for (int v : r)
            printf("%d ", v);
        printf("\n");
    }
    printf("---------------------------------------------------------------\n");
}

int main() {
    std::vector<std::vector<int>> board = {{0,1,0},
                                           {0,0,1},
                                           {1,1,1},
                                           {0,0,0}};
    Solution s;
    print(board);
    s.gameOfLife(board);
    print(board);

    board = {{1,1},
             {1,0}};
    print(board);
    s.gameOfLife(board);
    print(board);

    return 0;
}

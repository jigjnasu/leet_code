/*
  LeetCode.com
  Problem No: 79
  Problem: Word Search
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 26/05/2021
*/

#include <bits/stdc++.h>

inline void print(const std::vector<std::vector<char>>& board) {
    printf("-------------------------------------------------------------\n");
    for (const auto& row : board) {
        for (char c : row)
            printf("%c ", c);
        printf("\n");
    }
    printf("-------------------------------------------------------------\n");
}

class Solution {
public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        for (std::size_t r = 0; r < board.size(); ++r) {
            for (std::size_t c = 0; c < board[r].size(); ++c) {
                if (exist(board, word, r, c, 0))
                    return true;
            }
        }
        return false;
    }
private:
    bool exist(std::vector<std::vector<char>>& board, std::string& word, int x, int y, int len) {
        if (len == static_cast<int>(word.size())) return true;
        if (x < 0 || y < 0 || x >= static_cast<int>(board.size()) || y >= static_cast<int>(board[0].size())) return false;
        if (word[len] != board[x][y]) return false;
        const char temp = board[x][y];
        board[x][y] = ' ';
        bool res = exist(board, word, x-1, y, len+1) ||
            exist(board, word, x+1, y, len+1) ||
            exist(board, word, x, y-1, len+1) ||
            exist(board, word, x, y+1, len+1);
        board[x][y] = temp;
        return res;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}};
    printf("%d\n", s.exist(board, "ABCCED"));

    board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}};
    printf("%d\n", s.exist(board, "SEE"));

    board = {
        {'A','B','C','E'},
        {'S','F','C','S'},
        {'A','D','E','E'}};
    printf("%d\n", s.exist(board, "ABCB"));

    return 0;
}

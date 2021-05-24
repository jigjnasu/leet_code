/*
  LeetCode.com
  Problem No: 36
  Problem: Valid Sudoku
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 20/04/2020
*/

#include <bits/stdc++.h>

class Solution {
public:
    bool isValidSudoku_dict(std::vector<std::vector<char>>& board) {
        std::unordered_map<std::string, bool> dict;
        for (std::size_t r = 0; r < board.size();  ++r) {
            for (std::size_t c = 0; c < board[r].size(); ++c) {
                if (board[r][c] != '.') {
                    std::string t = "r" + std::to_string(r) + std::to_string(board[r][c]);
                    if (dict.find(t) == dict.end())
                        dict[t] = true;
                    else
                        return false;
                    t = "c" + std::to_string(c) + std::to_string(board[r][c]);
                    if (dict.find(t) == dict.end())
                        dict[t] = true;
                    else
                        return false;
                    t = "b" + std::to_string(r / 3) + std::to_string( c / 3) + std::to_string(board[r][c]);
                    if (dict.find(t) == dict.end())
                        dict[t] = true;
                    else
                        return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};
        for (int r = 0; r < static_cast<int>(board.size()); ++r) {
            for (int c = 0; c < static_cast<int>(board[r].size()); ++c) {
                if (board[r][c] != '.') {
                    const int n = board[r][c]-'0'-1;
                    const int box_no = r / 3 * 3 + c / 3;
                    if (row[r][n] || col[c][n] || box[box_no][n]) {
                        return false;
                    }
                    row[r][n] = col[c][n] = box[box_no][n] = true;
                }
            }
        }
        return true;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    printf("%d\n", s.isValidSudoku_dict(board));
    printf("%d\n", s.isValidSudoku(board));

    board = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    printf("%d\n", s.isValidSudoku_dict(board));
    printf("%d\n", s.isValidSudoku(board));

    return 0;
}

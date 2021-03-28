/*
  Leetcode.com
  Problem No: 1572
  Problem: 1572. Matrix Diagonal Sum
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 29/03/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int diagonalSum(std::vector<std::vector<int>>& mat) {
        int sum = 0;
        for (std::size_t r = 0; r < mat.size(); ++r)
            for (std::size_t c = 0; c < mat[r].size(); ++c)
                if (r == c || r + c == mat.size() - 1)
                    sum += mat[r][c];
        int i = mat.size() >> 1;
        return sum;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> v1 = {{1, 2, 3},
                                        {4, 5, 6},
                                        {7, 8, 9}};
    printf("%d\n", s.diagonalSum(v1));

    std::vector<std::vector<int>> v2 = {{1, 1, 1, 1},
                                        {1, 1, 1, 1},
                                        {1, 1, 1, 1},
                                        {1, 1, 1, 1}};
    printf("%d\n", s.diagonalSum(v2));

    return 0;
}

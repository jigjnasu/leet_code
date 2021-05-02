/*
  Leetcode.com
  Problem No : 1773
  Problem : Count Items Matching a Rule
  Author : cpp.rakesh@gmail.com
  Date: 02/05/2021
*/

#include <bits/stdc++.h>

class SubrectangleQueries {
public:
    SubrectangleQueries(std::vector<std::vector<int>>& rectangle) : rect(rectangle) {}

    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int r = row1; r <= row2; ++r)
            for (int c = col1; c <= col2; ++c)
                rect[r][c] = newValue;
    }

    int getValue(int row, int col) {
        return rect[row][col];
    }

private:
    std::vector<std::vector<int>> rect;
};

int main() {
    std::vector<std::vector<int>> v = {{{1,2,1},
                                        {4,3,4},
                                        {3,2,1},
                                        {1,1,1}}};
    SubrectangleQueries s(v);
    printf("%d\n", s.getValue(0, 2));
    s.updateSubrectangle(0,0,3,2,5);
    printf("%d\n", s.getValue(0, 2));
    printf("%d\n", s.getValue(3, 1));
    s.updateSubrectangle(3,0,3,2,10);
    printf("%d\n", s.getValue(3, 1));
    printf("%d\n", s.getValue(0, 2));

    return 0;
}

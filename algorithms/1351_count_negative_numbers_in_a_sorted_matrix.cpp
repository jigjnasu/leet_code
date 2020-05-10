#include <bits/stdc++.h>

class Solution {
public:
    int countNegatives(std::vector<std::vector<int>>& grid) {
        int c = 0;
        for (std::vector<int> v : grid)
            c += count(v, 0, v.size() - 1);

        return c;
    }

    int count(std::vector<int>& v, int s, int e) {
        const int t = e;
        int c = 0;
        while (1) {
            if (s == e) {
                if (v[s] < 0)
                    c = t - s + 1;
                break;
            }
            const int m = (s + e) >> 1;
            if (v[m] >= 0)
                s = m + 1;
            else
                e = m;
        }

        return c;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<int>> grid = { { 4,  3,  2,  -1 },
                                           { 3,  2,  1,  -1 },
                                           { 1,  1,  -1, -2 },
                                           { -1, -1, -2, -3 } };
    printf("%d\n", s.countNegatives(grid));

    grid = { { 3, 2 }, { 1 , 0 } };
    printf("%d\n", s.countNegatives(grid));

    grid = { { 1, -1}, { -1, -1 } };
    printf("%d\n", s.countNegatives(grid));

    grid = { { -1 } };
    printf("%d\n", s.countNegatives(grid));

    return 0;
}

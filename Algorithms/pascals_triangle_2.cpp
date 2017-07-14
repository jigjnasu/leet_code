/*
  Solution for Pascal's Triangle II
  Author: cpp.rakesh@gmail.com
  14/07/2017
*/

#include <cstdio>
#include <vector>

class Solution {
public:
    std::vector<int> getRow(int rowIndex) {
        std::vector<int> row(rowIndex + 1, 0);

        row[0] = 1;
        for (int i = 1; i <= rowIndex; ++i)
            for (int j = i; j > 0; --j)
                row[j] += row[j -1];

        return row;
    }
};

int main() {
    int n = 15;
    Solution s;
    const std::vector<int> row = s.getRow(n);
    for (std::size_t i = 0; i < row.size(); ++i)
        printf("%d ", row[i]);
    printf("\n");
    
    return 0;
}

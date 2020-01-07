/*
  Solution for Flipping an image
  Author: cpp.rakesh@gmail.com
  07/01/2020
*/

#include <bits/stdc++.h>

using V = std::vector<std::vector<int>>;

inline void print(const V& A) {
    for (std::vector<int> R : A) {
        for (int e : R)
            printf("%8d ", e);
        printf("\n");
    }
}

inline void swap(int& a, int& b) {
    a ^= b;
    b ^= a;
    a ^= b;
}

class Solution {
public:
    V flipAndInvertImage(V& A) {
        // Swapping done
        for (std::size_t r = 0; r < A.size(); ++r) {
            int i = 0;
            int j = A[r].size() - 1;
            while (i < j)
                swap(A[r][i++], A[r][j--]);
        }

        // Let's flip everything
        for (std::size_t r = 0; r < A.size(); ++r) {
            for (std::size_t c = 0; c < A[r].size(); ++c)
                A[r][c] ^= 0;
        }
        return A;
    }
};


int main() {
    V v = { {1, 1, 0},
            {1, 0, 1},
            {0, 0, 0}};

    Solution s;
    V r = s.flipAndInvertImage(v);
    print(r);

    return 0;
}

/*
  Leetcode.com
  Problem No : 1769
  Problem : Minimum Number of Operations to Move All Balls to Each Box
  Author : cpp.rakesh@gmail.com
  Date: 02/05/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> minOperations(std::string boxes) {
        std::vector<int> out(boxes.size(), 0);
        for (int i = 0; i < static_cast<int>(boxes.size()); ++i) {
            int c = 0;
            for (int j = 0; j < static_cast<int>(boxes.size()); ++j) {
                if (i != j)
                    if (boxes[j] == '1')
                        c += std::abs(j - i);
            }
            out[i] = c;
        }
        return out;
    }
};

inline void print(const std::vector<int>& v) {
    printf("----------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n----------------------------------------------------\n");
}

int main() {
    Solution s;
    print(s.minOperations("110"));
    print(s.minOperations("001011"));

    return 0;
}

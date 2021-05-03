/*
  Leetcode.com
  Problem No : 1769
  Problem : Minimum Number of Operations to Move All Balls to Each Box
  Author : cpp.rakesh@gmail.com
  Date: 02/05/2021
*/

#include <bits/stdc++.h>

inline void print(const std::vector<int>& v) {
    printf("----------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n----------------------------------------------------\n");
}

class Solution {
public:
    std::vector<int> minOperations(std::string boxes) {
        int balls = boxes[0] - '0';
        std::vector<int> left(boxes.size(), 0);
        for (std::size_t i = 1; i < boxes.size(); ++i) {
            left[i] = left[i - 1] + balls;
            balls += boxes[i] - '0';
        }
        balls = boxes[boxes.size() - 1] - '0';
        std::vector<int> right(boxes.size(), 0);
        for (int i = boxes.size() - 2; i >= 0; --i) {
            right[i] += right[i + 1] + balls;
            balls += boxes[i] - '0';
        }
        std::vector<int> res(boxes.size(), 0);
        for (std::size_t i = 0; i < boxes.size(); ++i)
            res[i] = left[i] + right[i];
        return res;
    }
};

int main() {
    Solution s;
    print(s.minOperations("110"));
    print(s.minOperations("001011"));

    return 0;
}

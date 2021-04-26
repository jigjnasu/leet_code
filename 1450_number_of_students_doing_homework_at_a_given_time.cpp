/*
  LeetCode.com
  Problem No: 1450
  Problem: Number of Students Doing Homework at a Given Time
  Rakesh Kumar
  Date: 26/03/2021
*/

#include <cstdio>
#include <vector>

class Solution {
public:
    int busyStudent(std::vector<int>& s, std::vector<int>& e, int q) {
        int c = 0;
        for (std::size_t i = 0; i < s.size(); ++i)
            if (q >= s[i] && q <= e[i])
                ++c;
        return c;
    }
};

int main() {
    Solution s;
    std::vector<int> s1 = {1,2,3};
    std::vector<int> e1 = {3,2,7};
    printf("%d\n", s.busyStudent(s1, e1, 4));

    std::vector<int> s2 = {4};
    std::vector<int> e2 = {4};
    printf("%d\n", s.busyStudent(s2, e2, 4));

    std::vector<int> s3 = {1, 1, 1, 1};
    std::vector<int> e3 = {1, 3, 2, 4};
    printf("%d\n", s.busyStudent(s3, e3, 7));

    std::vector<int> s4 = {9,8,7,6,5,4,3,2,1};
    std::vector<int> e4 = {10,10,10,10,10,10,10,10,10};
    printf("%d\n", s.busyStudent(s4, e4, 5));

    return 0;
}


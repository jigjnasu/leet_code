/*
  LeetCode.com
  Solution for Minimum absolute difference
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 20/04/2020
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<std::vector<int>> minimumAbsDifference(std::vector<int>& arr) {
        std::vector<std::vector<int>> r;
        std::sort(arr.begin(), arr.end());

        int m = arr[arr.size() - 1] - arr[arr.size() - 2];
        for (std::size_t i = 1; i < arr.size(); ++i)
            m = std::min(m , arr[i] - arr[i - 1]);

        for (std::size_t i = 1; i < arr.size(); ++i) {
            if (m == arr[i] - arr[i - 1]) {
                std::vector<int> v;
                v.push_back(arr[i - 1]);
                v.push_back(arr[i]);
                r.push_back(v);
            }
        }

        return r;
    }
};

inline void print(const std::vector<std::vector<int>>& v) {
    printf("--------------------------------------------------------------\n");
    for (std::vector<int> e : v)
        printf("[%d %d] ", e[0], e[1]);
    printf("\n--------------------------------------------------------------\n");
}

int main() {
    Solution s;

    std::vector<int> v = {4, 2, 1, 3};
    print(s.minimumAbsDifference(v));

    v = {3, 8, -10, 23, 19, -4, -14, 27};
    print(s.minimumAbsDifference(v));

    return 0;
}

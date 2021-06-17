/*
  LeetCode.com
  Problem No: 1534
  Problem: Count Good Triplets
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 17/06/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int countGoodTriplets(const std::vector<int>& arr, int a, int b, int c) {
        int res = 0;
        for (std::size_t i = 0; i < arr.size(); ++i) {
            for (std::size_t j = i + 1; j < arr.size(); ++j) {
                if (std::abs(arr[i] - arr[j]) <= a) {
                    for (std::size_t k = j + 1; k < arr.size(); ++k) {
                        if (std::abs(arr[j] - arr[k]) <= b &&
                            std::abs(arr[i] - arr[k]) <= c)
                            ++res;
                    }
                }
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {3,0,1,1,9,7};
    printf("%d\n", s.countGoodTriplets(v, 7,2,3));

    v = {1,1,2,2,3};
    printf("%d\n", s.countGoodTriplets(v, 0,0,1));

    return 0;
}

/*
  LeetCode.com
  Problem No: 1588
  Problem: Sum of All Odd Length Subarrays
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 22/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int sumOddLengthSubarrays(std::vector<int>& arr) {
        int sum = 0;
        std::size_t i = 1;
        while (i <= arr.size()) {
            for (std::size_t j = 0; j < arr.size(); ++j) {
                int s = 0;
                if (j + i > arr.size())
                    break;
                for (std::size_t k = 0; k < i; ++k)
                    s += arr[k + j];
                sum += s;
            }
            i += 2;
        }
        return sum;
    }
};

int main() {
    Solution s;
    std::vector<int> v1 = {1,4,2,5,3};
    printf("%d\n", s.sumOddLengthSubarrays(v1));

    std::vector<int> v2 = {1,2};
    printf("%d\n", s.sumOddLengthSubarrays(v2));

    std::vector<int> v3 = {10,11,12};
    printf("%d\n", s.sumOddLengthSubarrays(v3));

    return 0;
}

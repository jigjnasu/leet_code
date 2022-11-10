/*
  Leetcode.com
  Problem No : 1636
  Problem : Sort Array by Increasing Frequency
  Author : cpp.rakesh@gmail.com
  Date: 10/11/2022
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> frequencySort(std::vector<int>& nums) {
        std::unordered_map<int, int> dict;
        for (int n : nums)
            ++dict[n];
        std::sort(nums.begin(), nums.end(), [&](int a, int b) {
            return dict[a] == dict[b] ? a > b: dict[a] < dict[b];
        });
        return nums;
    }
};

void print_array(const std::vector<int>& v) {
    for (int e : v)
        printf("%d ", e);
    printf("\n");
}

int main() {
    std::vector<int> v = {1,1,2,2,2,3};
    Solution s;
    print_array(v);
    v = s.frequencySort(v);
    print_array(v);

    v = {2,3,1,3,2};
    print_array(v);
    v = s.frequencySort(v);
    print_array(v);

    v = {-1,1,-6,4,5,-6,1,4,1};
    print_array(v);
    v = s.frequencySort(v);
    print_array(v);

    return 0;
}
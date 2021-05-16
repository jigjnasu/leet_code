/*
  Leetcode.com
  Problem No: 1
  Problem: Two Sum
  Author: cpp.rakesh@gmail.com
  Date: Sep 2nd, 2016
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> r(2, 0);
        std::unordered_map<int, int> dict;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            const int d = target - nums[i];
            if (dict.find(d) != dict.end()) {
                r[0] = dict[d];
                r[1] = i;
                break;
            }
            dict[nums[i]] = i;
        }
        return r;
   }
};

int main() {
    int A[] = {2, 7, 11, 15};
    std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

    Solution s;
    const int target = 9;
    const std::vector<int> R = s.twoSum(V, target);
    printf("[%d] + [%d] == [%d]\n", R[0], R[1], target);

    return 0;
}

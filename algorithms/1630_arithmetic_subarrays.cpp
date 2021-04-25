/*
  Leetcode.com
  Problem No : 1630
  Problem : Arithmetic Subarrays
  Author : cpp.rakesh@gmail.com
  Date: 26/04/2021
*/

#include <bits/stdc++.h>

void print(const std::vector<bool>& v) {
    printf("---------------------------------------------\n");
    for (int t : v)
        printf("%d ", t);
    printf("\n---------------------------------------------\n");
}

class Solution {
public:
    std::vector<bool> checkArithmeticSubarrays(std::vector<int>& nums, std::vector<int>& l, std::vector<int>& r) {
        std::vector<bool> res;
        for (std::size_t i = 0; i < l.size(); ++i) {
            std::vector<int> v(nums.begin() + l[i], nums.begin() + r[i] + 1);
            std::sort(v.begin(), v.end());
            bool t = true;
            const int d = v[1] - v[0];
            for (std::size_t j = 2; j < v.size(); ++j) {
                if (v[j] - v[j - 1] != d) {
                    t = false;
                    break;
                }
            }
            res.emplace_back(t);
        }
        return res;
    }
};

int main() {
    Solution s;
    std::vector<int> v1 = {4,6,5,9,3,7};
    std::vector<int> l1 = {0,0,2};
    std::vector<int> r1 = {2,3,5};
    print(s.checkArithmeticSubarrays(v1, l1, r1));
    return 0;
}

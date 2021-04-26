/*
  LeetCode.com
  Problem No: 189
  Problem: Rotate Array
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 30/03/2018
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> v(nums.size(), 0);
        for (size_t i = 0; i < nums.size(); ++i)
            v[(i + k) % nums.size()] = nums[i];

        nums = v;
    }
};


int main() {
    vector<int> v = {1, 2, 3, 4, 5, 6, 7};
    Solution s;
    s.rotate(v, 3);

    return 0;
}

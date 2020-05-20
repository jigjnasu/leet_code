/*
  Leetcode.com
  Problem No: 540
  Problem: Single Number III
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 14/07/2017
*/

#include <cstdio>
#include <vector>

class Solution {
public:
    int singleNonDuplicate(const std::vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;

        while (1) {
            if (start == end) {
                return nums[start];
            } else {
                const int mid = (start + end) >> 1;
                if (mid % 2) {
                    if (nums[mid] == nums[mid - 1])
                        start = mid + 1;
                    else
                        end = mid - 1;
                } else {
                    if (nums[mid] == nums[mid + 1])
                        start = mid + 2;
                    else
                        end = mid - 2;
                }
            }
        }
    }
};

int main() {
    Solution s;
    std::vector<int> n = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    printf("%d\n", s.singleNonDuplicate(n));

    return 0;
}

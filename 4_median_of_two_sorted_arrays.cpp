/*
  Leetcode.com
  Problem No: 4
  Problem: Median of Two Sorted Arrays
  Author: cpp.rakesh@gmail.com
  Date: 17/05/2021
*/

#include <bits/stdc++.h>

inline void print(const std::vector<int>& v) {
    printf("---------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n---------------------------------------------------\n");
}

class Solution {
public:
    /*
      Time complexity O(log2n)
      Space complexity O(1)
     */
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = static_cast<int>(nums1.size()), n = static_cast<int>(nums2.size());
        /*
        if (m > n) {
            std::swap(m,n); std::swap(nums1,nums2);
        }
        */
        int low = 0, high = m, half = (m+n+1) >> 1;
        while (low <= high) {
            int x = (low+high) >> 1;
            int y = half - x;
            if (x && nums1[x-1] > nums2[y])
                high = x - 1;
            else if (x < m && nums2[y-1] > nums1[x])
                low = x + 1;
            else {
                int left = 0;
                if (x == 0)
                    left = nums2[y-1];
                else if (y == 0)
                    left = nums1[x-1];
                else
                    left = std::max(nums1[x-1],nums2[y-1]);
                if ((m+n) & 1)
                    return left;
                int right = 0;
                if (x == m)
                    right = nums2[y];
                else if (y == n)
                    right = nums1[x];
                else
                    right = std::min(nums1[x],nums2[y]);
                return (left+right) * 0.5f;
            }
        }
        return 0.0f;
    }

    /*
      Time complexity O(m+n)
      Space complexity O(m+n)
     */
    double findMedianSortedArrays_on(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::vector<int> nums;
        std::size_t i = 0, j = 0;
        while (i < nums1.size() && j < nums2.size())
            if (nums1[i] < nums2[j])
                nums.emplace_back(nums1[i++]);
            else
                nums.emplace_back(nums2[j++]);
        while (i < nums1.size())
            nums.emplace_back(nums1[i++]);
        while (j < nums2.size())
            nums.emplace_back(nums2[j++]);
        const int mid = (nums.size()) >> 1;
        if (nums.size() & 1)
            return nums[mid];
        else
            return (nums[mid]+nums[mid-1]) * 0.5f;
    }
};

int main() {
    Solution s;
    std::vector<int> v11 = {1, 3};
    std::vector<int> v12 = {2};
    double r1 = s.findMedianSortedArrays(v11, v12);
    double r2 = s.findMedianSortedArrays_on(v11, v12);
    assert(r1 == r2);

    std::vector<int> v21 = {1, 2};
    std::vector<int> v22 = {3, 4};
    r1 = s.findMedianSortedArrays(v21, v22);
    r2 = s.findMedianSortedArrays_on(v21, v22);
    assert(r1 == r2);

    std::vector<int> v31 = {0, 0};
    std::vector<int> v32 = {0, 0};
    r1 = s.findMedianSortedArrays(v31, v32);
    r2 = s.findMedianSortedArrays_on(v31, v32);
    assert(r1 == r2);
    std::vector<int> v41 = {};
    std::vector<int> v42 = {1};
    r1 = s.findMedianSortedArrays(v41, v42);
    r2 = s.findMedianSortedArrays_on(v41, v42);
    assert(r1 == r2);

    std::vector<int> v51 = {2};
    std::vector<int> v52 = {};
    r1 = s.findMedianSortedArrays(v51, v52);
    r2 = s.findMedianSortedArrays_on(v51, v52);
    assert(r1 == r2);

    return 0;
}

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
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int m = static_cast<int>(nums1.size()), n = static_cast<int>(nums2.size());
        if (m > n) {
            std::swap(m, n); std::swap(nums1, nums2);
        }
        int l = 0, r = m;
        while (l <= r) {
            int i = (l + r) >> 1, j = ((m + n + 1) >> 1) - i;
            if (i && nums1[i - 1] > nums2[j]) {
                r = i - 1;
            } else if (i < m && nums2[j - 1] > nums1[i]) {
                l = i + 1;
            } else {
                const int lmax = !i ? nums2[j - 1] : (!j ? nums1[i - 1] : std::max(nums1[i - 1], nums2[j - 1]));
                if ((m + n) & 1)
                    return lmax;
                const int rmin = i == m ? nums2[j] : (j == n ? nums1[i] : std::min(nums1[i], nums2[j]));
                return 0.5 * (lmax + rmin);
            }
        }
        return 0.0f;
    }
};

int main() {
    Solution s;
    std::vector<int> v11 = {1, 3};
    std::vector<int> v12 = {2};
    printf("%f\n", s.findMedianSortedArrays(v11, v12));

    std::vector<int> v21 = {1, 2};
    std::vector<int> v22 = {3, 4};
    printf("%f\n", s.findMedianSortedArrays(v21, v22));

    std::vector<int> v31 = {0, 0};
    std::vector<int> v32 = {0, 0};
    printf("%f\n", s.findMedianSortedArrays(v31, v32));

    std::vector<int> v41 = {};
    std::vector<int> v42 = {1};
    printf("%f\n", s.findMedianSortedArrays(v41, v42));

    std::vector<int> v51 = {2};
    std::vector<int> v52 = {};
    printf("%f\n", s.findMedianSortedArrays(v51, v52));

    return 0;
}

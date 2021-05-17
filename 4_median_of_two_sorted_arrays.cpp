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
        std::vector<int> v(nums1.size() + nums2.size(), 0);
        std::size_t i = 0, j = 0, k = 0;
        while (i < nums1.size() && j < nums2.size()) {
            if (nums1[i] < nums2[j])
                v[k++] = nums1[i++];
            else
                v[k++] = nums2[j++];
        }
        while (i < nums1.size())
            v[k++] = nums1[i++];
        while (j < nums2.size())
            v[k++] = nums2[j++];
        double res = 0.0f;
        const int mid = static_cast<int>(v.size()) >> 1;
        if (v.size() & 1)
            res = v[mid];
        else
            res = (v[mid] + v[mid - 1]) / 2.0f;
        return res;
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

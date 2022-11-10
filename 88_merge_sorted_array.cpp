/*
  Leetcode.com
  Problem No: 88
  Problem: Merge Sorted Array
  Author: cpp.rakesh@gmail.com
  Date: 10/11/2022
*/

#include "utility/common.h"
#include <bits/stdc++.h>

class Solution {
public:
    void merge(std::vector<int>& nums1, int m, std::vector<int>& nums2, int n) {
        int i = m - 1;
        int j = n - 1;
        int k = m + n - 1;
        while (i >= 0 && j >= 0) {
            if (nums1[i] > nums2[j]) {
                nums1[k] = nums1[i];
                --i;
                --k;
            } else {
                nums1[k] = nums2[j];
                --j;
                --k;
            }
        }

        while (i >= 0)
            nums1[k--] = nums1[i--];
        while (j >= 0)
            nums1[k--] = nums2[j--];
    }
};

void print_array(const std::vector<int>& v) {
    for (int e : v)
        printf("%d ", e);
    printf("\n");
}

void test_case_1() {
    std::vector<int> v1(10);
    for (int i = 0; i < 5; ++i)
        v1[i] = random(1, 100);
    std::vector<int> v2;
    for (int i = 0; i < 5; ++i)
        v2.emplace_back(random(1, 100));

    std::sort(v1.begin(), v1.begin() + 5);
    std::sort(v2.begin(), v2.end());
    print_array(v1);
    print_array(v2);

    Solution s;
    s.merge(v1, 5, v2, v2.size());
    print_array(v1);
}

void test_case_2() {
    std::vector<int> v1(15);
    v1[0] = 99;
    std::vector<int> v2;
    for (int i = 0; i < 14; ++i)
        v2.emplace_back(random(1, 100));

    std::sort(v2.begin(), v2.end());
    print_array(v1);
    print_array(v2);

    Solution s;
    s.merge(v1, 1, v2, v2.size());
    print_array(v1);
}

int main() {
    test_case_1();
    test_case_2();

    return 0;
}
/*
  LeetCode.com
  Problem Number: 1299
  Problem: Replace Elements with Greatest Element on Right Side
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 07/07/2021
 */

#include <bits/stdc++.h>

inline void print(const std::vector<int>& v) {
    printf("----------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n----------------------------------------------\n");
}


class Solution {
public:
    std::vector<int> replaceElements(std::vector<int>& arr) {
        int max = arr.back();
        arr[arr.size() - 1] = -1;
        for (int i = arr.size() - 2; i >= 0; --i) {
            const int temp = arr[i];
            arr[i] = max;
            max = std::max(max, temp);
        }
        return arr;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {17,18,5,4,6,1};
    print(s.replaceElements(v));
    
    return 0;
}
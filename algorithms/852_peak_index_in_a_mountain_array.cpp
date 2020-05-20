/*
  LeetCode.com
  Problem No: 852
  Problem Peak index in a mountain array
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 13/08/2019
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        const int n = A.size();
        int i = 1;
        while (i < n && A[i] > A[i - 1])
            ++i;

        return i - 1;
    }
};

int main() {
    Solution s;
    //vector<int> v = {0,1,0};
    vector<int> v = {0,2,1,0};
    printf("%d\n", s.peakIndexInMountainArray(v));

    return 0;
}

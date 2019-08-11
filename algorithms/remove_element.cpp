/*
  LeetCode.com
  Solution for remove element
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 12/08/2019
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n = nums.size();
        int i = 0, j = 0;
        while (j < n) {
            if (nums[j] != val)
                nums[i++] = nums[j];
            ++j;
        }

        return i;
    }
};


int main() {
    //vector<int> v = {3, 2, 2, 3};
    //vector<int> v = {0,1,2,2,3,0,4,2};
    vector<int> v = {2};
    Solution s;
    const int n = s.removeElement(v, 3);
    for (int i = 0; i < n; ++i)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}

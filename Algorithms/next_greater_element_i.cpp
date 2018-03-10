/*
  LeetCode.com
  Solution for Next Greater Element I
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 10/03/2018
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        vector<int> v;

        unordered_map<int, int> dict;
        for (size_t i = 0; i < nums.size(); ++i)
            dict[nums[i]] = i;

        for (size_t i = 0; i < findNums.size(); ++i) {
            for (size_t j = dict[findNums[i]] + 1; j < nums.size(); ++j) {
                if (nums[j] > findNums[i]) {
                    v.push_back(nums[j]);
                    break;
                }
            }

            if (v.size() == i)
                v.push_back(-1);
        }

        return v;
    }
};

int main() {
    Solution s;
    vector<int> a = {1, 3, 5, 2, 4};
    vector<int> b = {6, 5, 4, 3, 2, 1, 7};

    const vector<int> c = s.nextGreaterElement(a, b);
    for (std::size_t i = 0; i < c.size(); ++i)
        printf("%d ", c[i]);
    printf("\n");

    return 0;
}

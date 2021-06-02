/*
  LeetCode.com
  Problem No: 239
  Problem: Sliding Window Maximum
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 02/06/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        std::vector<int> res;
        std::deque<int> dq;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            while (!dq.empty() && dq.front() < i - k + 1)
                dq.pop_front();
            while (!dq.empty() && nums[dq.back()] < nums[i])
                dq.pop_back();
            dq.push_back(i);
            if (i >= k - 1) res.emplace_back(nums[dq.front()]);
        }
        return res;
    }
};

inline void print(const std::vector<int>& v) {
    printf("--------------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n--------------------------------------------------------\n");
}

int main() {
    Solution s;
    std::vector<int> v = {1,3,-1,-3,5,3,6,7};
    print(s.maxSlidingWindow(v, 3));

    v = {1};
    print(s.maxSlidingWindow(v, 1));

    v = {1,-1};
    print(s.maxSlidingWindow(v, 1));

    v = {9, 11};
    print(s.maxSlidingWindow(v, 2));

    v = {4,-2};
    print(s.maxSlidingWindow(v, 2));

    return 0;
}

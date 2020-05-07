/*
  LeetCode.com
  Problem Number: 1365
  Problem: How many numbers are smaller than the current number
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 08/05/2020
 */

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        std::vector<int> r(nums.size(), 0);

        std::vector<int> t = nums;
        std::sort(t.begin(), t.end());
        for (std::size_t i = 0; i < nums.size(); ++i)
            r[i] = m_pos(t, nums[i], 0, nums.size() - 1);

        return r;
    }

private:
    int m_pos(const std::vector<int>& v, int n, int s, int e) {
        if (s == e) {
            int i = s;
            while (i >= 0 && v[i - 1] == v[i])
                --i;
            return i;
        }

        const int m = (s + e) >> 1;
        if (n <= v[m])
            return m_pos(v, n, s, m);
        else
            return m_pos(v, n, m + 1, e);
    }
};

inline void print(const std::vector<int>& v) {
    printf("-----------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n-----------------------------------------------\n");
}

int main() {
    Solution s;

    std::vector<int> v = {8, 1, 2, 2, 3};
    print(s.smallerNumbersThanCurrent(v));

    v = {6, 5, 4, 8};
    print(s.smallerNumbersThanCurrent(v));

    v = {7, 7, 7, 7};
    print(s.smallerNumbersThanCurrent(v));

    return 0;
}

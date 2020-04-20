/*
  LeetCode.com
  Solution for Last stone weight
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 20/04/2020
*/

#include <bits/stdc++.h>

class Solution {
public:
    int lastStoneWeight(std::vector<int>& stones) {
        if (stones.size() == 0)
            return 0;
        else if (stones.size() == 1)
            return stones[0];
        std::sort(stones.begin(), stones.end());
        if (stones[stones.size() - 1] == stones[stones.size() - 2]) {
            stones.erase(stones.begin() + stones.size() - 2, stones.end());
        } else {
            const int t = stones[stones.size() - 1] - stones[stones.size() - 2];
            stones.erase(stones.begin() + stones.size() - 2, stones.end());
            stones.push_back(t);
        }
        return lastStoneWeight(stones);
    }
};

int main() {
    Solution s;
    std::vector<int> v = {2, 7, 4, 1, 8, 1};
    printf("%d\n", s.lastStoneWeight(v));

    return 0;
}

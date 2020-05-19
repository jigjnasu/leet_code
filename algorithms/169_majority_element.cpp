/*
  LeetCode.com
  Problem No: 169
  Problem: Majority Element.
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 26/04/2017
*/

#include <cstdio>
#include <vector>
#include <cstdlib>
#include <map>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        std::map<int, int> dict;
        for (std::size_t i = 0; i < nums.size(); ++i)
            ++dict[nums[i]];

        for (std::map<int, int>::const_iterator it = dict.begin();
             it != dict.end(); ++it)
            if (it->second > nums.size() >> 1)
                return it->first;
    }
};

int main() {
    std::vector<int> nums = {1, 1, 1, 1, 1, 2, 3, 4, 5, 6, 7, 1, 1, 1, 1};
    Solution solution;
    printf("[%d] have majority in this vector\n", solution.majorityElement(nums));

    return 0;
}

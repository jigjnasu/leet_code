/*
  Solution for Single Number from Leet Code
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 18th, Nov 2016
 */

#include <cstdio>
#include <vector>

class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        for (std::size_t i = 0; i < nums.size() - 1; ++i)
            nums[i + 1] ^= nums[i];
        return nums[nums.size() - 1];
    }
};

int main() {
    Solution s;
    int A[] = {1, 3, 2, 1, 2};
    std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

    printf("Single Number == [%d]\n", s.singleNumber(V));
    
    return 0;
}

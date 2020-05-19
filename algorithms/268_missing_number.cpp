/*
  Problem No: 268
  Problem: Missing Number from Leet Code
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 25th, Nov 2016
 */

#include <cstdio>
#include <vector>

class Solution {
public:
    // Simple Mathematical formula to sum and then, reduce the numbers
    int missingNumber(std::vector<int>& nums) {
        int total = (nums.size() * (nums.size() + 1)) / 2;
        for (std::size_t i = 0; i < nums.size(); ++i)
            total -= nums[i];

        return total;
    }

    // Simple xor solution
    int missingNumber1(std::vector<int>& nums) {
        int i = 0;
        int result = 0;

        while (i < nums.size()) {
            result ^= i ^ nums[i];
            ++i;
        }

        return result ^ i;
    }
};

int main() {
    int A[] = {10, 8, 7, 6, 9, 0, 1, 3, 5, 4};
    std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

    Solution s;
    printf("Missing Number == [%d]\n", s.missingNumber(V));
    printf("Missing Number == [%d]\n", s.missingNumber1(V));

    return 0;
}

/*
  Leetcode.com
  Problem No: 238
  Problem: Product Of Array Except Self from Leet Code
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 25th, Nov 2016
 */

#include <cstdio>
#include <vector>

class Solution {
public:

    std::vector<int> productExceptSelf(std::vector<int>& nums) {
        std::vector<int> result;
        result.push_back(1);

        for (std::size_t i = 1; i < nums.size(); ++i)
            result.push_back(result[i - 1] * nums[i - 1]);

        int temp = 1;
        for (int i = nums.size() - 2; i >= 0; --i) {
            temp *= nums[i + 1];
            result[i] *= temp;
        }

        return result;
    }

    void print(const std::vector<int>& V) const {
        for (std::size_t i = 0; i < V.size(); ++i)
            printf("%d ", V[i]);
        printf("\n");
    }
};

int main() {
    int A[] = {1, 2, 3, 4, 5};
    std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

    Solution s;
    s.print(V);
    s.print(s.productExceptSelf(V));

    return 0;
}

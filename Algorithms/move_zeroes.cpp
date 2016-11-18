/*
  LeetCode.com
  Solution for Move Zeroes
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Nov 18th, 2016
 */

#include <cstdio>
#include <vector>

class Solution {
public:
    void moveZeroes(std::vector<int>& nums) {
        int non_zero_index = 0;
        for (std::size_t i = 0; i < nums.size(); ++i)
            if (nums[i] != 0)
                m_swap(nums[non_zero_index++], nums[i]);
    }

    void print(const std::vector<int>& V) const {
        printf("----------------------------------------------\n");
        for (std::size_t i = 0; i < V.size(); ++i)
            printf("%d ", V[i]);
        printf("\n----------------------------------------------\n");        
    }

private:
    void m_swap(int& a, int& b) {
        const int t = a;
        a = b;
        b = t;
    }
};

int main() {
    int A[] = {0, 9, 18, 18, 1, 28, 0, 1, 1, 0};
    std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

    Solution s;
    s.print(V);
    s.moveZeroes(V);
    s.print(V);
    
    return 0;
}

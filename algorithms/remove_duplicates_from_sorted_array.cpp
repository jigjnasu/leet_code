/*
  Solution for Remove Duplicates from Sorted Array.
  Author : cpp.rakesh@gmail.com
  Date: Sep 3rd, 2016
*/

#include <cstdio>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int i = 0;
        for (std::size_t j = 1; j < nums.size(); ++j) {
            if (nums[j] != nums[i]) {
                ++i;				
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
};

int main() {
    int A[] = {2, 2, 1, 1, 1, 183, 12, 21, 12, 12};
    std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

    printf("-----------------------------------------------------------\n");
    for (std::size_t i = 0; i < V.size(); ++i)
        printf("%d ", V[i]);
    printf("\n-----------------------------------------------------------\n");    
    
    Solution s;
    const int size = s.removeDuplicates(V);

    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < size - 1; ++i)
        printf("%d ", V[i]);
    printf("\n-----------------------------------------------------------\n");    
    
    return 0;
}

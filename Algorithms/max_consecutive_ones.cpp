#include <cstdio>
#include <vector>

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int max = 0;
        int i = 0;
        int j = 0;

        while (j < nums.size()) {

            while (j < nums.size() && nums[j]) ++j;
            if (j - i > max)
                max = j - i;
            if (j - i == 0)
                ++j;
            i = j;
        }
        
        return max;
    }
};

int main() {
    Solution s;
    std::vector<int> v = {1,0,1,1,0,1};
    printf("[%d]\n", s.findMaxConsecutiveOnes(v));

    return 0;
}

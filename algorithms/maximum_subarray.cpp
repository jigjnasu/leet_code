/*
  LeetCode.com
  Solution for Maximum Subarray.
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 26/04/2017
*/

#include <cstdio>
#include <vector>
#include <cstdlib>

int random(int min, int max) {
    return min + rand() % (max - min + 1);
}

void print(const std::vector<int>& nums) {
    printf("----------------------------------------------------\n");
    for (std::size_t i = 0; i < nums.size(); ++i)
        printf("%d ", nums[i]);
    printf("\n----------------------------------------------------\n");    
}

// Divide and conquer algorithm to find the maximum subarray.
class Solution {
public:
    int maxSubArray(const std::vector<int>& nums) {
        return m_maxSubArray(0, nums.size() - 1, nums);
    }

private:
    int m_maxSubArray(int start, int end, const std::vector<int>& nums) {
        if (start == end) {
            return nums[start];
        } else {
            const int mid = (start + end) >> 1;
            const int left_sum  = m_maxSubArray(start, mid, nums);
            const int right_sum = m_maxSubArray(mid + 1, end, nums);
            const int cross_sum = m_maxSubArrayCross(start, mid, end, nums);
            
            return m_max(m_max(left_sum, right_sum), cross_sum);
        }
    }

    int m_maxSubArrayCross(int start, int mid, int end, const std::vector<int>& nums) {
        int sum = nums[mid];
        int left_sum = sum;
        for (int i = mid - 1; i >= start; --i) {
            sum += nums[i];
            if (sum > left_sum)
                left_sum = sum;
        }

        sum = nums[mid + 1];
        int right_sum = sum;
        for (int i = mid + 2; i <= end; ++i) {
            sum += nums[i];
            if (sum > right_sum)
                right_sum = sum;
        }

        return left_sum + right_sum;
    }

    int m_max(int a, int b) {
        return a > b ? a : b;
    }
};

int main() {
    int min = -100;
    int max = 100;
    std::vector<int> nums;
    for (int i = 0; i < 100; ++i)
        nums.push_back(random(min, max));

    Solution solution;
    print(nums);
    printf("Maximum sum of subarray == [%d]\n", solution.maxSubArray(nums));
    
    return 0;
}

'''
  LeetCode.com
  Problem Number: 1403
  Problem: Minimum Subsequence in Non-Increasing Order
  Rakesh Kumar @ rakesh.maths@tutanota.com
  Date: 31/03/2021
'''

from typing import List

class Solution:
    def minSubsequence(self, nums: List[int]) -> List[int]:
        s = sum(nums)
        nums.sort(reverse=True)
        t = 0
        for i in range(len(nums)):
            t += nums[i]
            s -= nums[i]
            if t > s:
                return nums[:i + 1]
        return nums

if __name__ == '__main__':
    s = Solution()
    print(s.minSubsequence([4,3,10,9,8]))
    print(s.minSubsequence([4,4,7,6,7]))
    print(s.minSubsequence([6]))

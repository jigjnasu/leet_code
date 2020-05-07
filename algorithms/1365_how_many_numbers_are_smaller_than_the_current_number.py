'''
  LeetCode.com
  Problem Number: 1365
  Problem: How many numbers are smaller than the current number
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 08/05/2020
'''

from typing import List

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        r = [0] * len(nums)
        t = sorted(nums)

        for i in range(len(nums)):
            r[i] = self.pos(t, nums[i], 0, len(nums) - 1)

        return r

    def pos(self, arr, n, s, e):
        if s == e:
            i = s
            while i > 0 and arr[i - 1] == arr[i]:
                i -= 1
            return i
        m = (s + e) >> 1
        if n <= arr[m]:
            return self.pos(arr, n, s, m)
        else:
            return self.pos(arr, n, m + 1, e)

if __name__ == '__main__':
    s = Solution()

    print(s.smallerNumbersThanCurrent([8, 1, 2, 2, 3]))
    print(s.smallerNumbersThanCurrent([6, 5, 4, 8]))
    print(s.smallerNumbersThanCurrent([7, 7, 7, 7]))

'''
  LeetCode.com
  Problem No: 1748
  Problem: Sum of Unique Elements
  Rakesh Kumar
  Date: 29/03/2021
'''

from typing import List

class Solution:
    def sumOfUnique(self, nums: List[int]) -> int:
        d = [0] * 101
        for n in nums:
            d[n] += 1
        s = 0
        for i in range(101):
            if d[i] == 1:
                s += i
        return s

if __name__ == '__main__':
    s = Solution()
    print(s.sumOfUnique([1,2,3,2]))
    print(s.sumOfUnique([1,1,1,1,1]))
    print(s.sumOfUnique([1,2,3,4,5]))

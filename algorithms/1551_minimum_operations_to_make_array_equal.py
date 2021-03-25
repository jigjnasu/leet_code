'''
  LeetCode.com
  Problem No: 1551
  Problem: Minimum Operations to Make Array Equal
  Rakesh Kumar
  Date: 26/03/2021
'''

from typing import List

class Solution:
    def minOperations(self, n: int) -> int:
        if n & 1 == 0:
            n = n >> 1
            return (n * (2 + (n - 1) * 2)) >> 1
        else:
            n = n >> 1
            return (n * (4 + (n - 1) * 2)) >> 1


if __name__ == '__main__':
    s = Solution()
    print(s.minOperations(6))


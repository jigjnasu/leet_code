'''
  LeetCode.com
  Problem Number: 1051
  Problem: Height Checker
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 29/03/2021
'''

from typing import List

class Solution:
    def heightChecker(self, h: List[int]) -> int:
        t = h.copy()
        t.sort()
        c = 0
        for i in range(len(h)):
            if t[i] != h[i]:
                c += 1
        return c


if __name__ == '__main__':
    s = Solution()
    print(s.heightChecker([1,1,4,2,1,3]))
    print(s.heightChecker([5,1,2,3,4]))
    print(s.heightChecker([1,2,3,4,5]))

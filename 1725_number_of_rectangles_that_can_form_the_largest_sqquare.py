'''
  LeetCode.com
  Problem No: 1725
  Problem: Number Of Rectangles That Can Form The Largest Square
  Rakesh Kumar
  Date: 26/03/2021
'''

from typing import List

class Solution:
    def countGoodRectangles(self, rectangles: List[List[int]]) -> int:
        m = 0
        for rec in rectangles:
            m = max(min(rec[0], rec[1]), m)

        c = 0
        for rec in rectangles:
            if min(rec[0], rec[1]) == m:
                c += 1
        return c

if __name__ == '__main__':
    s = Solution()
    print(s.countGoodRectangles([[5,8],[3,9],[5,12],[16,5]]))
    print(s.countGoodRectangles([[2,3],[3,7],[4,3],[3,7]]))


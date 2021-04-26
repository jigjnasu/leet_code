'''
  LeetCode.com
  Problem Number: 682
  Problem: baseball game
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 18/05/2020
'''

from typing import List

class Solution:
    def calPoints(self, ops: List[str]) -> int:
        d = [0] * len(ops)
        i = 0

        for o in ops:
            if o == '+':
                d[i] = d[i - 1] + d[i - 2]
                i += 1
            elif o == 'D':
                d[i] = d[i - 1] << 1
                i += 1
            elif o == 'C':
                d[i - 1] = 0
                i -= 1
            else:
                d[i] = int(o)
                i += 1

        s = 0
        for score in d:
            s += score
        return s


if __name__ == '__main__':
    s = Solution()
    print(s.calPoints(["5", "2", "C", "D", "+"]))
    print(s.calPoints(["5", "-2", "4", "C", "D", "9", "+", "+"]))

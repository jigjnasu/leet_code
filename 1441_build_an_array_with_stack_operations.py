'''
  LeetCode.com
  Problem Number: 1441
  Problem: Build an Array With Stack Operations
  Rakesh Kumar @ rakesh.maths@tutanota.com
  Date: 01/04/2021
'''

from typing import List

class Solution:
    def buildArray(self, target: List[int], n: int) -> List[str]:
        res = []
        for i in range(1, max(target) + 1):
            res.append('Push')
            if i not in target:
                res.append('Pop')
        return res

if __name__ == '__main__':
    s = Solution()
    print(s.buildArray([1, 3], 3))
    print(s.buildArray([1, 2, 3], 3))
    print(s.buildArray([1, 2], 4))

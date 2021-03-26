'''
  LeetCode.com
  Problem No: 804
  Problem: Unique Morse Code Words
  Rakesh Kumar
  Date: 27/03/2021
'''

from typing import List

class Solution:
    def uniqueMorseRepresentations(self, words: List[str]) -> int:
        morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
        res = []
        for w in words:
            s = ''
            for c in w:
                s += morse[ord(c) - ord('a')]
            res.append(s)
        return len(set(res))

if __name__ == '__main__':
    s = Solution()
    print(s.uniqueMorseRepresentations(["gin", "zen", "gig", "msg"]))

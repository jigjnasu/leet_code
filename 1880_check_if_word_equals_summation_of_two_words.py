'''
  LeetCode.com
  Problem Number: 1880
  Problem: Check if Word Equals Summation of Two Words
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 01/08/2021
'''

class Solution:
    def isSumEqual(self, firstWord: str, secondWord: str, targetWord: str) -> bool:
        return self._getNum(firstWord) + self._getNum(secondWord) == self._getNum(targetWord)

    def _getNum(self, word: str):
        s = ''
        for c in word:
            s += str(ord(c) - ord('a'))
        return int(s)

if __name__ == '__main__':
    s = Solution()
    print(s.isSumEqual('acb', 'cba', 'cdb'))
    print(s.isSumEqual('aaa', 'a', 'aab'))
    print(s.isSumEqual('aaa', 'a', 'aaaa'))
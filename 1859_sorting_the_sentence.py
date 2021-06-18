'''
  Problem No: 1859
  Problem : Sorting the Sentence
  Author : cpp.rakesh@gmail.com
  Date : 18/06/2021
'''

class Solution:
    def sortSentence(self, s: str) -> str:
        words = s.split()
        d = [None] * 10
        for w in words:
          d[ord(w[-1]) - ord('1')] = w[:-1]
        res = ''
        for w in d:
          if w != None:
            res += w + " "
        return res[:-1]

if __name__ == '__main__':
    s = Solution()
    print(s.sortSentence("is2 sentence4 This1 a3"))
    print(s.sortSentence("Myself2 Me1 I4 and3"))
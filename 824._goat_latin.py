'''
  LeetCode.com
  Problem No: 824
  Problem: Goat Latin
  Rakesh Kumar
  Date: 19/07/2021
'''

class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        words = sentence.split(' ')
        res = []
        i = 2
        for w in words:
            t = 'a' * i
            if w[0] in 'aeiouAEIOU':
                res.append(w + 'm' + t)
            else:
                res.append(w[1:] + w[0] + 'm' + t)
            i += 1
        return ' '.join(res)

if __name__ == '__main__':
    s = Solution()
    print(s.toGoatLatin("I speak Goat Latin"))
    print(s.toGoatLatin("The quick brown fox jumped over the lazy dog"))
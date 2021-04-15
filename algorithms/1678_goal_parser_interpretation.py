'''
  LeetCode.com
  Problem Number: 1678
  Problem: Goal Parser Interpretation
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 16/04/2021
'''

class Solution:
    def interpret(self, command: str) -> str:
        return command.replace('()', 'o').replace('(al)', 'al')

if __name__ == '__main__':
    s = Solution()
    print(s.interpret('G()(al)'))
    print(s.interpret('G()()()()(al)'))
    print(s.interpret('(al)G(al)()()'))

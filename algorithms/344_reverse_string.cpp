/*
  Leetcode.com
  Problem No: 344
  Problem: Reverse String
  Author: cpp.rakesh@gmail.com
  Date: Nov 18th, 2016
*/

#include <cstdio>
#include <string>

class Solution {
public:
    std::string reverseString(std::string s) {
        int j = s.size() - 1;
        for (int i = 0; i < j; ++i, --j)
            m_swap(s[i], s[j]);
        return s;
    }

private:
    void m_swap(char& a, char& b) {
        char c = a;
        a = b;
        b = c;
    }
};

int main() {
    Solution s;
    std::string str = "Hansraj Model School, Punjabi Bagh New Delhi, 110076";
    printf("Original String == [%s]\n", str.c_str());
    printf("Reverse  String == [%s]\n", s.reverseString(str).c_str());

    return 0;
}

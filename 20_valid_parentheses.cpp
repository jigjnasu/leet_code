/*
  LeetCode.com
  Problem No: 20
  Problem: Valid Parentheses
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 29/03/2018
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> stack;
        for (char c : s) {
            if (c == '(' || c == '[' || c == '{')
                stack.push(c);
            else {
                if (stack.empty())
                    return false;
                const char t = stack.top(); stack.pop();
                if (c == ')' && t != '(')
                    return false;
                if (c == ']' && t != '[')
                    return false;
                if (c == '}' && t != '{')
                    return false;
            }
        }
        return stack.empty();
    }
};

int main() {
    Solution s;
    string str = "()[]{{}";
    printf("%d\n", s.isValid(str));

    return 0;
}

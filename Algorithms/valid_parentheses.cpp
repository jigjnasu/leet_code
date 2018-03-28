/*
  LeetCode.com
  Solution for Valid Parentheses
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 29/03/2018
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        map<char, char> dict;
        dict[')'] = '(';
        dict['}'] = '{';
        dict[']'] = '[';

        stack<char> st;
        for (size_t i = 0; i < s.size(); ++i) {
            if (s[i] == '(' ||
                s[i] == '{' ||
                s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty())
                    return false;

                const char c = st.top();
                st.pop();

                if (c != dict[s[i]])
                    return false;
            }
        }

        return st.empty() == true;
    }
};


int main() {
    Solution s;
    string str = "()[]{{}";
    printf("%d\n", s.isValid(str));

    return 0;
}

/*
  LeetCode.com
  Problem Number: 682
  Problem: baseball game
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 18/05/2020
*/

#include <bits/stdc++.h>

class Solution {
public:
    int calPoints(std::vector<std::string>& ops) {
        std::stack<int> d;
        for (const std::string& s : ops) {
            if (s == "+") {
                const int t = d.top();
                d.pop();
                const int n = d.top() + t;
                d.push(t);
                d.push(n);
            } else if (s == "D") {
                d.push(d.top() * 2);
            } else if (s == "C") {
                d.pop();
            } else {
                d.push(std::atoi(s.c_str()));
            }
        }

        int r = 0;
        while (d.empty() == false) {
            r += d.top();
            d.pop();
        }

        return r;
    }
};

int main() {
    Solution s;
    std::vector<std::string> v = {"5", "2", "C", "D", "+"};
    printf("%d\n", s.calPoints(v));

    v = {"5", "-2", "4", "C", "D", "9", "+", "+"};
    printf("%d\n", s.calPoints(v));

    return 0;
}

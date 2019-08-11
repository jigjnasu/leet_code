/*
  LeetCode.com
  Solution for defant ip addr
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 12/08/2019
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    string defangIPaddr(string address) {
        string ip;
        for (const auto& x : address) {
            if (x == '.')
                ip += "[.]";
            else
                ip += x;
        }

        return ip;
    }
};

int main() {
    Solution s;
    printf("%s\n", s.defangIPaddr("1.1.1.1").c_str());
    printf("%s\n", s.defangIPaddr("255.100.50.0").c_str());

    return 0;
}

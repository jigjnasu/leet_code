/*
  Leetcode.com
  Problem No: 1828
  Problem: Queries on Number of Points Inside a Circle
  Author: cpp.rakesh@gmail.com
  Date: 18/04/2021
*/

#include <bits/stdc++.h>

/*
  solution is very simple
  just find the max element of the string from 1 .... 9 and return the ans

  explaination of 32
  3 2
  ---
  1 1
  1 1
  1 0

  explaination of 82734
  8 2 7 3 4
  ---------
  1 1 1 1 1
  1 1 1 1 1
  1 0 1 1 1
  1 0 1 0 1
  1 0 1 0 0
  1 0 1 0 0
  1 0 1 0 0
  1 0 0 0 0
 */

class Solution {
public:
    int minPartitions(std::string n) {
        return *(std::max_element(n.begin(), n.end())) - '0';
    }
};

int main() {
    Solution s;
    printf("%d\n", s.minPartitions("32"));
    printf("%d\n", s.minPartitions("82734"));
    printf("%d\n", s.minPartitions("27346209830709182346"));

    return 0;
}

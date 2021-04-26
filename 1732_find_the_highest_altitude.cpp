/*
  LeetCode.com
  Problem No: 1732
  Problem: Find the Highest Altitude
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 19/04/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int largestAltitude(std::vector<int>& gain) {
        int highest = 0;
        int altitude = 0;
        for (int h : gain) {
            altitude += h;
            highest = std::max(highest, altitude);
        }
        return highest;
    }
};

int main() {
    Solution s;
    std::vector<int> v1 = {-5,1,5,0,-7};
    printf("%d\n", s.largestAltitude(v1));

    std::vector<int> v2 = {-4,-3,-2,-1,4,3,2};
    printf("%d\n", s.largestAltitude(v2));

    return 0;
}

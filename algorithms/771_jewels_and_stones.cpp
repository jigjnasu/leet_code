/*
  LeetCode.com
  Problem No: 771
  Problem: Jewels and Stones
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 10/03/2018
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        string j_s(26, 0);
        string j_c(26, 0);
        for (size_t i = 0; i < J.size(); ++i)
            if (J[i] >= 'a' && J[i] <= 'z')
                j_s[J[i] - 'a'] = 1;
            else
                j_c[J[i] - 'A'] = 1;

        int count = 0;
        for (size_t i = 0; i < S.size(); ++i)
            if (S[i] >= 'a' && S[i] <= 'z') {
                if (j_s[S[i] - 'a'])
                    ++count;
            } else {
                if (j_c[S[i] - 'A'])
                    ++count;
            }
        return count;
    }
};

int main() {
    Solution s;
    string J = "z";
    string S = "ZZ";
    printf("%d\n", s.numJewelsInStones(J, S));

    return 0;
}

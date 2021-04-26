/*
  LeetCode.com
  Problem No: 977
  Problem: Squares of a sorted array
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 12/08/2019
*/

#include <bits/stdc++.h>

using namespace std;

inline void print(const vector<int>& v) {
    printf("--------------------------------------\n");
    for (const auto & x : v)
        printf("%d ", x);
    printf("\n--------------------------------------\n");
}

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        const int n = A.size();
        int i = 0;
        while (i < n && A[i] < 0)
            ++i;
        int j = i - 1;

        vector<int> result;
        while (j >= 0 && i < n) {
            if (A[j] * A[j] < A[i] * A[i]) {
                result.emplace_back(A[j] * A[j]);
                --j;
            } else {
                result.emplace_back(A[i] * A[i]);
                ++i;
            }
        }

        while (j >= 0) {
            result.emplace_back(A[j] * A[j]);
            --j;
        }

        while (i < n) {
            result.emplace_back(A[i] * A[i]);
            ++i;
        }

        return result;
    }
};

int main() {
    //vector<int> v = {-4,-1,0,3,10};
    vector<int> v = {-7,-3,2,3,11};
    print(v);

    Solution s;
    v = s.sortedSquares(v);
    print(v);
    return 0;
}

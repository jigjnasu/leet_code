/*
  LeetCode.com
  Solution for sort array by parity
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 12/08/2019
*/

#include <bits/stdc++.h>

using namespace std;

void inline print(const vector<int>& v) {
    printf("-------------------------------\n");
    for (const auto& x : v)
        printf("%d ", x);
    printf("\n-------------------------------\n");
}

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        const int n = A.size();
        int i = 0;
        int j = n - 1;
        while (i < j) {
            while (i < n && A[i] % 2 == 0)
                ++i;
            while (j >= 0 && A[j] % 2 == 1)
                --j;
            if (i < j)
                swap(A[i], A[j]);
        }

        return A;
    }

private:
    void swap(int& a, int& b) {
        a ^= b;
        b ^= a;
        a ^= b;
    }
};

int main() {
    vector<int> v = {3, 1, 2, 4};
    print(v);
    Solution s;
    v = s.sortArrayByParity(v);
    print(v);

    return 0;
}

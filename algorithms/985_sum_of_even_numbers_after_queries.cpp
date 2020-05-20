/*
  LeetCode.com
  Problem No: 985
  Problem: Sum of even numbers after queries
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 20/04/2020
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::vector<int> sumEvenAfterQueries(std::vector<int>& A, std::vector<std::vector<int>>& queries) {
        int even = 0;
        for (int e : A)
            if (e % 2 == 0)
                even += e;

        std::vector<int> r;
        for (std::vector<int> v : queries) {
            if (A[v[1]] % 2 == 0)
                even -= A[v[1]];

            A[v[1]] += v[0];
            if (A[v[1]] % 2 == 0)
                even += A[v[1]];
            r.push_back(even);
        }
        return r;
    }
};

inline void print(const std::vector<int>& v) {
    printf("--------------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n--------------------------------------------------------\n");
}

int main() {
    Solution s;
    std::vector<int> A = {1, 2, 3, 4};
    std::vector<std::vector<int>> queries = { {1,0}, {-3,1}, {-4,0}, {2,3} };
    print(s.sumEvenAfterQueries(A, queries));
    return 0;
}

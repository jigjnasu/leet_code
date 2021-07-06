/*
  LeetCode.com
  Problem Number: 1338
  Problem: Reduce Array Size to The Half
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 07/07/2021
 */

#include <bits/stdc++.h>

inline void print(const std::vector<int>& v) {
    printf("----------------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n----------------------------------------------------------\n");
}

class Solution {
public:
    int minSetSize(std::vector<int>& arr) {
        std::unordered_map<int, int> dict;
        for (int v : arr)
            ++dict[v];
        std::vector<int> v;
        for (const auto& it : dict)
            v.emplace_back(it.second);
        std::sort(v.begin(), v.end(), greater());

        int total = 0;
        int res = 0;
        for (std::size_t i = 0; i < v.size(); ++i) {
            total += v[i];
            if (total >= static_cast<int>(arr.size() >> 1)) {
                res = i + 1;
                break;
            } 
        }
        return res;
    }

private:
    struct greater {
        bool operator () (const int& a, const int& b) const {
            return a > b;
        }
    };  
};

int main() {
    Solution s;
    std::vector<int> v = {3,3,3,3,5,5,5,2,2,7};
    printf("%d\n", s.minSetSize(v));

    v = {7, 7, 7, 7, 7, 7, 7, 7, 7};
    printf("%d\n", s.minSetSize(v));

    v = {1, 7};
    printf("%d\n", s.minSetSize(v));

    v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("%d\n", s.minSetSize(v));

    return 0;
}
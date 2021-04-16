/*
  LeetCode.com
  Problem No: 1720
  Problem : Decode Xored array
  Rakesh Kumar
  Date: 16/04/2021
*/

#include <bits/stdc++.h>

void print(const std::vector<int>& v) {
    printf("------------------------------------------------\n");
    for (int e : v)
        printf("%d ", e);
    printf("\n------------------------------------------------\n");
}

class Solution {
public:
    std::vector<int> decode(std::vector<int>& encoded, int first) {
        std::vector<int> r(encoded.size() + 1, 0);
        r[0] = first;
            for (std::size_t i = 0; i < encoded.size(); ++i)
                r[i + 1] = first = first ^ encoded[i];
        return r;
    }
};

int main() {
    Solution s;
    std::vector<int> v1 = {1, 2, 3};
    print(s.decode(v1, 1));

    return 0;
}

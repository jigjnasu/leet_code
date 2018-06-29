/*
  LeetCode.com
  Solution for Self Dividing Numbers
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 10/03/2018
 */

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    Solution() {
        m_initialize();
    }

    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> r;
        for (int i = left; i <= right; ++i)
            if (m_dict[i])
                r.push_back(i);

        return r;
    }

private:
    void m_initialize() {
        m_dict.push_back(0);
        for (int i = 1; i <= 10000; ++i)
            m_dict.push_back(m_is_div(i));
    }

    bool m_is_div(int n) {
        const int m = n;
        while (n) {
            if ((n % 10) == 0 || (m % (n % 10)))
                return false;
            n /= 10;
        }

        return true;
    }

    string m_dict;
};

int main() {
    Solution s;
    const vector<int> v = s.selfDividingNumbers(1, 22);
    for (size_t i = 0; i < v.size(); ++i)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}

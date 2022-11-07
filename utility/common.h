/*
    Header file: some useful common functions
    Author: cpp.rakesh@gmail.com
    Date: 07/11/2022
*/

#ifndef GIT_HUB_LEET_CODE_UTILITY_COMMON_H_
#define GIT_HUB_LEET_CODE_UTILITY_COMMON_H_

#include <bits/stdc++.h>

int random(int s, int e) {
    std::random_device rd;
    std::uniform_int_distribution<> dt(s, e);
    return dt(rd);
}

std::vector<int> get_sorted_array(int n, int start, int end) {
    std::vector<int> v(n, 0);
    for (std::size_t i = 0; i < v.size(); ++i)
        v[i] = random(start, end);
    std::sort(v.begin(), v.end());
    return v;
}

#endif // GIT_HUB_LEET_CODE_UTILITY_COMMON_H_
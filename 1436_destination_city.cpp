/*
  LeetCode.com
  Problem Number: 1436
  Problem: Destination city
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 08/05/2020
 */

#include <bits/stdc++.h>

class Solution {
public:
    std::string destCity(std::vector<std::vector<std::string>>& paths) {
        std::unordered_map<std::string, int> dict;
        for (const std::vector<std::string>& path : paths) {
            dict[path[0]] += 1;
            dict[path[1]] += 2;
        }

        std::string r;
        for (auto it = dict.begin(); it != dict.end(); ++it) {
            if (it->second == 2) {
                r = it->first;
                break;
            }
        }

        return r;
    }
};

int main() {
    Solution s;

    std::vector<std::vector<std::string>> v = { {"London","New York"}, {"New York","Lima"}, {"Lima","Sao Paulo"} };
    printf("%s\n", s.destCity(v).c_str());

    v = { {"B","C"}, {"D","B"}, {"C","A"} };
    printf("%s\n", s.destCity(v).c_str());

    v = { {"A","Z"} };
    printf("%s\n", s.destCity(v).c_str());

    return 0;
}

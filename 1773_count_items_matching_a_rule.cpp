/*
  Leetcode.com
  Problem No : 1773
  Problem : Count Items Matching a Rule
  Author : cpp.rakesh@gmail.com
  Date: 02/05/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int countMatches(std::vector<std::vector<std::string>>& items, std::string ruleKey, std::string ruleValue) {
        int count = 0;
        for (const auto& it : items)
            if (ruleKey == "type" && it[0] == ruleValue ||
               ruleKey == "color" && it[1] == ruleValue ||
               ruleKey == "name" && it[2] == ruleValue)
                ++count;
        return count;
    }
};

int main() {
    Solution s;
    std::vector<std::vector<std::string>> i1 = {{"phone","blue","pixel"},
                                                {"computer","silver","lenovo"},
                                                {"phone","gold","iphone"}};
    printf("%d\n", s.countMatches(i1, "color", "silver"));
    std::vector<std::vector<std::string>> i2 = {{"phone","blue","pixel"},
                                                {"computer","silver","phone"},
                                                {"phone","gold","iphone"}};
    printf("%d\n", s.countMatches(i2, "type", "phone"));

    return 0;
}

/*
  Solution for Relative Ranks
  Author: cpp.rakesh@gmail.com
  14/07/2017
*/

#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <sstream>

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& nums) {
        std::vector<std::string> ranks(nums.size(), "");
        std::map<int, int> hash;
        for (std::size_t i = 0; i < nums.size(); ++i)
            hash[nums[i]] = i;

        int i = 0;
        for (std::map<int, int>::const_iterator it = hash.begin();
             it != hash.end(); ++it, ++i)
            ranks[it->second] = m_convert(nums.size() -  i);
        return ranks;
    }

private:
    std::string m_convert(int n) const {
        std::string r;
        if (n == 1) {
            r = "Gold Medal";
        } else if (n == 2) {
            r = "Silver Medal";
        } else if (n == 3) {
            r = "Bronze Medal";
        } else {
            std::ostringstream oss;
            oss << n;
            r = oss.str();
        }

        return r;
    }
};

int main() {
    std::vector<int> r = {5, 4, 3, 2, 1};
    Solution s;
    const std::vector<std::string> ranks = s.findRelativeRanks(r);
    for (std::size_t i = 0; i < ranks.size(); ++i)
        printf("%s\n", ranks[i].c_str());
    printf("\n");

    return 0;
}

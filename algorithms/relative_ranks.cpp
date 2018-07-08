/*
  Solution for Relative Ranks
  Author: cpp.rakesh@gmail.com
  14/07/2017
*/

#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>
#include <random>

class Solution {
public:
    std::vector<std::string> findRelativeRanks(std::vector<int>& nums) {
        std::vector<int> pos;
        for (std::size_t i = 0; i < nums.size(); ++i)
            pos.push_back(i);

        m_quick_sort(nums, pos, 0, nums.size() - 1);

        const std::size_t size = nums.size();
        std::vector<std::string> ranks(nums.size(), "");

        for (std::size_t i = 0; i < nums.size(); ++i) {
            if (i == 0)
                ranks[pos[i]] = "Gold Medal";
            else if (i == 1)
                ranks[pos[i]] = "Silver Medal";
            else if (i == 2)
                ranks[pos[i]] = "Bronze Medal";
            else
                ranks[pos[i]] = std::to_string(i + 1);
        }

        return ranks;
    }

private:
    void m_quick_sort(std::vector<int>& nums, std::vector<int>& pos, int start, int end) const {
        if (start < end) {
            const int mid = m_partition(nums, pos, start, end);
            m_quick_sort(nums, pos, start, mid - 1);
            m_quick_sort(nums, pos, mid + 1, end);
        }
    }

    int m_partition(std::vector<int>& nums, std::vector<int>& pos, int start, int end) const {
        const int index = m_random(start, end);
        m_swap(nums[index], nums[end]);
        m_swap(pos[index], pos[end]);

        int i = start;
        for (int j = start; j < end; ++j) {
            if (nums[j] >= nums[end]) {
                m_swap(nums[i], nums[j]);
                m_swap(pos[i], pos[j]);
                ++i;
            }
        }

        m_swap(nums[i], nums[end]);
        m_swap(pos[i], pos[end]);

        return i;
    }

    int m_random(int min, int max) const {
        std::random_device rd;
        std::uniform_int_distribution<> dt(min, max);
        return dt(rd);
    }

    void m_swap(int& a, int& b) const {
        const int t = a;
        a = b;
        b = t;
    }
};

int main() {
    std::vector<int> r = {5, 1, 4, 3, 2};
    Solution s;
    const std::vector<std::string> ranks = s.findRelativeRanks(r);
    for (std::size_t i = 0; i < ranks.size(); ++i)
        printf("%s\n", ranks[i].c_str());
    printf("\n");

    return 0;
}

/*
  Solution for Two Sum
  Author: cpp.rakesh@gmail.com
  Date: Sep 2nd, 2016
*/

#include <cstdio>
#include <map>
#include <vector>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> result;
        std::map<int, int> dictionary;
        for (std::size_t i = 0; i < nums.size(); ++i) {
            const int diff = target - nums[i];
            std::map<int, int>::const_iterator it = dictionary.find(diff);
            if (it != dictionary.end()) {
                result.push_back(it->second);
                result.push_back(i);
                return result;
            }
            dictionary.insert(std::pair<int, int>(nums[i], i));
        }
        return result;
    }
};

int main() {
    int A[] = {2, 7, 11, 15};
    std::vector<int> V(A, A + sizeof(A) / sizeof(A[0]));

    Solution s;
    const int target = 9;
    const std::vector<int> R = s.twoSum(V, target);
    printf("[%d] + [%d] == [%d]\n", R[0], R[1], target);
    
    return 0;
}

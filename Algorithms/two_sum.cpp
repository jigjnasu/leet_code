/*
	Solution for Two Sum
	Author: cpp.rakesh@gmail.com
	Date: Sep 2nd, 2016
 */

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

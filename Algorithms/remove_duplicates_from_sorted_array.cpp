/*
  Solution for Remove Duplicates from Sorted Array.
  Author : cpp.rakesh@gmail.com
  Date: Sep 3rd, 2016
 */
class Solution {
public:
	int removeDuplicates(std::vector<int>& nums) {
		if (nums.size() == 0)
			return 0;
		int i = 0;
		for (std::size_t j = 1; j < nums.size(); ++j) {
			if (nums[j] != nums[i]) {
				++i;				
				nums[i] = nums[j];
			}
		}
		return i + 1;
	}
};

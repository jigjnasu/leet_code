#include <cstdio>
#include <string>

class Solution {
public:
    int firstUniqChar(const std::string& s) {
        int dict[26] = {0};
        for (std::size_t i = 0; i < s.size(); ++i)
            ++dict[s[i] - 'a'];

        for (std::size_t i = 0; i < s.size(); ++i)
            if (dict[s[i] - 'a'] == 1)
                return i;
        return -1;
    }
};


int main() {
    Solution solution;
    const std::string a = "leetcode";
    printf("%d\n", solution.firstUniqChar(a));

    const std::string b = "loveleetcode";
    printf("%d\n", solution.firstUniqChar(b));    

    return 0;
}

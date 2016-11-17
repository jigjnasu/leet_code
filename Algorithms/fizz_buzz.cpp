/*
  Solution for Fizz Buzz
  Author: cpp.rakesh@gmail.com
  Date: Nov 18th, 2016
*/

#include <cstdio>
#include <vector>
#include <string>
#include <sstream>

class Solution {
public:
    std::vector<std::string> fizzBuzz(int n) {
        std::vector<std::string> result;
        for (int i = 1; i <= n; ++i) {
            if (i % 3 == 0 && i % 5 == 0)
                result.push_back("FizzBuzz");
            else if (i % 3 == 0)
                result.push_back("Fizz");
            else if (i % 5 == 0)
                result.push_back("Buzz");
            else
                result.push_back(m_to_string(i));
        }
        return result;
    }

private:
    std::string m_to_string(int n) {
        std::stringstream ss;
        ss << n;
        return ss.str();
    }
};

int main() {
    Solution s;
    const std::vector<std::string> result = s.fizzBuzz(15);
    for (std::size_t i = 0; i < result.size(); ++i)
        printf("%s\n", result[i].c_str());
    printf("\n");

    return 0;
}

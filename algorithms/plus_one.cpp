/*
  LeetCode.com
  Solution for Plus One
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: Nov 18th, 2016
 */

#include <cstdio>
#include <vector>
#include <cstdlib>

class Solution {
public:

    std::vector<int> plusOne(std::vector<int>& digits) {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; --i) {
            const int sum = carry + digits[i];
            digits[i] = sum % 10;
            carry = sum / 10;
        }

        while (carry) {
            digits.insert(digits.begin(), carry % 10);
            carry /= 10;
        }

        return digits;
    }

    std::vector<int> get_number() const {
        std::vector<int> number_in_vector;
        int number = m_get_random_number();
        while (number) {
            number_in_vector.insert(number_in_vector.begin(), number % 10);
            number /= 10;
        }

        return number_in_vector;
    }

    void print(const std::vector<int>& V) const {
        for (std::size_t i = 0; i < V.size(); ++i)
            printf("%d", V[i]);
    }

private:
    int m_get_random_number() const {
        const int min = 0;
        const int max = 10000000;
        return min + rand() % (max - min) + 1;
    }
};

int main() {
    Solution s;

    // 100 random test cases
    for (int i = 0; i < 100; ++i) {
        printf("----------------------------------------\n");
        std::vector<int> number = s.get_number();
        s.print(number);
        printf("\n");
        s.plusOne(number);
        s.print(number);
        printf("\n----------------------------------------\n");
    }
    
    return 0;
}

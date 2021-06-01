/*
  LeetCode.com
  Problem No: 211
  Problem: Design Add and Search Words Data Structure
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 01/06/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    std::string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        else
            return convert(num).substr(1);
    }


private:
    std::vector<std::string> a = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
    std::vector<std::string> b = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
    std::string convert(int n) {
        if (n >= 1000000000) return convert(n / 1000000000) + " Billion" + convert(n - 1000000000 * (n / 1000000000));
        else if (n >= 1000000) return convert(n / 1000000) + " Million" + convert(n - 1000000 * (n / 1000000));
        else if (n >= 1000) return convert(n / 1000) + " Thousand" + convert(n - 1000 * (n / 1000));
        else if (n >= 100) return convert(n / 100) + " Hundred" + convert(n - 100 * (n / 100));
        else if (n >= 20) return std::string(" ") + b[n/10] + convert(n - 10 * (n / 10));
        else if (n >= 1) return std::string(" ") + a[n];
        else return std::string("");
    }
};

int main() {
    Solution s;
    printf("%s\n", s.numberToWords(0).c_str());
    printf("%s\n", s.numberToWords(1).c_str());
    printf("%s\n", s.numberToWords(9).c_str());
    printf("%s\n", s.numberToWords(20).c_str());
    printf("%s\n", s.numberToWords(25).c_str());
    printf("%s\n", s.numberToWords(29).c_str());
    printf("%s\n", s.numberToWords(69).c_str());
    printf("%s\n", s.numberToWords(70).c_str());
    printf("%s\n", s.numberToWords(76).c_str());
    printf("%s\n", s.numberToWords(89).c_str());
    printf("%s\n", s.numberToWords(99).c_str());
    printf("%s\n", s.numberToWords(100).c_str());
    printf("%s\n", s.numberToWords(199).c_str());
    printf("%s\n", s.numberToWords(278).c_str());
    printf("%s\n", s.numberToWords(399).c_str());
    printf("%s\n", s.numberToWords(1000).c_str());
    printf("%s\n", s.numberToWords(1050).c_str());
    printf("%s\n", s.numberToWords(1099).c_str());
    printf("%s\n", s.numberToWords(6271).c_str());
    printf("%s\n", s.numberToWords(9999).c_str());
    printf("%s\n", s.numberToWords(1000000).c_str());
    printf("%s\n", s.numberToWords(1234567).c_str());
    printf("%s\n", s.numberToWords(9876543).c_str());
    printf("%s\n", s.numberToWords(1000000000).c_str());
    printf("%s\n", s.numberToWords(1234567891).c_str());

    return 0;
}

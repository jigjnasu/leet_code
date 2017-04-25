/*
  LeetCode.com
  Solution for Reverse Words in a String III 
  Rakesh Kumar @ cpp.rakesh(at)gmail.com
  Date: 25/04/2017
*/

#include <string>

class Solution {
public:
    std::string reverseWords(std::string& s) {
        std::size_t last_pos = 0;
        std::size_t pos = s.find(" ");
        reverse(s, last_pos, pos - 1);

        while (1) {
            last_pos = pos;
            pos = s.find(" ", pos + 1);
            if (pos == std::string::npos)
                break;
            reverse(s, last_pos, pos);
        }
        reverse(s, last_pos + 1, s.size() - 1);
        return s;
    }

private:
    void reverse(std::string& w, std::size_t s, std::size_t e) {
        int i = s;
        int j = e;
        while (i < j)
            swap(w[i++], w[j--]);
    }

    void swap(char& a, char& b) {
        const char t = a;
        a = b;
        b = t;
    }
};

int main() {
    Solution s;
    std::string str = "Let's take LeetCode contest";
    s.reverseWords(str);
    printf("%s\n", str.c_str());
    return 0;
}

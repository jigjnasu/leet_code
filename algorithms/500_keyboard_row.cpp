/*
  Problem No: 500
  Problem: Keyboard Row from Leet Code
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: March 1st, Nov 2017
 */

#include <cstdio>
#include <string>
#include <vector>

const std::vector<std::string> keyboard = {"QWERTYUIOP",
                                           "ASDFGHJKL",
                                           "ZXCVBNM"};

class Solution {
public:
    Solution() {
        for (std::size_t i = 0; i < keyboard.size(); ++i) {
            m_dictionary[i] = 0;
            for (std::size_t j = 0; j < keyboard[i].size(); ++j)
                m_dictionary[i] += 1 << (keyboard[i][j] - 'A');
        }
    }

    std::vector<std::string> findWords(const std::vector<std::string>& words) {
        std::vector<std::string> result;
        for (std::size_t i = 0; i < words.size(); ++i)
            if (m_is_keyboard_row(words[i]))
                result.push_back(words[i]);
        return result;
    }

private:
    std::size_t m_dictionary[3];

    bool m_is_keyboard_row(const std::string& word) {
        for (std::size_t i = 0; i < keyboard.size(); ++i) {
            std::size_t mask = 0;
            for (std::size_t j = 0; j < word.size(); ++j) {
                mask = (1 << std::toupper(word[j]) - 'A') & m_dictionary[i];
                if (mask == 0)
                    break;
            }

            if (mask)
                return true;
        }

        return false;
    }
};

int main() {
    std::vector<std::string> words = {"Alaska", "Hello", "Rakesh", "Peace", "Dada", "QoeiuWieroQEEEW"};
    Solution solution;
    const std::vector<std::string> result = solution.findWords(words);

    for (std::size_t i = 0; i < result.size(); ++i)
        printf("%s\n", result[i].c_str());

    return 0;
}

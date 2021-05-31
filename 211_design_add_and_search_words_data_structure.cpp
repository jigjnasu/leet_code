/*
  LeetCode.com
  Problem No: 211
  Problem: Design Add and Search Words Data Structure
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 01/06/2021
*/

#include <bits/stdc++.h>

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    void addWord(const std::string& word) {
        dict[word.size()].emplace_back(word);
    }

    bool search(const std::string& word) {
        for (const auto& w : dict[word.size()])
            if (equal(word, w))
                return true;
        return false;
    }

private:
    std::unordered_map<int, std::vector<std::string>> dict;

    bool equal(const std::string& a, const std::string& b) {
        for (std::size_t i = 0; i < a.size(); ++i) {
            if (a[i] == '.') continue;
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};

int main() {
    WordDictionary wd;
    wd.addWord("bad");
    wd.addWord("dad");
    wd.addWord("mad");
    printf("%d\n", wd.search("pad"));
    printf("%d\n", wd.search("bad"));
    printf("%d\n", wd.search(".ad"));
    printf("%d\n", wd.search("b.."));
    printf("%d\n", wd.search("b.d"));

    return 0;
}

/*
  LeetCode.com
  Problem No: 127
  Problem: Word Ladder
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 30/05/2021
*/

#include <bits/stdc++.h>

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        std::unordered_map<std::string, bool> visit;
        for (std::size_t i = 0; i < wordList.size(); ++i)
            visit[wordList[i]] = false;
        std::queue<std::string> q;
        q.push(beginWord);
        int depth = 1;
        while (!q.empty()) {
            for (int i = static_cast<int>(q.size()); i > 0; --i) {
                std::string word = q.front(); q.pop();
                if (word == endWord)
                    return depth;
                for (std::size_t j = 0; j < word.size(); ++j) {
                    const char c = word[j];
                    for (int k = 0; k < 26; ++k) {
                        word[j] = k + 'a';
                        if (visit.find(word) != visit.end()) {
                            if (visit[word] == false) {
                                q.push(word);
                                visit[word] = true;
                            }
                        }
                    }
                    word[j] = c;
                }
            }
            ++depth;
        }
        return 0;
    }
};

int main() {
    Solution s;
    std::vector<std::string> list = {"hot","dot","dog","lot","log","cog"};
    printf("depth == [%d]\n", s.ladderLength("hit","cog",list));

    return 0;
}

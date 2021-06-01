/*
  LeetCode.com
  Problem No: 211
  Problem: Design Add and Search Words Data Structure
  Rakesh Kumar @ cpp.rakesh at gmail.com
  Date: 01/06/2021
*/

#include <bits/stdc++.h>

struct Node {
    Node* child[26] = {nullptr};
    int count = 0;
};

class WordDictionary {
public:
    /** Initialize your data structure here. */
    WordDictionary() {

    }

    void addWord(const std::string& word) {
        Node* node = root;
        for (char c : word) {
            if (node->child[c-'a'] == nullptr)
                node->child[c-'a'] = new Node;
            node = node->child[c-'a'];
        }
        ++node->count;
    }

    bool search(const std::string& word) {
        return find(root, word);
    }

private:
    bool find(Node* node, const std::string& word) {
        for (std::size_t i = 0; i < word.size(); ++i) {
            if (word[i] == '.') {
                bool found = false;
                int j = 0;
                for (; j < 26; ++j) {
                    if (node->child[j])
                        found |= find(node->child[j], word.substr(i + 1));
                    if (found) return true;
                }
                if (found == false) return false;
            } else {
                if (node->child[word[i]-'a'] == nullptr)
                    return false;
                node = node->child[word[i]-'a'];
            }
        }
        return node->count > 0;
    }

    Node* root = new Node;
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

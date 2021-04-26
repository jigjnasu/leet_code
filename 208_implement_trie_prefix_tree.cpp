/*
  Leetcode.com
  Problem No : 208
  Problem : Implement Trie (Prefix Tree)
  Author : cpp.rakesh@gmail.com
  Date: 26/04/2021
*/

#include <bits/stdc++.h>

const int ABC = 26;

struct Node {
    Node* children[ABC] = {nullptr};
    int count = 0;
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(std::string word) {
        int index = 0;
        Node* node = root;
        for (char c : word) {
            index = c - 'a';
            if (node->children[index] == nullptr)
                node->children[index] = new Node;
            node = node->children[index];
        }
        ++node->count;
     }

    /** Returns if the word is in the trie. */
    bool search(std::string word) {
        Node* node = root;
        for (char c : word) {
            const int index = c - 'a';
            if (node->children[index] == nullptr)
                return false;
            node = node->children[index];
        }
        return node->count > 0;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(std::string prefix) {
        Node* node = root;
        for (char c : prefix) {
            const int index = c - 'a';
            if (node->children[index] == nullptr)
                return false;
            node = node->children[index];
        }
        if (node->count > 0)
            return true;
        bool res = false;
        for (int i = 0; i < ABC; ++i)
            if (node->children[i] != nullptr)
                res = true;
        return res;
    }

private:
    Node* root = new Node;
};

int main() {
    Trie t;
    t.insert("apple");
    printf("%d\n", t.search("apple"));   // return True
    printf("%d\n", t.search("app"));     // return False
    printf("%d\n", t.startsWith("app")); // return True
    t.insert("app");
    printf("%d\n", t.search("app"));     // return True

    return 0;
}

#include <bits/stdc++.h>

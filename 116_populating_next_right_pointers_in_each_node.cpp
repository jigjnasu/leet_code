/*
  Leetcode.com
  Problem No: 116
  Problem: Populating Next Right Pointers in Each Node
  Author: cpp.rakesh@gmail.com
  Date: 27/05/2021
*/

#include <bits/stdc++.h>

struct Node {
    Node() {}
    Node(int val) : val(val) {}

    int val = 0;
    Node* left = nullptr;
    Node* right = nullptr;
    Node* next = nullptr;
};

class Solution {
public:
    Node* connect(Node* root) {
        if (root) {
            Node* node = root;
            std::queue<Node*> q;
            q.push(node);
            while (!q.empty()) {
                std::vector<Node*> v;
                for (int i = static_cast<int>(q.size()); i > 0; --i) {
                    node = q.front(); q.pop();
                    v.emplace_back(node);
                    if (node->left) q.push(node->left);
                    if (node->right) q.push(node->right);
                }
                for (std::size_t i = 0; i < v.size() - 1; ++i)
                    v[i]->next = v[i+1];
            }
        }
        return root;
    }
};

void traverse(Node* node) {
    printf("-------------------------------------------------\n");
    while (node) {
        Node* p = node;
        while(p) {
            printf("%d ", p->val);
            p = p->next;
        }
        printf("\n");
        node = node->left;
    }
    printf("-------------------------------------------------\n");
}

void bfs(Node* node) {
    printf("-------------------------------------------------\n");
    if (node) {
        std::queue<Node*> q;
        q.push(node);
        while (!q.empty()) {
            for (int i = static_cast<int>(q.size()); i > 0; --i) {
                node = q.front(); q.pop();
                printf("%d ", node->val);
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            printf("\n");
        }
    }
    printf("-------------------------------------------------\n");
}

int main() {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    bfs(root);

    Solution s;
    Node* n1 = s.connect(root);
    traverse(n1);

    return 0;
}

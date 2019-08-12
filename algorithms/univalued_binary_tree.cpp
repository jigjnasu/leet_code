/*
  LeetCode.com
  Solution for Univalued binary tree
  Rakesh Kumar @ cpp.rakesh@gmail.com
  Date: 13/08/2019
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    Solution() : m_root(nullptr) {}

    bool isUnivalTree(TreeNode* root) {
        if (root == nullptr) {
            return false;
        } else {
            const int n = root->val;
            queue<TreeNode*> q;
            q.push(root);

            while (!q.empty()) {
                TreeNode* node = q.front();
                q.pop();

                if (node->val != n)
                    return false;
                if (node->left)
                    q.push(node->left);
                if (node->right)
                    q.push(node->right);
            }
        }

        return true;
    }

    void insert(int x) {
        TreeNode* node = new TreeNode(x);
        if (m_root == nullptr) {
            m_root = node;
        } else if (m_root->left == nullptr) {
            m_root->left = node;
        } else {
            queue<TreeNode*> q;
            q.push(m_root);

            while (1) {
                TreeNode* n = q.front();
                q.pop();

                if (n->left == nullptr) {
                    n->left = node;
                    break;
                } else {
                    q.push(n->left);
                }

                if (n->right == nullptr) {
                    n->right = node;
                    break;
                } else {
                    q.push(n->right);
                }
            }
        }
    }

    void level() const {
        printf("-------------------------------------------------\n");
        map<int, vector<int>> m;
        m_level(m_root, m, 0);
        for (auto it = m.begin(); it != m.end(); ++it) {
            for (const auto& x : it->second)
                printf("%d ", x);
            printf("\n");
        }
        printf("-------------------------------------------------\n");
    }

    TreeNode* root() const {
        return m_root;
    }

private:
    void m_level(TreeNode* node, map<int, vector<int>>& m, int level) const {
        if (node != nullptr) {
            m[level].push_back(node->val);
            m_level(node->left, m, level + 1);
            m_level(node->right, m, level + 1);
        }
    }

    TreeNode* m_root;
};

int main() {
    Solution s;
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(1);
    s.insert(2);
    s.insert(1);
    s.level();

    printf("%d\n", s.isUnivalTree(s.root()));

    return 0;
}
